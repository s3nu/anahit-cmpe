`timescale 1ns / 1ps
module GPIO_tb;
// inputs
reg [1:0] A_tb;
reg WE_tb;
reg [31:0] gpl1_tb;
reg [31:0] gpl2_tb;
reg [31:0] WD_tb;
reg Clk_tb;
reg Rst_tb;
// outputs
wire [31:0] RD_tb;
wire [31:0] gpO1_tb;
wire [31:0] gpO2_tb;
// test integer
integer test=7;

//calling top level module
GPIO_top U1(.A(A_tb), .WE(WE_tb), .gpl1(gpl1_tb),.gpl2(gpl2_tb), .WD(WD_tb), .RST(Rst_tb), .Clk(Clk_tb), .RD(RD_tb), .gpo1(gpO1_tb), .gpo2(gpO2_tb));

task clock;
    begin
        #10 Clk_tb = 1'b1;
        #10 Clk_tb = 1'b0;
        #10 Rst_tb=  1'b0;
    end
endtask

initial begin
// reset & clock
Rst_tb=1'b1;
clock;

//testing 00 case
A_tb=2'b00;
WE_tb=1'b0;
gpl1_tb=test;
//compare gpl1 & test value
if(RD_tb!=gpl1_tb)
begin
$display("Input 1 does not match");
$stop;
end 

#10

//testing 01 case
A_tb=2'b01;
WE_tb=1'b0;
gpl2_tb=test;
//compare gpl1 & test value
if(RD_tb!=gpl2_tb)
begin
$display("Input 2 does not match");
$stop;
end 

#10;
//testing 10 case
A_tb=2'b10;
WE_tb=1'b1;
WD_tb=test;
clock;
//compare gpO1 & test value
if(RD_tb!=gpO1_tb)
begin
$display("Output 1 does not match");
$stop;
end 

#10;
//testing 11 case
A_tb=2'b11;
WE_tb=1'b1;
WD_tb=test;
clock;
//compare gpO2 & test value
if(RD_tb!=gpO2_tb)
begin
$display("Output 2 does not match");
$stop;
end 

#10;
$display("GPIO test is successful");
$stop;

end // initial begin
endmodule
