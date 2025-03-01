module stage_dreg # (parameter DATA_WIDTH = 32) (
        input  wire clk, rst, en,
        input  wire [DATA_WIDTH - 1:0] d,
        output reg  [DATA_WIDTH - 1:0] q
    );

    always @ (posedge clk, posedge rst) begin
        if (rst) 
            q <= 0;
        else begin
            case (en)
                1'b0: q <= d;
                1'b1: q <= q;
            endcase
        end    
    end
endmodule
