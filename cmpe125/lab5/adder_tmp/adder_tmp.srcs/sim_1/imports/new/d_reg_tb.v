`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 03/22/2017 03:54:47 PM
// Design Name: 
// Module Name: d_reg_tb.v
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


module d_reg_tb();
    parameter WIDTH = 8;
    reg clk, reset, en;
    reg [WIDTH-1:0]d_tb;
    wire [WIDTH-1:0]q_tb;
    d_reg DUT (.clk(clk), .reset(reset), .en(en), .d(d_tb), .q(q_tb));
    integer temp_val;
    initial
    begin
        for(temp_val=0; temp_val<256; temp_val=temp_val+1)
        begin
            clk= 0;
            reset=0;
            d_tb=temp_val;
            #5;
            if(q_tb == d_tb)
            begin
                $display("Error when clock =0 and rst=0");
                $stop;
            end
            clk=1;
            en=0;
            #1;
            if(q_tb == d_tb)
            begin
                $display("Error, when clk=1 and enable=0");
                $stop;
            end
            en=1;
            #5;
            clk = 0;
            #5;
            clk = 1;
            #1;
            if(q_tb != d_tb)
            begin
                $display("Error, expected %d, output was %d", d_tb, q_tb);
                $stop;
            end
            reset=1;
            #1;
            if(q_tb != 0)
            begin
                $display("Error, when reset=1 and clock =1");
                $stop;
            end  
        end
    $display("Test Bench Success");
    $stop;
    end   
endmodule
