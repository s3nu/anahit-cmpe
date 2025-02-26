module shifter # (parameter WIDTH = 32) (
        input  wire a,
		input  wire [WIDTH-1:0] b,
		input  wire [4:0] c,
        output reg  [WIDTH-1:0] y
    );

    always @ (a, b, c) begin
        if(a) y = b >> c;
		else  y = b << c;
    end
endmodule