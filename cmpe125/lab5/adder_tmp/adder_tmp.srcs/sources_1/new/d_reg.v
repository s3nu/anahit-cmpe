//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 03/22/2017 03:54:47 PM
// Design Name: 
// Module Name: d_reg.v
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

module d_reg#(parameter WIDTH=8)
    (input clk, reset, en, 
     input [WIDTH-1:0]d, 
     output reg[WIDTH-1:0]q);
     
always@(posedge clk, posedge reset)
    if(reset) q<=0;
    else if(en) q<=d;     
    else q<=q;
    
endmodule