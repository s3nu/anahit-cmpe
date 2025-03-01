`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 10/08/2017 06:28:31 PM
// Design Name: 
// Module Name: cu_parts
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

module maindec
(input [5:0] opcode, output branch, jump, reg_dst, we_reg, alu_src, we_dm, dm2reg, [1:0] alu_op);
    reg [8:0] ctrl;
    assign {branch, jump, reg_dst, we_reg, alu_src, we_dm, dm2reg, alu_op} = ctrl;
    always @ (opcode)
    begin
        case (opcode)
            6'b00_0000: ctrl = 9'b0_0_1_1_0_0_0_10; // R-type
            6'b00_1000: ctrl = 9'b0_0_0_1_1_0_0_00; // ADDI
            6'b00_0100: ctrl = 9'b1_0_0_0_0_0_0_01; // BEQ
            6'b00_0010: ctrl = 9'b0_1_0_0_0_0_0_00; // J
            6'b10_1011: ctrl = 9'b0_0_0_0_1_1_0_00; // SW
            6'b10_0011: ctrl = 9'b0_0_0_1_1_0_1_00; // LW
            default:    ctrl = 9'bx_x_x_x_x_x_x_xx;
        endcase
    end
endmodule

module auxdec
(input [1:0] alu_op, [5:0] funct, output [2:0] alu_ctrl);
    reg [2:0] ctrl;
    assign {alu_ctrl} = ctrl;
    always @ (alu_op, funct)
    begin
        case (alu_op)
            2'b00: ctrl = 3'b010; // add
            2'b01: ctrl = 3'b110; // sub
            default: case (funct)
                6'b10_0100: ctrl = 3'b000; // AND
                6'b10_0101: ctrl = 3'b001; // OR
                6'b10_0000: ctrl = 3'b010; // ADD
                6'b10_0010: ctrl = 3'b110; // SUB
                6'b10_1010: ctrl = 3'b111; // SLT
                default:    ctrl = 3'bxxx;
            endcase
        endcase
    end
endmodule