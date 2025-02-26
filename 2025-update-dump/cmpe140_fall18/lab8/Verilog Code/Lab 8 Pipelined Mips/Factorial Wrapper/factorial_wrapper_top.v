`timescale 1ns / 1ps

module factorial_wrapper_top (
    input wire [3:0] wd,
    input wire [1:0] addr,
    input wire we, rst, clk,
    output wire [31:0] rd,
    output wire done_sig
    );
    
    wire [31:0] nf, result;
    wire [3:0] n_out;
    wire [1:0] RdSel;
    wire go_out, go_pulse, done, err, resdone, reserr, we1, we2;
    wire GoPulseCmb;
    assign GoPulseCmb = {we2 & wd[0]};
    assign done_sig = done;
    
    address_decoder ADDR_DEC (.addr(addr), .we(we), .we1(we1), .we2(we2), .RdSel(RdSel));
    
    D_register #(4) N (.D(wd), .load(we1), .rst(rst), .clk(clk), .Q(n_out));
    D_register #(1) GO (.D(wd[0]), .load(we2), .rst(rst), .clk(clk), .Q(go_out));
    D_register #(1) GP (.D(GoPulseCmb), .load({1'b1}), .rst(rst), .clk(clk), .Q(go_pulse));
    
    factorial_top FACT (.go(go_pulse), .clk(clk), .rst(rst), .in(n_out), .done(done), .error(err), .product(nf));
    
    D_flipflop DONE (.clk(clk), .D({1'b0}), .S(done), .R(GoPulseCmb), .Q(resdone));
    D_flipflop ERROR (.clk(clk), .D({1'b0}), .S(err), .R(GoPulseCmb), .Q(reserr));
    
    D_register #(32) RESULT (.D(nf), .load(done), .rst(rst), .clk(clk), .Q(result));
    
    mux_4 #(32) MUX (.a({28'b0, n_out}), .b({31'b0, go_out}), .c({30'b0, reserr, resdone}), .d(result), .sel(RdSel), .out(rd));
    
endmodule
