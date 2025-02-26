module system (
		input wire			clk,
		input wire			rst,
		input wire	[31:0]	gpI1,
		input wire	[31:0]	gpI2,
		input  wire [4:0]	ra3,
		output wire	[31:0]	gpO1,
		output wire	[31:0]	gpO2,
		output wire [31:0]	rd3,
		output wire			done_sig
	);
	
	wire [31:0] Instruction;
	wire [31:0] PC;
	wire [31:0] Address;
	wire [31:0] WriteData;
	wire [31:0] DMemData;
	wire [31:0] FactData;
	wire [31:0] GPIOData;
	wire [31:0] ReadData;
	wire [1:0]	RdSel;
	wire		MemWrite;
	wire		WEM;
	wire		WE1;
	wire		WE2;
	
	sys_add_decoder Address_Decoder (
		.addr			(Address),
		.we				(MemWrite),
		.we1			(WE1),
		.we2			(WE2),
		.wem			(WEM),
		.RdSel			(RdSel)
	);
	
	imem Instruction_Memory (
		.a				(PC[7:2]),
		.y				(Instruction)
	);
	
	mips MIPS_Processor (
		.clk			(clk),
        .rst			(rst),
        .ra3			(ra3),
        .instr			(Instruction),
        .rd_dm			(ReadData),
        .we_dm			(MemWrite),
        .pc_current		(PC),
        .alu_shift_out  (Address),
        .wd_dm			(WriteData),
        .rd3			(rd3)
	);
	
	dmem Data_Memory (
		.clk			(clk),
        .we				(WEM),
        .a				(Address[7:2]),
        .d				(WriteData),
        .q				(DMemData)
	);
	
	factorial_wrapper_top Factorial_Accelerator (
		.wd				(WriteData[3:0]),
		.addr			(Address[3:2]),
		.we				(WE1),
		.rst			(rst),
		.clk			(clk),
		.rd				(FactData),
		.done_sig		(done_sig)
	);
	
	gpio_top General_Purpose_I_O (
		.Clk			(clk),
		.Rst			(rst),
		.WE				(WE2),
		.A				(Address[3:2]),
		.gpI1			(gpI1),
		.gpI2			(gpI2),
		.WD				(WriteData),
		.RD				(GPIOData),
		.gpO1			(gpO1),
		.gpO2			(gpO2)
	);
	
	sys_output_mux Multiplexer (
		.RdSel			(RdSel),
		.DMemData		(DMemData),
		.FactData		(FactData),
		.GPIOData		(GPIOData),
		.ReadData		(ReadData)
	);
endmodule