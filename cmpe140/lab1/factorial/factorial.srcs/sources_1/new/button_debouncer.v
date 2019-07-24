`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 09/02/2017 06:16:30 PM
// Design Name: 
// Module Name: button_debouncer
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


module button_debouncer #(parameter depth = 16)(input wire clk, button,
                                                output reg debounced_button);
localparam history_max = (2**depth)-1;

reg [depth-1:0] history;

always @(posedge clk)
begin
    history <= {button, history[depth-1:1]};
    debounced_button <= (history == history_max) ? 1'b1 : 1'b0;
end
endmodule
