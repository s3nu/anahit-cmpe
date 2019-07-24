`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 09/05/2017 01:20:52 PM
// Design Name: 
// Module Name: Ud_Cnt_4
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


module Ud_Cnt_4(input [3:0] D,
                input LD, UD, CE, CLK, RST,
                output reg [3:0] Q);
always @(posedge CLK, posedge RST)
begin
    if(RST) Q <= 4'd0;
    else if(CE)
        begin
            if(LD) Q <= D;
            else
                begin
                    case(UD)
                        1: Q <= Q + 1;
                        0: Q <= Q - 1;
                    endcase
                end
        end
    else Q <= Q;
end
endmodule
