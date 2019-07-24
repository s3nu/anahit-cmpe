`timescale 1ns / 1ps

module soc_fpga(
    input clk, reset,
    input [4:0] switches,
    output [7:0] LEDSEL, 
    output [7:0] LEDOUT,
    output dispsel
    );
    
    wire clksec, clk_5KHz;
    wire [31:0]  dataadr, gpo1, gpo2;
    wire [15:0] mux_out;
    wire [31:0] pc;
    
    clk_gen top_clk(
            .clk100MHz(clk),
            .rst(reset),
            .clk_sec(clksec),
            .clk_5KHz(clk_5KHz)
            );
    
    SOC_top(clksec, reset, switches, gpo1, gpo1, gpo2, dataadr, pc);
    
    mux2 #(16) fpga_mux(gpo2[15:0], gpo2[31:16], dispsel, mux_out);
    
    assign dispsel = gpo1[4];
    /////////////////////
    
        wire [7:0] mux_out0;
        wire [7:0] mux_out1;
        wire [7:0] mux_out2;
        wire [7:0] mux_out3, mux_out4, mux_out5, mux_out6, mux_out7;
 
       bcd_to_7seg bcd4 (pc[3:0],mux_out4);
       bcd_to_7seg bcd5 (pc[7:4], mux_out5);
       bcd_to_7seg bcd6 (pc[11:8], mux_out6);
       bcd_to_7seg bcd7 (pc[15:12], mux_out7);
        
        bcd_to_7seg bcd0 (mux_out[3:0],mux_out0);
        bcd_to_7seg bcd1 (mux_out[7:4], mux_out1);
        bcd_to_7seg bcd2 (mux_out[11:8], mux_out2);
        bcd_to_7seg bcd3 (mux_out[15:12], mux_out3);
       
        LED_MUX disp_unit (
            clk_5KHz,
            reset,
            mux_out7,
            mux_out6,
            mux_out5,
            mux_out4,
            mux_out3,
            mux_out2,
            mux_out1,
            mux_out0,
            LEDOUT,
            LEDSEL        
            );  
    
endmodule
