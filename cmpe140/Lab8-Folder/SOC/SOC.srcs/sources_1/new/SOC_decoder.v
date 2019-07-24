module SOC_decoder(WE,A,WE2,WE1,WEM,RdSel);
// declaring inputs
input wire [31:0] A;
input wire WE;
// declaring outputs
output reg WE1;
output reg WE2;
output reg WEM;
// control for mux
output reg [1:0] RdSel;
//address decoding 
always @ (*) begin
case (A[11:8])
// 0x00 - 0xFC
4'b0000: begin
RdSel = 2'b00;
WE1=1'b0;
WE2=1'b0;
WEM=WE;
end
// 0x80 - 0x0C
4'b1000: begin
RdSel = 2'b10;
WE1=WE;
WE2=1'b0;
WEM=1'b0;
end
// 0x90 - 0x0C
4'b1001: begin
RdSel = 2'b11;
WE1=1'b0;
WE2=WE;
WEM=1'b0;;
end
default: begin
WE1 = 1'bx;
WE2 = 1'bx;
WEM=1'bx;
end
endcase
end
endmodule

// mux for soc
module SOC_mux (DMemData, FactData, GPIOData, RdSel, ReadData);
//declaring inputs
input [1:0] RdSel;
input [31:0] DMemData;
input [31:0] GPIOData;
input [31:0] FactData;
//declaring outputs
output reg [31:0] ReadData;
always @(*) begin
case(RdSel)
2'b00: ReadData = DMemData;
2'b01: ReadData = DMemData;
2'b10: ReadData = FactData;
2'b11: ReadData = GPIOData;
default: ReadData = {31{1'bx}};
endcase
end
endmodule 

//SOC top level
//// SOC Top Level Module
module SOC_top(clk,rst,gpl1,gpl2,gpo1,gpo2,readdata,A_to_PC);
// inputs
input clk;
input rst;
input [31:0] gpl1;
input [31:0] gpl2;
// outputs
output [31:0] gpo1;
output [31:0] gpo2;
output [31:0] readdata;
output [31:0]  A_to_PC;
//wires
wire [31:0] Dmem_to_mux;
wire [31:0] gpio_to_mux;
wire [31:0] fact_to_mux;
//wire [31:0] A_to_PC;
wire [31:0] instruction;
wire [31:0] writedata_to_we;
wire [31:0] address;
wire WE1;
wire WE2;
wire WEM;
wire [1:0] RdSel;
wire [4:0] dispel;
wire [31:0] dispdat;
//mux
SOC_mux U0(.DMemData(Dmem_to_mux), .FactData(fact_to_mux), .GPIOData(gpio_to_mux), .RdSel(RdSel), .ReadData(readdata));
//instruction memory
imem U1(.a(A_to_PC[7:2]),.dOut(instruction));
//mips
mips U2(.clk(clk),.reset(rst),.pc(A_to_PC),.instr(instruction),.memwrite(memwrite_to_we),.aluout(address),.writedata(writedata_to_we),.readdata(readdata),.dispSel(dispel),.dispDat(disdat));
//decoder
SOC_decoder U3(.WE(memwrite_to_we),.A(address),.WE2(WE2),.WE1(WE1),.WEM(WEM),.RdSel(RdSel));
//data memory
dmem U4(.clk(clk),.we(WEM),.addr(address),.dIn(writedata_to_we),.dOut(Dmem_to_mux));
// fact
fact_top U5 (.A(address[3:2]),.WE(WE1),.WD(writedata_to_we[3:0]),.Clk(clk),.Rst(rst),.RD(fact_to_mux));
// gpio
GPIO_top U6 (.A(address[3:2]), .WE(WE2), .gpl1(gpl1),.gpl2(gpl2), .WD(writedata_to_we), .RST(rst), .Clk(clk), .RD(gpio_to_mux), .gpo1(gpo1), .gpo2(gpo2));

endmodule





