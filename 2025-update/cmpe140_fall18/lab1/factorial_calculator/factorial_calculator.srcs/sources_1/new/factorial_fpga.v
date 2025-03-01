`timescale 1ns / 1ps

module factorial_fpga
    (
    input wire go, clk100MHz, rst,
    input wire [3:0] in,
    output wire [3:0] in_out,
    output [7:0] LEDSEL, LEDOUT,
    output wire done
    );
    
    wire [31:0] out;
    wire [7:0] RES_LED0, RES_LED1, RES_LED2, RES_LED3, RES_LED4, RES_LED5, RES_LED6, RES_LED7;
    wire [3:0] out0, out1, out2, out3, out4, out5, out6, out7;
    
    assign in_out = in;
    
    factorial_top FACT 
        (
        .go(go), 
        .clk(clk100MHz),
        .rst(rst), 
        .in(in), 
        .product(out)
        );
    
    BIN_to_BCD BTB 
        (
        .value(out), 
        .dig0(out0), 
        .dig1(out1), 
        .dig2(out2), 
        .dig3(out3), 
        .dig4(out4), 
        .dig5(out5), 
        .dig6(out6), 
        .dig7(out7)
        );
        
    bcd_to_7seg BCD0 (out0, RES_LED0);
    bcd_to_7seg BCD1 (out1, RES_LED1);
    bcd_to_7seg BCD2 (out2, RES_LED2);
    bcd_to_7seg BCD3 (out3, RES_LED3);
    bcd_to_7seg BCD4 (out4, RES_LED4);
    bcd_to_7seg BCD5 (out5, RES_LED5);
    bcd_to_7seg BCD6 (out6, RES_LED6);
    bcd_to_7seg BCD7 (out7, RES_LED7);
    
    led_mux LED
        (clk100MHz, RES_LED7, RES_LED6, RES_LED5, RES_LED4, RES_LED3, RES_LED2, RES_LED1, RES_LED0, LEDSEL, LEDOUT);
endmodule
