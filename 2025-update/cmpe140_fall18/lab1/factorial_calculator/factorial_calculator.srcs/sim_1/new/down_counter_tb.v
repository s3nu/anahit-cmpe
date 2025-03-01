`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 09/10/2018 12:22:30 PM
// Design Name: 
// Module Name: down_counter_tb
// Project Name: 
// Target Devices: 
// Tool Versions: 
// Description: 
// 
// Dependencies: 
// 
// Revision:
// Revision 0.01 - File Created
// Additional Comments:
// 
//////////////////////////////////////////////////////////////////////////////////


module down_counter_tb();

    reg ld, en, clk;
    wire [3:0] in;
    wire [3:0] out;
  
    down_counter DUT (.load_count(ld), .enable(en), .clk(clk), .D(in), .Q(out));
   
    integer i;
    assign in =  15;
   
    initial begin
        clk = 0; #10;
   
        ld = 1;
        clk = 1;
        #10 clk = 0;
        #10 clk = 1;
        #10 clk = 0;
        ld = 0;
        #10 clk = 1;
        #10 clk = 0;
        #10 clk = 1;
        #10 clk = 0;
   
        en = 1;
        for (i = in + 1; i > 0; i = i - 1) begin
            #10 clk = 1;
            #10 clk = 0;
        end
        en = 0;
        #10 clk = 1;
        #10 clk = 0;
        #10 clk = 1;
        #10 clk = 0;
        $finish;
    end   
endmodule
