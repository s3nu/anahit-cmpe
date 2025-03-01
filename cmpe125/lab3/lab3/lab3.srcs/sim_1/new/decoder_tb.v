`timescale 1ns / 1ps

module test;
// declaring variables
reg[7:0] tb_in;
wire [2:0] ot_out_if, ot_out_case, ot_out_for;
wire tb_valid_if;
wire tb_valid_case;
wire tb_valid_for;

// passing in inputs based on function table

decoder_if DUTA (.A(tb_in),.Y(ot_out_if), .Valid(tb_valid_if));

decoder_case DUTB (.A(tb_in),.Y(ot_out_case), .Valid(tb_valid_case));

decoder_for DUTC (.A(tb_in),.Y(ot_out_for), .Valid(tb_valid_for));

initial
begin
//tb_in=0;
for(integer i=0; i<256; i=i+1)
    begin
        tb_in = i;
        #5
        begin
            casex(tb_in)
                8'b 1xxxxxx:
                    if (tb_valid_if != 1 || tb_valid_for != 1 || tb_valid_case != 1 || ot_out_if != 3'd7 || ot_out_for != 3'd7 || ot_out_case != 3'd7)
                        $display("error for testbench");
                8'b 01xxxxx:
                    if (tb_valid_if != 1 || tb_valid_for != 1 || tb_valid_case != 1 || ot_out_if != 3'd6 || ot_out_for != 3'd6 || ot_out_case != 3'd6)
                        $display("error for testbench");
                8'b 001xxxx:
                    if (tb_valid_if != 1 || tb_valid_for != 1 || tb_valid_case != 1 || ot_out_if != 3'd5 || ot_out_for != 3'd5 || ot_out_case != 3'd5 )
                        $display("error for testbench");
                8'b 0001xxx:
                    if (tb_valid_if != 1 || tb_valid_for != 1 || tb_valid_case != 1 || ot_out_if != 3'd4 || ot_out_for != 3'd4 || ot_out_case != 3'd4 )
                        $display("error for testbench");
                8'b 00001xx:
                    if (tb_valid_if != 1 || tb_valid_for != 1 || tb_valid_case != 1 || ot_out_if != 3'd3 || ot_out_for != 3'd3 || ot_out_case != 3'd3 )
                        $display("error for testbench");
                8'b 000001x:
                    if (tb_valid_if != 1 || tb_valid_for != 1 || tb_valid_case != 1 || ot_out_if != 3'd2 || ot_out_for != 3'd2 || ot_out_case != 3'd2 )
                        $display("error for testbench");
                8'b 0000001:
                    if (tb_valid_if != 1 || tb_valid_for != 1 || tb_valid_case != 1 || ot_out_if != 3'd1 || ot_out_for != 3'd1 || ot_out_case != 3'd1 )
                        $display("error for testbench");
            endcase
        end
    end
    $display("success");
    $finish;
end
endmodule
