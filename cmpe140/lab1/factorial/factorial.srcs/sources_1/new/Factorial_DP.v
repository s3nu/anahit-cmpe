`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 05/19/2017 02:18:08 PM
// Design Name: 
// Module Name: Factorial_DP
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


module Factorial_DP(input [3:0] n, 
                    input [5:0] ctrl,
                    input  clk, rst,
                    output [31:0] out,
                    output Is_GT);


wire [3:0] Cnt_Reg;
wire [31:0] q_out, aluout, q2_out, mux_out1, mux_out2;
wire IS_equal;
Ud_Cnt_4 u1(.D(n), .LD(ctrl[2]), .UD(ctrl[3]), .CE(ctrl[4]), .CLK(clk), .RST(rst), .Q(Cnt_Reg));
comparater u2(.A({28'd0,Cnt_Reg}), .B(32'd1), .greater(Is_GT));
Dreg u3(.D(mux_out1), .en(ctrl[1]), .clk(clk), .rst(rst), .Q(q_out));
Alu u4(.in1(q_out), .in2({28'd0,Cnt_Reg}), .c(2'b00), .aluout(aluout));
Mux u6 (.in1(32'd1), .in2(aluout), .sel(ctrl[5]), .out(mux_out1));
Mux u7 (.in1(32'd0), .in2(aluout), .sel(ctrl[0]), .out(out));
endmodule

