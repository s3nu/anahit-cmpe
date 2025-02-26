`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 09/08/2018 06:11:42 PM
// Design Name: 
// Module Name: data_path
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


module data_path
    (
    input wire [3:0] in,
    input wire load_counter, select, load_register, enable_counter, clk, output_enable,
    output wire [31:0] product,
    output wire  gt, gt12
    );
    

    wire [3:0] counter_q;
    wire [31:0] register_q, mux1_out, mux2_out;
    wire [31:0] multiplier_out; 
    
    down_counter COUNT (.load_count(load_counter), .enable(enable_counter), .clk(clk), .D(in), .Q(counter_q));
    
    comparator COMP (.a(counter_q), .b(4'b0001), .greater_than(gt));
    
    comparator COMP1 (.a(in), .b(4'b1101), .greater_than(gt12));
    
    multiplexer #(.DATA_WIDTH(32)) MUX1 (.a(multiplier_out), .b({31'b0,1'b1}), .select(select), .out(mux1_out));
    
    D_register REG (.D(mux1_out), .load(load_register), .clk(clk), .Q(register_q));
    
    simple_multiplier MULT (.a({28'b0, counter_q}), .b(register_q), .product(multiplier_out));
    
    multiplexer #(.DATA_WIDTH(32)) MUX2 (.a(32'b0), .b(register_q), .select(output_enable), .out(mux2_out));
    
    assign product = mux2_out;    
endmodule