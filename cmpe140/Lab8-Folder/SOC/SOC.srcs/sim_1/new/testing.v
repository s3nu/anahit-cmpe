`timescale 1ns / 1ps

module SOC_tb();
    // inputs
    reg clk_tb;
    reg rst_tb;
    reg [31:0] gpl1_tb;
    reg [31:0] gpl2_tb;
    //outputs
    wire [31:0] gpo1_tb;
    wire [31:0] gpo2_tb;
    wire [31:0] readdata_tb;
    // calling top level SOC
    SOC_top U1 (.clk(clk_tb),.rst(rst_tb),.gpl1(gpl1_tb),.gpl2(gpl2_tb),.gpo1(gpo1_tb),.gpo2(gpo2_tb),.readdata(readdata_tb));
	// initialize test
	always
    begin
      clk_tb <= 1; #5; clk_tb <= 0; #5;
    end

  initial
	begin
		rst_tb <=0; #5; rst_tb <=1; #5; rst_tb <=0;
	    // testing for 5!
	    gpl1_tb <= 3;
        gpl2_tb <= 0;
        #500 
		$stop;
	end
endmodule
