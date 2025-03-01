`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 03/13/2017 07:20:35 PM
// Design Name: 
// Module Name: infer_add
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

module infer_add(input [3:0] a, input [3:0] b, input cin, output [3:0] sum, output cout);  
   assign {cout, sum} = a + b + cin;
endmodule

