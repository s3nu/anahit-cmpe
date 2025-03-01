`timescale 1ns / 1ps

module factorial_top
    (
    input wire go, clk, rst, 
    input wire [3:0] in,
    output wire done, error,
    output wire [3:0] cs,
    output wire [31:0] product
    );
    
    wire load_counter, select, load_register, enable_counter, gt, gt12, output_enable;
    
    data_path DP 
        (
         .in(in), 
         .load_counter(load_counter), 
         .select(select), 
         .load_register(load_register), 
         .enable_counter(enable_counter), 
         .clk(clk), 
         .output_enable(output_enable), 
         .product(product), 
         .gt(gt),
         .gt12(gt12)
        );
        
    control_unit CU 
        (
        .go(go), 
        .gt(gt),
        .gt12(gt12), 
        .clk(clk),
        .rst(rst), 
        .select(select), 
        .load_counter(load_counter), 
        .enable(enable_counter), 
        .load_register(load_register), 
        .output_enable(output_enable), 
        .done(done),
        .error(error),
        .cs(cs)
        );
                 
endmodule
