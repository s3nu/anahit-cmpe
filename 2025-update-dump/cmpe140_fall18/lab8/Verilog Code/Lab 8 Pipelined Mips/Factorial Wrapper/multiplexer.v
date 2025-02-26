`timescale 1ns / 1ps

module multiplexer #(parameter DATA_WIDTH = 4)
    (
    input wire [DATA_WIDTH - 1:0] a, b, 
    input wire select,
    output reg [DATA_WIDTH - 1:0] out
    );
    
    always @(*) begin
        case (select)
            0: out = a;
            1: out = b;
        endcase
    end        
endmodule
