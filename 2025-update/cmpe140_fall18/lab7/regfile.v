module regfile
(input clk, we, [4:0] ra1, ra2, ra3, wa, [31:0] wd, output [31:0] rd1, rd2, rd3);
    reg [31:0] rf [0:31];
    integer n;
    initial begin
        for (n = 0; n < 32; n = n + 1) rf[n] = 32'h0;
    end
    always @ (posedge clk)
    begin
        if (we) rf[wa] <= wd;
    end
    assign rd1 = (ra1 == 0) ? 0 : rf[ra1];
    assign rd2 = (ra2 == 0) ? 0 : rf[ra2];
    assign rd3 = (ra3 == 0) ? 0 : rf[ra3];
endmodule

module multreg
(input clk, rst, MultWE, [31:0]in, output reg [31:0] out);
    always@ (posedge clk, posedge rst)
    begin
        if(rst) out = 0;
        else begin
            if(MultWE) out = in;
            end
    end
endmodule

module shifter
(input [31:0] in, output reg [31:0] out);
    always@ (in,out)
    begin
        out = in << 2;
    end
endmodule
