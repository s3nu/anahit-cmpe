`timescale 1ns / 1ps

module down_counter #(parameter DATA_WIDTH = 4)
    (
    input wire load_count, enable, clk,
    input wire [DATA_WIDTH - 1:0] D,
    output reg [DATA_WIDTH - 1:0] Q
    );

    always @ (posedge clk) begin
        if (load_count)
            Q <= D;
        if(enable)
            Q <= Q - 1;
    end
endmodule