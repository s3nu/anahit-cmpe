module mult # (parameter WIDTH = 32) (
        input  wire [WIDTH-1:0] a,
		input  wire [WIDTH-1:0] b,
        output reg  [63:0] y
    );

    always @ (a, b) begin
        y = a * b;
    end
endmodule