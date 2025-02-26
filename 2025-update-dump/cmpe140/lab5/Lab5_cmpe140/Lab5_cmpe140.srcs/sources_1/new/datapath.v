`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 10/08/2017 06:29:15 PM
// Design Name: 
// Module Name: datapath
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


module datapath
(input clk, rst, pc_src, jump, reg_dst, we_reg, alu_src, dm2reg, [2:0] alu_ctrl, [4:0] ra3, [31:0] instr, rd_dm, output zero, [31:0] pc_current, alu_out, wd_dm, rd3);
    wire [4:0]  rf_wa;
    wire [31:0] pc_plus4, pc_pre, pc_next, sext_imm, ba, bta, jta, alu_pa, alu_pb, wd_rf;
    assign ba = {sext_imm[29:0], 2'b00};
    assign jta = {pc_plus4[31:28], instr[25:0], 2'b00};
    // --- PC Logic --- //
    dreg       pc_reg     (clk, rst, pc_next, pc_current);
    adder      pc_plus_4  (pc_current, 4, pc_plus4);
    adder      pc_plus_br (pc_plus4, ba, bta);
    mux2 #(32) pc_src_mux (pc_src, pc_plus4, bta, pc_pre);
    mux2 #(32) pc_jmp_mux (jump, pc_pre, jta, pc_next);
    // --- RF Logic --- //
    mux2 #(5)  rf_wa_mux  (reg_dst, instr[20:16], instr[15:11], rf_wa);
    regfile    rf         (clk, we_reg, instr[25:21], instr[20:16], ra3, rf_wa, wd_rf, alu_pa, wd_dm, rd3);
    signext    se         (instr[15:0], sext_imm);
    // --- ALU Logic --- //
    mux2 #(32) alu_pb_mux (alu_src, wd_dm, sext_imm, alu_pb);
    alu        alu        (alu_ctrl, alu_pa, alu_pb, zero, alu_out);
    // --- MEM Logic --- //
    mux2 #(32) rf_wd_mux  (dm2reg, alu_out, rd_dm, wd_rf);
endmodule