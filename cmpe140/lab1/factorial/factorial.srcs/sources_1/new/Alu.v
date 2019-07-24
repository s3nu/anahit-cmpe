`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 09/05/2017 01:18:49 PM
// Design Name: 
// Module Name: Alu
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


module Alu(input [31:0] in1, in2,
           input [1:0] c,
           output reg [31:0] aluout);
always @ (in1, in2, c)
begin
    case (c)   
        2'b00:  
        begin
            if(in2 == 0) begin aluout = 1; end
            else begin aluout = in1 * in2; end
        end  
        2'b01:  aluout = in1 & in2;   
        2'b10:  aluout = 1;   
        default:  aluout = in2; // 2'b11;
    endcase 
end
endmodule
