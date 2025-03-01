module gpio_top (
		input wire				Clk, Rst, WE,
		input wire  [1:0]		A,
		input wire  [31:0]		gpI1, gpI2, WD,
		output wire [31:0]		RD, gpO1, gpO2
	);
	
	wire			WE1, WE2;
	wire [1:0]		RdSel;
	
	gpio_ad add_decoder (
		.A			(A),
		.WE			(WE),
		.WE1		(WE1),
		.WE2		(WE2),
		.RdSel		(RdSel)
	);
	
	gpio_reg #(32) gpO1_Reg (
		.Clk		(Clk),
		.Rst		(Rst),
		.Load_Reg	(WE1),
		.D			(WD),
		.Q			(gpO1)
	);
	
	gpio_reg #(32) gpO2_Reg (
		.Clk		(Clk),
		.Rst		(Rst),
		.Load_Reg	(WE2),
		.D			(WD),
		.Q			(gpO2)
	);
	
	gpio_output_mux #(32) gpio_out_mux (
		.RdSel		(RdSel),
		.gpI1		(gpI1),
		.gpI2		(gpI2),
		.gpO1		(gpO1),
		.gpO2		(gpO2),
		.RD			(RD)
	);
	
endmodule