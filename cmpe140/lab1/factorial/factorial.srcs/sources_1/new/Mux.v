`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 05/19/2017 02:35:31 PM
// Design Name: 
// Module Name: Mux
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


module Mux(input [31:0] in1, in2,
           input sel,
           output reg [31:0] out);
           
always @(in1, in2, sel, out)
begin
    if(sel)
        begin
            out = in2;
        end
    else
        begin
            out = in1;
        end
end
endmodule
