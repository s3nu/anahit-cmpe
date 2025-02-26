`timescale 1ns / 1ps

module simple_multiplier #(parameter DATA_WIDTH = 32)
    (
    input wire [DATA_WIDTH - 1:0] a,b,
    output reg [DATA_WIDTH - 1:0] product
    );
    
    always @(*) begin
        if (a && b)
            product = a * b;
        else if (a && !b)
            product = a * {31'b0, 1'b1};
        else if (b && !a)
            product = b * {31'b0, 1'b1};
        else
            product = {31'b0, 1'b1};
    end
endmodule
