`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 05/19/2017 03:21:02 PM
// Design Name: 
// Module Name: Dreg
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


module Dreg(input [31:0] D,
            input en, clk, rst,
            output reg [31:0] Q);
always @(posedge clk, posedge rst)
begin
    if(rst)
    begin
        Q <= 32'd0;
    end
    else
    begin 
        if(en) Q <= D;
        else Q <= Q;
    end
end
endmodule
