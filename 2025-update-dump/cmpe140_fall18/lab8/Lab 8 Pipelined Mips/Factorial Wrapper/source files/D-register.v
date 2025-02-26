`timescale 1ns / 1ps

module D_register #(parameter DATA_WIDTH = 32)
    (
    input wire [DATA_WIDTH - 1:0] D,
    input wire load, rst, clk,
    output reg [DATA_WIDTH - 1:0] Q
    );
    
    always @(posedge clk, rst) begin
        if (rst)
            Q = 0;   
        else if (load)
            Q = D;
        else
            Q = Q;
    end
endmodule