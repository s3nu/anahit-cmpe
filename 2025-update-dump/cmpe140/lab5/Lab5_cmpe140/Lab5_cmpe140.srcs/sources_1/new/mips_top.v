`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 10/08/2017 06:33:47 PM
// Design Name: 
// Module Name: mips_top
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


module mips_top
(input clk, rst, output we_dm, [31:0] pc_current, instr, alu_out, wd_dm, rd_dm);
    wire [31:0] DONT_USE;
    mips mips (clk, rst, 0, instr, rd_dm, we_dm, pc_current, alu_out, wd_dm, DONT_USE);
    imem imem (pc_current[7:2], instr);
    dmem dmem (clk, we_dm, alu_out[7:2], wd_dm, rd_dm);
endmodule