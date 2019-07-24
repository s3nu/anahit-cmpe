`timescale 1ns / 1ps

module GPIO_decoder(A, WE, WE1, WE2,RdSel);
// declaring inputs
input wire [1:0] A;
input wire WE;
// declaring outputs
output reg WE1;
output reg WE2;
// control for mux
output wire [1:0] RdSel;
//address decoding 
always @ (*) begin
case (A)
2'b00: begin
WE1=1'b0;
WE2=1'b0;
end
2'b01: begin
WE1=1'b0;
WE2=1'b0;
end
2'b10: begin
WE1=WE;
WE2=1'b0;
end
2'b11: begin
WE1=1'b0;
WE2=WE;
end
default: begin
WE1 = 1'bx;
WE2 = 1'bx;
end
endcase
end
assign RdSel = A;
endmodule

// MUX module
module GPIO_MUX(RdSel, gpl1, gpl2, gpo1, gpo2, RD);
// declaring inputs 
input [1:0] RdSel;
input [31:0] gpl1;
input [31:0] gpl2;
input [31:0] gpo1;
input [31:0] gpo2;
// declaring output
output reg [31:0] RD;

always @(*) begin
case(RdSel)
2'b00: RD = gpl1;
2'b01: RD = gpl2;
2'b10: RD = gpo1;
2'b11: RD = gpo2;
default: RD = {31{1'bx}};
endcase
end
endmodule

// register
module GPIO_reg #(parameter w = 32) (
input wire Clk, Rst,
input wire [w-1:0] WD,
input wire EN,
output reg [w-1:0] Q );
always @ (posedge Clk, posedge Rst)
if (Rst)
Q <= 0;
else if (EN)
Q <= WD;
else
Q <= Q;
endmodule

//GPIO top level module
module GPIO_top(A, WE, gpl1,gpl2, WD, RST, Clk, RD, gpo1, gpo2);
// declaring inputs 
input [1:0] A;
input WE;
input [31:0] gpl1;
input [31:0] gpl2;
input [31:0] WD;
input RST;
input Clk;
// declaring outputs
output [31:0] RD;
output [31:0] gpo1;
output [31:0] gpo2;
// declaring wires
wire WE2,WE1;
wire[1:0] RdSel;
// decoder
GPIO_decoder U1(.A(A), .WE(WE), .WE1(WE1), .WE2(WE2),.RdSel(RdSel));
// register gpO1
GPIO_reg U2(.Clk(Clk),.Rst(RST),.WD(WD),.EN(WE1),.Q(gpo1));
// register gpO2
GPIO_reg U3(.Clk(Clk),.Rst(RST),.WD(WD),.EN(WE2),.Q(gpo2));
// mux
GPIO_MUX U4(.RdSel(RdSel), .gpl1(gpl1), .gpl2(gpl2), .gpo1(gpo1), .gpo2(gpo2), .RD(RD));
endmodule











