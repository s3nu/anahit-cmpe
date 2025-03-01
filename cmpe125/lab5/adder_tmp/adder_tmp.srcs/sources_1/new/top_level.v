`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 03/22/2017 04:14:46 PM
// Design Name: 
// Module Name: top_level
// Project Name: 
// Target Devices: 
// Tool Versions: 
// Description: 
// 
// Dependencies: 
// 
// Revision:
// Revision 0.01 - File Created
// Additional Comments:
// 
//////////////////////////////////////////////////////////////////////////////////


module top_level(input [3:0]a, input [3:0]b, output[7:0]top_level_out);
    //ouput that leave the partial product generator 
    wire [3:0]PP0;
    wire [3:0]PP1;
    wire [3:0]PP2;
    wire [3:0]PP3;
   //output of shifter
    wire [3:0] p0, p1, p2, p3;
    
    //lost bits
    wire missing_bit, missing_bit_two;
    wire C1;
    wire C2;
    //carry out of cla's
    wire [3:0]cla1;
    wire [3:0]cla2, HiSum, LoSum;
    wire cout1, cout2, cout3;
    wire PSum1, PSum2, Pcout1, Pcout2, cout4;
   
   padding u0( a, b, PP0, PP1, PP2, PP3);
   padding_shift u1(PP1, p1, missing_bit);
   padding_shift u2(PP3, p3, missing_bit_two);
   
   cla_top_level u3(PP0, p1, 1'b0, cla1, cout1);
   cla_top_level u4(PP2, p3, 1'b0, cla2, cout2);
   
   add u5(cout1, missing_bit, PSum1, Pcout1);
   add u6(cout2, missing_bit_two, PSum2, Pcout2);
   
   cla_top_level u7(cla1, {cla2[1:0],2'b00}, 1'b0, LoSum, cout3);
   cla_top_level u8({2'b00, Pcout1, PSum1}, {Pcout2, PSum2, cla2[3:2]}, cout3, HiSum, cout4);

   assign top_level_out = {cout4, HiSum, LoSum};    //store output
endmodule

module clk_gen_multi(input clk100MHz, input rst, output clk_4sec, output clk_5KHz);
    reg clk_4sec, clk_5KHz; 
    integer c, x; 
    always@(posedge clk100MHz)
    begin
       if(rst)  
           begin
               c = 0;   
               x = 0;
               clk_4sec = 0;   
               clk_5KHz  = 0;
           end  
       else  
           begin
               if(c == 200000000)
                   begin
                       clk_4sec = ~clk_4sec;    
                       c = 0;
                   end
               if(x == 10000)   
                   begin
                       clk_5KHz = ~clk_5KHz;    
                       x = 0;   
                   end   
           c = c + 1;   
           x = x + 1;         
           end
    end
endmodule

module padding(input [3:0]a, input [3:0]b, output [3:0]p0, p1, p2, p3);

assign p0 = {{a[0]&b[0]},{a[1]&b[0]},{a[2]&b[0]},{a[3]&b[0]}};
assign p1 = {{a[0]&b[1]},{a[1]&b[1]},{a[2]&b[1]},{a[3]&b[1]}};
assign p2 = {{a[0]&b[2]},{a[1]&b[2]},{a[2]&b[2]},{a[3]&b[2]}};
assign p3 = {{a[0]&b[3]},{a[1]&b[3]},{a[2]&b[3]},{a[3]&b[3]}};

endmodule

module padding_shift(input [3:0] shift_input, output [3:0] shift_out, output lost_out);
    assign shift_out= {{shift_input[2:0]}, 1'b0};
    assign lost_out= shift_input[3];
endmodule

module cla_top_level(input [3:0] a, input [3:0] b, input cla_input, output [3:0] summer, output cla_ouput);
    wire [3:0] cla_sum,p,g;
    
    add u0(a[0], b[0], p[0], g[0]);
    add u1(a[1], b[1], p[1], g[1]);
    add u2(a[2], b[2], p[2], g[2]);
    add u3(a[3], b[3], p[3], g[3]);
    
    cla_gen u4(cla_input, p, g, {cla_ouput, cla_sum});
    
    assign summer = p ^ cla_sum;
endmodule

module add(
    input a, b,
    output p, g
    );
    assign p = a ^ b;
    assign g = a & b;
endmodule

module cla_gen(input cin, input [3:0] p, input [3:0] g, output reg [3:0] c, output reg cout);
    always @(cin, p, g)
    begin
       c[0] = cin;
       c[1] = g[0] | p[0] & cin;
       c[2] = g[1] | g[0] & p[1] | cin & p[0] & p[1];
       c[3] = g[2] | g[1] & p[2] | g[0] & p[1] & p[2] | c[0] & p[0] & p[1] & p[2];
       cout = g[3] | g[2] & p[3] | g[1] & p[2] & p[3] | g[0] & p[1] & p[2] & p[3] | c[0] & p[0] & p[1] & p[2] & p[3];
    end
endmodule



