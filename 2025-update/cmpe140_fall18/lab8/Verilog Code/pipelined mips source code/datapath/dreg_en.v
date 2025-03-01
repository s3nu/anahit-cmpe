module dreg_en # (parameter WIDTH = 32) (
        input  wire             clk,
        input  wire             rst,
		input  wire				en,
        input  wire [WIDTH-1:0] d,
        output reg  [WIDTH-1:0] q
    );

    always @ (posedge clk, posedge rst, en) begin
        if(en)
		begin
			if (rst) q <= 0;
			else     q <= d;
		end
    end
endmodule