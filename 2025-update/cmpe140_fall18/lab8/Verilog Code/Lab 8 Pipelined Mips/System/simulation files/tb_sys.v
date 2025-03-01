module tb_sys;
    reg         clk;
    reg         rst;
    reg [31:0] gpI1;
    reg [31:0] gpI2;
    wire [31:0] gpO1;
    wire [31:0] gpO2;
	wire		done_sig;
    wire [31:0] DONT_USE;
	integer n;
    
    system DUT (
            .clk			(clk),
			.rst			(rst),
			.gpI1			(gpI1),
			.gpI2			(gpI2),
			.ra3			(5'h0),
			.gpO1			(gpO1),
			.gpO2			(gpO2),
			.rd3			(DONT_USE),
			.done_sig		(done_sig)
        );
    
    task tick; 
    begin 
        clk = 1'b0; #5;
        clk = 1'b1; #5;
    end
    endtask

    task reset;
    begin 
        rst = 1'b0; #5;
        rst = 1'b1; #5;
        rst = 1'b0;
    end
    endtask
    
    initial begin
        reset;
        gpI1 = 32'b01; #5;
        gpI2 = 32'b10; #5;
        for(n = 1; n <= 50; n = n + 1) tick;
        $finish;
    end

endmodule