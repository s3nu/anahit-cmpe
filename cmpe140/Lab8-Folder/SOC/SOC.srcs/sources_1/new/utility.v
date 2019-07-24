`timescale 1ns / 1ps

module clk_gen(input clk100MHz, input rst, output reg clk_sec, output reg clk_5KHz);

integer count, count1;

always@(posedge clk100MHz)
    begin
        if(rst)
        begin
            count = 0;
            count1 = 0;
            clk_sec = 0;
            clk_5KHz =0;
        end
        else
        begin
            if(count == 50000000) /* 50e6 x 10ns = 1/2sec, toggle twice for 1sec */
            begin
            clk_sec = ~clk_sec;
            count = 0;
            end
            if(count1 == 10000)
            begin
            clk_5KHz = ~clk_5KHz;
            count1 = 0;
            end
            count = count + 1;
            count1 = count1 + 1;
        end
    end
endmodule // end clk_gen


/* 7-segment values */
`define D0 8'b10001000 /* 0 */
`define D1 8'b11101101 /* 1 */
`define D2 8'b10100010 /* 2 */
`define D3 8'b10100100 /* 3 */
`define D4 8'b11000101 /* 4 */
`define D5 8'b10010100 /* 5 */
`define D6 8'b10010000 /* 6 */
`define D7 8'b10101101 /* 7 */
`define D8 8'b10000000 /* 8 */
`define D9 8'b10000100 /* 9 */
`define DA 8'b10100000 /* A */
`define DB 8'b11010000 /* B */
`define DC 8'b11110010 /* C */
`define DD 8'b11100000 /* D */
`define DE 8'b10010010 /* E */
`define DF 8'b10010011 /* F */
`define DX 8'b01111111 /* All segments off except decimal point */

/* Generate one decimal digits from a 4-bit number */
module bcd_to_7seg(input [3:0] num, output reg [7:0] out);
always @ (num)
    begin
        case (num) 
            4'h0: begin out=`D0; end
            4'h1: begin out=`D1; end
            4'h2: begin out=`D2; end
            4'h3: begin out=`D3; end
            4'h4: begin out=`D4; end
            4'h5: begin out=`D5; end
            4'h6: begin out=`D6; end
            4'h7: begin out=`D7; end
            4'h8: begin out=`D8; end
            4'h9: begin out=`D9; end
            4'hA: begin out=`DA; end
            4'hB: begin out=`DB; end
            4'hC: begin out=`DC; end
            4'hD: begin out=`DD; end
            4'hE: begin out=`DE; end
            4'hF: begin out=`DF; end		
       default: begin out=`DX; end
        endcase
    end
endmodule

module LED_MUX (
	input wire clk,
	input wire rst,
	input wire [7:0] LED0, // leftmost digit
	input wire [7:0] LED1,
	input wire [7:0] LED2,
	input wire [7:0] LED3,
	input wire [7:0] LED4,
	input wire [7:0] LED5,
	input wire [7:0] LED6,
	input wire [7:0] LED7, // rightmost digit
	output wire [7:0] LEDSEL,
	output wire [7:0] LEDOUT
	);
	
    reg [2:0] index;
    reg [15:0] led_ctrl;
    
    assign {LEDOUT, LEDSEL} = led_ctrl;

always@(posedge clk)
    begin
        index <= (rst) ? 3'd0 : (index + 3'd1);
    end    

always @(index, LED0, LED1, LED2, LED3, LED4, LED5, LED6, LED7)
    begin
        case(index)
            3'd0: led_ctrl <= {8'b11111110, LED7}; 
            3'd1: led_ctrl <= {8'b11111101, LED6};
            3'd2: led_ctrl <= {8'b11111011, LED5};
            3'd3: led_ctrl <= {8'b11110111, LED4};
            3'd4: led_ctrl <= {8'b11101111, LED3};
            3'd5: led_ctrl <= {8'b11011111, LED2};
            3'd6: led_ctrl <= {8'b10111111, LED1};
            3'd7: led_ctrl <= {8'b01111111, LED0};
         default: led_ctrl <= {8'b11111111, 8'hFF};
        endcase
    end
endmodule


