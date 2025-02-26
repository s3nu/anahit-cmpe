`timescale 1ns / 1ps

module comparator #(parameter DATA_WIDTH = 4)
    (
    input wire [DATA_WIDTH - 1:0] a, b,
    output reg greater_than, less_than, equal
    );

    initial begin
        greater_than = 0;
        less_than = 0;
        equal = 0;
    end
     
    always @(*) begin
        if (a > b) begin
            greater_than = 1;
            less_than = 0;
            equal = 0;
        end
        else if (a < b) begin
            greater_than = 0;
            less_than = 1;
            equal = 0;
        end
        else if (a == b) begin
            greater_than = 0;
            less_than = 0;
            equal = 1;
        end
    end
endmodule