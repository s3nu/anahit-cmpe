`timescale 1ns / 1ps

module BUFF #(parameter DATA_WIDTH = 32)
            (A, Y, E);
input [DATA_WIDTH-1:0] A;
input E;
output [DATA_WIDTH-1:0] Y;

assign Y = (E) ? A : 'bz;

endmodule

module CMP #(parameter DATA_WIDTH = 32)
            (A, B, GT);
input [DATA_WIDTH-1:0] A, B;
output GT;

assign GT = (A > B) ? 1 : 0;

endmodule

module CNT #(parameter DATA_WIDTH = 32)
            (D, Load_cnt, EN, CLK, Q);
//parameter DATA_WIDTH = 4;
input [DATA_WIDTH-1:0] D;
input Load_cnt, EN, CLK;
output reg [DATA_WIDTH-1:0] Q;

always@(posedge CLK)
begin
    if (EN)
    begin
        if (Load_cnt)
            Q = D;
        else
            Q = Q - 1;
    end
end

endmodule

module CU(Go, clk, gt, Done, cw, rst, error, Err);
input Go, clk;
input gt;
input rst;
input error;
output reg Done;
output reg [4:0] cw;
output reg Err;

reg [1:0] CS, NS;   //there are a total of three states

initial
    CS = 2'b00;
/*
always@(rst)
    if(rst)
        CS = 3'b000;
*/
//Next-State Logic (combinational) based on the state transition diagram
always@(CS, Go, gt, rst, error)
begin
    if(rst)
        NS = 2'b00;
    else
    begin
      case(CS)
        2'b00: begin
                    if(!Go)
                        NS = 2'b00;
                    else
                        NS = 2'b01;
               end
        2'b01: begin
                    NS = 2'b10;
               end
        2'b10: begin
                    if(gt && (!error))
                        NS = 2'b10;
                    else
                        NS = 2'b00;
               end
        default: NS = 2'b00;
      endcase
    end
end

//State Register (sequential)
always@(posedge clk)
    CS <= NS;

//Output Logic (combinational) based on the output table
always@(CS, error, gt)
begin
    case(CS)
    2'b00: begin
                cw = 5'b00000;
                Done = 0;
                Err = 0;
           end
    2'b01: begin
                cw = 5'b11100;
                Done = 0;
                Err = 0;
           end
    2'b10: begin
                if(error)
                begin
                    cw = 5'b00010;
                    Err = 1;
                    Done = 1;
                end
                else if(!error && gt)
                begin
                    cw = 5'b01110;
                    Err = 0;
                    Done = 0;
                end
                else
                begin
                    cw = 5'b00011;
                    Err = 0;
                    Done = 1;
                end
           end
endcase
end

endmodule

module DP_fact #(parameter DATA_WIDTH = 32)
                (n, out, cw, clk, gt, error);
input [DATA_WIDTH-1:0] n;
input [4:0] cw;
input clk;
output [DATA_WIDTH-1:0] out;
output gt, error;
wire Load_cnt, EN, Load_reg, sel, OE;
wire [DATA_WIDTH-1:0] cnt, D, product, z;

assign {Load_cnt, EN, Load_reg, sel, OE} = cw;

CNT #(DATA_WIDTH) U0(.D(n), .Load_cnt(Load_cnt), .EN(EN), .CLK(clk), .Q(cnt));
REG #(DATA_WIDTH) U1(.D(D), .Load_reg(Load_reg), .CLK(clk), .Q(product));
CMP #(DATA_WIDTH) U2(.A(cnt), .B(1), .GT(gt));
//CMP #(DATA_WIDTH) U6(.A(z), .B(99999999), .GT(error));
CMP #(DATA_WIDTH) U6(.A(cnt), .B(12), .GT(error));
MUL #(DATA_WIDTH) U3(.x(cnt), .y(product), .z(z));
MUX #(DATA_WIDTH) U4(.d1(z), .d0(1), .sel(sel), .y(D));
BUFF #(DATA_WIDTH) U5(.A(product), .E(OE), .Y(out));

endmodule


module fact_ad(
    input wire[1:0] A,
    input wire      WE,
    output reg      WE1,
    output reg      WE2,
    output wire [1:0] RdSel);

always @ (*) begin
    case (A)
        2'b00: begin
         WE1 = WE;
         WE2 = 1'b0;
        end
        2'b01: begin
         WE1 = 1'b0;
         WE2 = WE;
        end
        2'b10: begin
         WE1 = 1'b0;
         WE2 = 1'b0;
        end
        2'b11: begin
         WE1 = 1'b0;
         WE2 = 1'b0;
        end
        default: begin
         WE1 = 1'bx;
         WE2 = 1'bx;
        end
    endcase
end

assign RdSel = A;

endmodule

module fact_reg #(parameter w = 32) (
 input wire Clk, Rst,
 input wire [w-1:0] D,
 input wire Load_Reg,
 output reg [w-1:0] Q);

always @ (posedge Clk, posedge Rst)
    if (Rst)
        Q <= 0;
    else if (Load_Reg)
        Q <= D;
    else
        Q <= Q;

endmodule

module fact_top(
 input [1:0] A,
 input WE,
 input [3:0] WD,
 input Clk, Rst,
 output reg [31:0] RD);

wire WE1, WE2, Go, GoPulse, Done, Err, GoPulseCmb;
wire [1:0] RdSel;
wire [3:0] n;
wire [31:0] nf, Result;
reg ResDone, ResErr;

fact_ad fad(A, WE, WE1, WE2, RdSel);
fact_reg #(4) fn(Clk, Rst, WD, WE1, n);
fact_reg #(1) fgo(Clk, Rst, WD[0], WE2, Go);
fact_reg fresult(Clk, Rst, nf, Done, Result);
Factorial fact(GoPulse, {28'b0, n}, Clk, Done, nf, Rst, Err);

assign GoPulseCmb = WD[0] & WE2;
assign GoPulse = GoPulseCmb;

//Factorial Result Done Register
always @ (posedge Clk, posedge Rst)
begin
    if (Rst)
        ResDone <= 1'b0;
    else
        ResDone <= (~GoPulseCmb) & (Done | ResDone);
end

//Factorial Result Err Register
always @ (posedge Clk, posedge Rst)
begin
    if (Rst)
        ResErr <= 1'b0;
    else
        ResErr <= (~GoPulseCmb) & (Err | ResErr);
end

//Read Data Logic (the output MUX):
always @ (*) begin
    case (RdSel)
        2'b00:   RD = {{(32-4){1'b0}}, n};
        2'b01:   RD = {{31{1'b0}}, Go};
        2'b10:   RD = {{30{1'b0}}, ResErr, ResDone};
        2'b11:   RD = Result;
        default: RD = {31{1'bx}};
    endcase
end

endmodule

module Factorial #(parameter DATA_WIDTH = 32)
                    (Go, n, clk, Done, out, rst, Err);
input Go, clk, rst;
input [DATA_WIDTH-1:0] n;
output Done, Err;
output [DATA_WIDTH-1:0] out;
wire [4:0] cw;
wire gt, error;

CU U0(Go, clk, gt, Done, cw, rst, error, Err);
DP_fact #(DATA_WIDTH) U1(n, out, cw, clk, gt, error);

endmodule

module MUL #(parameter DATA_WIDTH = 32)
            (x, y, z);
input[DATA_WIDTH-1:0] x, y;
output[DATA_WIDTH-1:0] z;

assign z = x * y;

endmodule

module MUX #(parameter DATA_WIDTH = 32)
            (d1, d0, sel, y);
input [DATA_WIDTH-1:0] d1, d0;
input sel;
output [DATA_WIDTH-1:0] y;

assign y = (sel) ? d1 : d0;

endmodule

module REG #(parameter DATA_WIDTH = 32)
            (D, Load_reg, CLK, Q);
input[DATA_WIDTH-1:0] D;
input Load_reg, CLK;
output reg [DATA_WIDTH-1:0] Q;

always@(posedge CLK)
begin
    if(Load_reg)
        Q = D;
    else
        Q = Q;
end

endmodule


