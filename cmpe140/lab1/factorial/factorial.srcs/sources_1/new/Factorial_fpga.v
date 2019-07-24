`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 09/02/2017 10:53:38 AM
// Design Name: 
// Module Name: Factorial_fpga
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


module Factorial_fpga(input [3:0] n,
                      input go, clk100MHz, control, rst,
                      output Done,
                      output [7:0] LEDOUT, LEDSEL );
supply1 [7:0] vcc;
wire DONT_USE, clk_5KHz;
wire [31:0] out;
wire [3:0] dig0, dig1, dig2, dig3, dig4, dig5, dig6, dig7;
wire [6:0] out0, out1, out2, out3, out4, out5, out6, out7;
Factorial U0 (.n(n), .Go(go), .clk(debouncedButton), .rst(rst), .Done(Done), .out(out));
bin2bcd32 U1 (.value(out), .dig0(dig0), .dig1(dig1), .dig2(dig2), .dig3(dig3), .dig4(dig4), .dig5(dig5), .dig6(dig6), .dig7(dig7));
showNumber U2 (.dig0(dig0), .dig1(dig1), .dig2(dig2), .dig3(dig3), .dig4(dig4), .dig5(dig5), .dig6(dig6), .dig7(dig7),
                  .out0(out0), .out1(out1), .out2(out2), .out3(out3), .out4(out4), .out5(out5), .out6(out6), .out7(out7));
led_mux U3(clk_5KHz, rst, {1'b1, out7}, {1'b1, out6}, {1'b1, out5}, {1'b1, out4}, {1'b1, out3}, {1'b1, out2}, {1'b1, out1},{1'b1, out0}, LEDOUT, LEDSEL);
clk_gen U4(.clk100MHz(clk100MHz), .rst(rst), .clk_4sec(DONT_USE), .clk_5KHz(clk_5KHz));
button_debouncer U5(.clk(clk_5KHz), .button(control), .debounced_button(debouncedButton));                        
endmodule
