`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 08/29/2017 09:09:58 PM
// Design Name: 
// Module Name: Factorial
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


module Factorial(input [3:0] n,
                 input Go, clk, rst,
                 output Done,
                 output [31:0] out);

wire [5:0] ctrl;
wire Is_Gt;
Factorial_CU U0 (.Go(Go), .clk(clk), .rst(rst), .Is_Gt(Is_Gt), .Done(Done), .ctrl(ctrl));
Factorial_DP U1 ( .n(n), .ctrl(ctrl), .clk(clk), .rst(rst), .out(out), .Is_GT(Is_Gt));
endmodule
