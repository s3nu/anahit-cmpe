module tb_gpio_top;
	reg				Clk;
	reg				Rst;
	wire			WE;
	reg  [1:0]		A;
	wire [31:0]		gpI1;
	wire [31:0]		gpI2;
	wire [31:0]		WD;
	wire [31:0]		gpO1;
	wire [31:0]		gpO2;
	wire [31:0]		RD;
	
	gpio_top DUT (
		.Clk		(Clk),
		.Rst		(Rst),
		.WE			(WE),
		.A			(A),
		.gpI1		(gpI1),
		.gpI2		(gpI2),
		.WD			(WD),
		.gpO1		(gpO1),
		.gpO2		(gpO2),
		.RD			(RD)
	);
	
	assign WE = 1'b1;
	assign gpI1 = {29'b0, 1'b1, 2'b00};
	assign gpI2 = {28'b0, 1'b1, 3'b000};
	assign WD = {27'b0, 1'b1, 4'b0000};
	
	task tick; 
		begin 
			Clk = 1'b0; #5;
			Clk = 1'b1; #5;
		end
    endtask

    task reset;
		begin 
			Rst = 1'b0; #5;
			Rst = 1'b1; #5;
			Rst = 1'b0;
		end
    endtask
	
	initial begin
        reset;
        A = 2'b00;
		tick;
		A = 2'b01;
		tick;
		A = 2'b10;
		tick;
		A = 2'b11;
		tick;
        $finish;
    end
	
endmodule