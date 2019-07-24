`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 05/19/2017 02:46:33 PM
// Design Name: 
// Module Name: comparater
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


module comparater(input [31:0] A, B,
                  output reg greater);
always @(A,B)
begin
    greater <= 0;
    if(A > B)
    begin
        greater <= 1;
    end
end
endmodule
