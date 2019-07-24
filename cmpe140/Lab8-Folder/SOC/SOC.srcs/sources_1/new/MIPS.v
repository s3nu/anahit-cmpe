`timescale 1ns / 1ps

//******************************** Main Decoder ********************************//
module maindec(
	input	[5:0] op, funct,
	output	memtoreg, memwrite, branch, alusrc, regdst, regwrite, jump, LoHi, MulLd, 
	        MultoReg, JR, PCLink, 
	output	[1:0] aluop );

	reg 	[13:0]	controls;

	assign {regwrite, regdst, alusrc, branch, memwrite, memtoreg, jump, LoHi, MulLd, MultoReg, JR, PCLink, aluop} = controls;

	always @(*)
		case(op)
			// R-Type
			6'b000000: 
			     case(funct)
                     6'b011001: controls <= 14'b00000000100010; //multu = 25 (0x19) 0x000x0x100010
			         6'b010010: controls <= 14'b11000000010010; //mflo = 18 (0x12) 	11x00x00010010
					 6'b010000: controls <= 14'b11000001010010; //mfhi = 16 (0x10)	11x00x01010010
			         6'b001000: controls <= 14'b00000000001010; //jr = 8 (0x08)		0x000x0x001010
			         default:   controls <= 14'b11000000000010; //other R-Type instructions	11000000000010
                 endcase
			// I-Type    
			6'b100011: controls <= 14'b10100100000000; //LW = 35 (0x23)	1010010x000000
			6'b101011: controls <= 14'b00101000000000; //SW = 43 (0x2b)	0x101x0x000000	
			6'b000100: controls <= 14'b00010000000001; //BEQ = 4 (0x04)	0x010x0x000001	
			6'b001000: controls <= 14'b10100000000000; //ADDI = 8 (0x08) 1010000x000000
			// J-Type
			6'b000010: controls <= 14'b00000010000000; //J = 2 (0x02)	0xxx0x1x0000xx
			6'b000011: controls <= 14'b10000010000100; //JAL = 3 (0x03)	1xxx0x1x0001xx
			default:   controls <= 14'bxxxxxxxxxxxxxx; //Default case for general instructions
		endcase
endmodule

//******************************** ALU Decoder ********************************//
module aludec(
	input		[5:0]	funct,
	input		[1:0]	aluop,
	output reg	[2:0]	alucontrol );

	always @(*)
		case(aluop)
			2'b00: alucontrol <= 3'b010;  // add
			2'b01: alucontrol <= 3'b110;  // sub
			default: case(funct)          // R-TYPE
				6'b100000: alucontrol <= 3'b010; // ADD = 32 (0x20)
				6'b100010: alucontrol <= 3'b110; // SUB = 34 (0x22)
				6'b100100: alucontrol <= 3'b000; // AND = 36 (0x24)
				6'b100101: alucontrol <= 3'b001; // OR = 37 (0x25)
				6'b101010: alucontrol <= 3'b111; // SLT = 42 (0x2a)
				default:   alucontrol <= 3'bxxx; // Default case
			endcase
		endcase
endmodule

//*********************************** ALU ***********************************//
module alu(input [31:0]	a, b, 
	       input [ 2:0]	alucont, 
	       output reg [31:0] result,
	       output			zero );

	wire	[31:0]	b2, sum, slt;

	assign b2 = alucont[2] ? ~b:b; 
	assign sum = a + b2 + alucont[2];
	assign slt = sum[31];

	always@(*)
		case(alucont[1:0])
			2'b00: result <= a & b;
			2'b01: result <= a | b;
			2'b10: result <= sum;
			2'b11: result <= slt;
		endcase

	assign zero = (result == 32'b0);	// if(result=0) then zero = 1
endmodule

//********************************** Adder **********************************//
module adder(input [31:0] a, b,
	         output [31:0]	y );
    assign y = a + b;
endmodule

//*************************Two-bit left shifter *****************************//
module sl2(input [31:0]	a,
	       output [31:0] y);
	// shift left by 2
	assign y = {a[29:0], 2'b00};
endmodule

//************************* Signed Extension Unit ***************************//
module signext(
	input	[15:0]	a,
	output	[31:0]	y );

	assign y = {{16{a[15]}}, a};
endmodule

////********************** D-FF without enable signal *************************//
module flopr #(parameter WIDTH = 8) (
	input					clk, reset,
	input		[WIDTH-1:0]	d, 
	output reg	[WIDTH-1:0]	q);

	always @(posedge clk, posedge reset)
		if (reset) q <= 0;
		else       q <= d;
endmodule

//*********************** D-FF with enable signal ***************************//
module flopenr #(parameter WIDTH = 32) (
	input					clk, reset,
	input					en,
	input		[WIDTH-1:0]	d, 
	output reg	[WIDTH-1:0]	q);

	always @(posedge clk)
		if      (reset) q <= 0;
		else if (en)    q <= d;
endmodule

//**************************** 2-to-1 MUX ************************************//
module mux2 #(parameter WIDTH = 32) (
	input	[WIDTH-1:0]	d0, d1, 
	input				s, 
	output	[WIDTH-1:0]	y );
    
    assign y = s ? d1 : d0; 
endmodule

//**************************** Multiplier ************************************//
module mult(input [31:0] a, b,
            output [31:0] hi, lo);

    assign {hi, lo} = a * b;
endmodule

//*************************** Register File **********************************//
// register file with one write port and three read ports
// the 3rd read port is for prototyping dianosis
module regfile(	
	input			clk, 
	input			we3, 
	input 	[ 4:0]	ra1, ra2, wa3, 
	input	[31:0] 	wd3, 
	output 	[31:0] 	rd1, rd2,
	input	[ 4:0] 	ra4,
	output 	[31:0] 	rd4);

	reg		[31:0]	rf[31:0];
	integer			n;
	
	
	//initialize registers to all 0s
	initial 
		for (n=0; n<32; n=n+1) 
			rf[n] = 32'h00;
		
	//write first order, include logic to handle special case of $0
    always @(posedge clk)
         if (we3)
            begin
			/*if (~wa3[4])
				rf[{0,wa3[3:0]}] <= wd3;
			else
				rf[{1,wa3[3:0]}] <= wd3;
			end   */
            
            if (wa3!=0)
                rf[wa3] <= wd3;
            else
                rf[wa3] <= 32'h00000000;   
            end
         
            
	assign rd1 = (ra1 != 0) ? rf[ra1[4:0]] : 0;
	assign rd2 = (ra2 != 0) ? rf[ra2[4:0]] : 0;
	assign rd4 = (ra4 != 0) ? rf[ra4[4:0]] : 0;	// Input the read address to read the content of RF
endmodule

//******************************** Control Unit ********************************//
module controller(
	input [5:0]	op, funct,
	input zero,
	output memtoreg, memwrite, pcsrc, alusrc, regdst, regwrite, jump, LoHi, MulLd, 
	       MultoReg, JR, PCLink,
	output [2:0] alucontrol );

	wire	[1:0]	aluop;
	wire			branch;

	maindec	md(op, funct, memtoreg, memwrite, branch, alusrc, regdst, regwrite, jump, LoHi, MulLd, 
	           MultoReg, JR, PCLink, aluop);
	aludec	ad(funct, aluop, alucontrol);

	assign pcsrc = branch & zero;
endmodule

//********************************* Data Path **********************************//
module datapath(
	input	clk, reset, regwrite, regdst, alusrc, pcsrc, memtoreg, jump, LoHi, MulLd, 
	        MultoReg, JR, PCLink,
	input	[2:0]	alucontrol,
	output			zero,
	output	[31:0]	pc,
	input	[31:0]	instr,
	output	[31:0]	aluout, writedata,
	input	[31:0]	readdata,
	input	[4:0]	dispSel,
	output	[31:0]	dispDat );

	wire [4:0]  writereg, regadd;
	wire [31:0] pcnext, pcnextbr, pcnextjr, pcplus4, pcbranch, signimm, signimmsh, srca, srcb, 
	            mulreslo, loout, mulreshi, hiout, aluresult, mulresult, writedata3, result;

	// next PC logic
	flopr #(32) pcreg(clk, reset, pcnext, pc); 
	adder       pcadd1(pc, 32'b100, pcplus4); 
	sl2         immsh(signimm, signimmsh); 
	adder       pcadd2(pcplus4, signimmsh, pcbranch); 
	mux2 #(32)  pcjrmux(pcplus4, srca, JR, pcnextjr);
    mux2 #(32)  pcbrmux(pcnextjr, pcbranch, pcsrc, pcnextbr);
    mux2 #(32)  pcmux(pcnextbr, {pcplus4[31:28], instr[25:0], 2'b00}, jump, pcnext);

	// register file logic
	regfile		rf(clk, regwrite, instr[25:21], instr[20:16], writereg, writedata3, srca, writedata, dispSel, dispDat);
	mult        multu(srca, writedata, mulreshi, mulreslo);
	flopenr #(32) lo(clk, reset, MulLd, mulreslo, loout);
	flopenr #(32) hi(clk, reset, MulLd, mulreshi, hiout);
	mux2 #(5)	wrmux(instr[20:16], instr[15:11], regdst, regadd);
	mux2 #(5)	jaladd(regadd, 5'b11111, PCLink, writereg);
    mux2 #(32)	lohimux(loout, hiout, LoHi, mulresult);
    // end
	mux2 #(32)	resmux(aluout, readdata, memtoreg, aluresult);
	mux2 #(32)	readormulmux(aluresult, pcplus4, PCLink, result);
    mux2 #(32)  pcjalmux(result, mulresult, MultoReg, writedata3);
	signext		se(instr[15:0], signimm);

	// ALU logic
	mux2 #(32)	srcbmux(writedata, signimm, alusrc, srcb);
	alu			alu(srca, srcb, alucontrol, aluout, zero);
endmodule

//********************************* MIPS ***************************************//
// The MIPS (excluding the instruction and data memories)
module mips(
	input        	clk, reset,
	output	[31:0]	pc,
	input 	[31:0]	instr,
	output			memwrite,
	output	[31:0]	aluout, writedata,
	input 	[31:0]	readdata,
	input	[ 4:0]	dispSel,
	output	[31:0]	dispDat );

	// deleted wire "branch" - not used
	wire 			memtoreg, pcsrc, zero, alusrc, regdst, regwrite, jump;
	wire	[2:0] 	alucontrol;

	controller c(instr[31:26], instr[5:0], zero,
				memtoreg, memwrite, pcsrc,
				alusrc, regdst, regwrite, jump, LoHi, MulLd, 
                MultoReg, JR, PCLink,
				alucontrol);
	datapath dp(clk, reset, regwrite, regdst, alusrc, pcsrc, memtoreg, jump, LoHi, MulLd, 
                MultoReg, JR, PCLink,
				alucontrol, zero, pc, instr, aluout, 
				writedata, readdata, dispSel, dispDat);
endmodule

//*************************** Instruction Memory *********************************//
module imem (
	input	[ 5:0]	a,
	output 	[31:0]	dOut );
	
	reg		[31:0]	rom[0:63];
	
	//initialize rom from memfile.dat
	initial 
		$readmemh("memfile.dat", rom);
	
	//simple rom
    assign dOut = rom[a];
endmodule

//****************************** Data Memory ************************************//
module dmem (
	input			clk,
	input			we,
	input	[31:0]	addr,
	input	[31:0]	dIn,
	output 	[31:0]	dOut );
	
	reg		[31:0]	ram[63:0];
	integer			n;
	
	//initialize ram to all FFs
	initial 
		for (n=0; n<64; n=n+1)
			ram[n] = 8'hFF;
		
	assign dOut = ram[addr[31:2]];
				
	always @(posedge clk)
		if (we) 
			ram[addr[31:2]] = dIn; 
endmodule


