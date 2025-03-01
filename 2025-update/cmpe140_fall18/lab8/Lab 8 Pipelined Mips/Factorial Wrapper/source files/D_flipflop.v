`timescale 1ns / 1ps

module D_flipflop (
    input wire D,
    input wire S, R, clk,
    output reg Q
    );
    
    always@ (*) begin
        case ({S,R})
            2'b00: Q = D;
            2'b01: Q = 0;
            2'b10: Q = 1;
            2'b11: Q = 1;
        endcase
   end        
endmodule
