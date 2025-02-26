//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 03/13/2017 07:20:35 PM
// Design Name: 
// Module Name: CLA.v
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

module cla(input [3:0] a, input [3:0] b, input c_in, output c_out, output [3:0] sum);

    wire [3:0] p;
    wire [3:0] g;
    wire [3:0] c;
    quad_add U1 (.a(a), .b(b), .p(p), .g(g));
    carry    U2 (.cin(c_in), .p(p), .g(g), .c(c), .cout(c_out));
    overall_sum U3 (.c(c), .p(p), .sum(sum));
endmodule

module quad_add(input [3:0] a, input [3:0] b, output [3:0] p, output [3:0] g);
    half_adder U0 (.a(a[0]), .b(b[0]), .p(p[0]), .g(g[0]));
    half_adder U1 (.a(a[1]), .b(b[1]), .p(p[1]), .g(g[1]));
    half_adder U2 (.a(a[2]), .b(b[2]), .p(p[2]), .g(g[2]));
    half_adder U3 (.a(a[3]), .b(b[3]), .p(p[3]), .g(g[3]));
endmodule

module half_adder(input a, input b, output reg  p, output reg g);
    always @(a,b)
    begin
     p = a ^ b;
     g = a & b;
    end
endmodule

module carry(input cin, input [3:0] p, input [3:0] g, output reg [3:0] c, output reg cout);
    always @(cin, p, g)
    begin
       c[0] = cin;
       c[1] = g[0] | p[0] & cin;
       c[2] = g[1] | g[0] & p[1] | cin & p[0] & p[1];
       c[3] = g[2] | g[1] & p[2] | g[0] & p[1] & p[2] | c[0] & p[0] & p[1] & p[2];
       cout = g[3] | g[2] & p[3] | g[1] & p[2] & p[3] | g[0] & p[1] & p[2] & p[3] | c[0] & p[0] & p[1] & p[2] & p[3];
    end
endmodule

module overall_sum(input [3:0] c, input [3:0] p, output [3:0] sum);
    basic_add U0 (c[0], p[0], sum[0]);
    basic_add U1 (c[1], p[1], sum[1]);
    basic_add U2 (c[2], p[2], sum[2]);
    basic_add U3 (c[3], p[3], sum[3]);
endmodule

module basic_add(input c, input p, output reg sum );
    always @(c, p)
    begin
       sum = p ^ c;
    end
endmodule

module clk_gen(input clk100MHz, input rst, output clk_4sec, output clk_5KHz);
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

module led_mux(input wire clk,  input wire rst,input wire [7:0] LED0, input wire [7:0] LED1,  input wire [7:0] LED2,  input wire [7:0] LED3,  input wire [7:0] LED4,  input wire [7:0] LED5,  input wire [7:0] LED6,  input wire [7:0] LED7, output wire [7:0] LEDSEL,  output wire [7:0] LEDOUT);
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

module bcd_to_7seg(input [3:0] bin, output reg s0, s1, s2, s3, s4, s5, s6);   
    always @ (bin) 
    begin
       case (bin)
           4'b0000: begin s0=0; s1=0; s2=0; s3=1; s4=0; s5=0; s6=0; end
           4'b0001: begin s0=1; s1=0; s2=1; s3=1; s4=0; s5=1; s6=1; end
           4'b0010: begin s0=0; s1=1; s2=0; s3=0; s4=0; s5=1; s6=0; end
           4'b0011: begin s0=0; s1=0; s2=1; s3=0; s4=0; s5=1; s6=0; end
           4'b0100: begin s0=1; s1=0; s2=1; s3=0; s4=0; s5=0; s6=1; end
           4'b0101: begin s0=0; s1=0; s2=1; s3=0; s4=1; s5=0; s6=0; end
           4'b0110: begin s0=0; s1=0; s2=0; s3=0; s4=1; s5=0; s6=0; end
           4'b0111: begin s0=1; s1=0; s2=1; s3=1; s4=0; s5=1; s6=0; end
           4'b1000: begin s0=0; s1=0; s2=0; s3=0; s4=0; s5=0; s6=0; end
           4'b1001: begin s0=0; s1=0; s2=1; s3=0; s4=0; s5=0; s6=0; end
       default: begin s0=1; s1=1; s2=1; s3=1; s4=1; s5=1; s6=1; end
       endcase
       end
endmodule

module show_double_number(input [4:0] in, output [6:0] out1, output [6:0] out2);
    reg [3:0] in1, in2;
    always@(in)
       begin
           case(in)
               5'd0,5'd10,5'd20,5'd30 : 
                   in2 = 4'd0;
               5'd1,5'd11,5'd21,5'd31: 
                   in2 = 4'd1;
               5'd2,5'd12, 5'd22:
                   in2 = 4'd2;
               5'd3,5'd13, 5'd23:
                   in2 = 4'd3;
               5'd4,5'd14, 5'd24:
                   in2 = 4'd4;
               5'd5,5'd15, 5'd25:
                   in2 = 4'd5;
               5'd6,5'd16,5'd26:
                   in2 = 4'd6;
               5'd7,5'd17, 5'd27:
                   in2 = 4'd7;
               5'd8,5'd18, 5'd28:
                   in2 = 4'd8;
               5'd9, 5'd19, 5'd29:
                   in2 = 4'd9;
               default: in2 = 4'd0;
           endcase
           case(in)
               5'd10,5'd11,5'd12,5'd13,5'd14, 5'd15,5'd16,5'd17,5'd18,5'd19: 
                          in1 = 4'd1;
               5'd20,5'd21,5'd22,5'd23,5'd24, 5'd25,5'd26,5'd27,5'd28,5'd29:
                          in1 = 4'd2;
               5'd30, 5'd31:
                          in1 = 4'd3;
               default: in1 = 4'd0;
           endcase
       end
    bcd_to_7seg IN1 (.bin(in1), .s0(out1[0]), .s1(out1[1]), .s2(out1[2]), .s3(out1[3]), .s4(out1[4]), .s5(out1[5]), .s6(out1[6])); 
    bcd_to_7seg IN2 (.bin(in2), .s0(out2[0]), .s1(out2[1]), .s2(out2[2]), .s3(out2[3]), .s4(out2[4]), .s5(out2[5]), .s6(out2[6])); 
endmodule

module cla_fpga(
    input [3:0] a, input [3:0] b, input cin, input clk100MHz, input rst, output [3:0] a_out, output [3:0] b_out, output [7:0] LEDOUT, output [7:0] LEDSEL);
    supply1[7:0] vcc; 
    wire [4:0] sum;
    wire [6:0] out_a; 
    wire [6:0] out_b; 
    wire [6:0] i;
    wire DONT_USE, clk_5KHz; 
    
    assign a_out = a;
    assign b_out = b;
    
    cla U0(.a(a), .b(b), .c_in(cin), .c_out(sum [4]), .sum(sum [3:0]));
    show_double_number U1(.in(sum), .out1(out_a), .out2(out_b));
    bcd_to_7seg U2(.bin({3'b0, cin}), .s0(i[0]), .s1(i[1]), .s2(i[2]), .s3(i[3]), .s4(i[4]), .s5(i[5]), .s6(i[6])); 
    led_mux U3(clk_5KHz, rst, {1'b1, i}, vcc, vcc, vcc, vcc, vcc, {1'b1, out_a},{1'b1, out_b}, LEDOUT, LEDSEL); 
    clk_gen U4 (.clk100MHz(clk100MHz), .rst(rst), .clk_4sec(DONT_USE), .clk_5KHz(clk_5KHz));
endmodule





