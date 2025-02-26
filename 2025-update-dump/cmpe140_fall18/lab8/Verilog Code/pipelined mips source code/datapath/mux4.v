module mux4 #(parameter DATA_WIDTH = 32)(
    input wire [1:0] sel,
    input wire [DATA_WIDTH - 1:0] a, b, c, d,
    output reg [DATA_WIDTH - 1:0] out
    );
    
    always @(*) begin
        case (sel)
            2'b00: out = a;
            2'b01: out = b;
            2'b10: out = c;
            2'b11: out = d;
            default: out = 32'b0;
        endcase
    end
endmodule
