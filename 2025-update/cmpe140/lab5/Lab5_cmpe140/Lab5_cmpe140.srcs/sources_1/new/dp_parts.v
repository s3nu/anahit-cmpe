`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 10/08/2017 06:29:59 PM
// Design Name: 
// Module Name: dp_parts
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


module mux2 #(parameter wide = 8)
(input sel, [wide-1:0] a, b, output [wide-1:0] y);
    assign y = (sel) ? b : a;
endmodule

module adder
(input [31:0] a, b, output [31:0] y);
    assign y = a + b;
endmodule

module signext
(input [15:0] a, output [31:0] y);
    assign y = {{16{a[15]}}, a};
endmodule

module alu
(input [2:0] op, [31:0] a, b, output zero, reg [31:0] y);
    assign zero = (y == 0);
    always @ (op, a, b)
    begin
        case (op)
            3'b000: y = a & b;
            3'b001: y = a | b;
            3'b010: y = a + b;
            3'b110: y = a - b;
            3'b111: y = (a < b) ? 1 : 0;
        endcase
    end
endmodule

module dreg
(input clk, rst, [31:0] d, output reg [31:0] q);
    always @ (posedge clk, posedge rst)
    begin
        if (rst) q <= 0;
        else     q <= d;
    end
endmodule

module regfile
(input clk, we, [4:0] ra1, ra2, ra3, wa, [31:0] wd, output [31:0] rd1, rd2, rd3);
    reg [31:0] rf [0:31];
    integer n;
    initial begin
        for (n = 0; n < 32; n = n + 1) rf[n] = 32'h0;
    end
    always @ (posedge clk)
    begin
        if (we) rf[wa] <= wd;
    end
    assign rd1 = (ra1 == 0) ? 0 : rf[ra1];
    assign rd2 = (ra2 == 0) ? 0 : rf[ra2];
    assign rd3 = (ra3 == 0) ? 0 : rf[ra3];
endmodule
