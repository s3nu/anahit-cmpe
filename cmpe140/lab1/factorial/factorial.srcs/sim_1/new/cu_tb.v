`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 08/29/2017 08:25:45 PM
// Design Name: 
// Module Name: cu_tb
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


module cu_tb();
reg Go_tb, clk_tb, rst_tb, Is_Gt_tb;
wire Done_tb;
wire [5:0] ctrl_tb;

Factorial_CU DUT(.Go(Go_tb), .clk(clk_tb), .rst(rst_tb), .Is_Gt(Is_Gt_tb), .Done(Done_tb), .ctrl(ctrl_tb));
parameter
    IDLE = 6'b0_0_0_0_0_0,
    S1 =   6'b0_1_0_1_1_0,
    S2 =   6'b1_0_0_0_0_0,
    S3 =   6'b1_0_0_0_0_1,
    S4 =   6'b1_1_0_0_1_0;
    
task tick; begin #5 clk_tb = 1; #5 clk_tb = 0; end endtask
initial
begin
    clk_tb = 0; rst_tb = 0; Go_tb = 1; Is_Gt_tb = 1;
    tick;
    if(ctrl_tb != IDLE) $display("Error with IDLE");
    tick;
    if(ctrl_tb != S1) $display("Error with S1");
    tick;
    if(ctrl_tb != S2) $display("Error with S2");
    tick;
    if(ctrl_tb != S4) $display("Error with S4");
    tick;
    Is_Gt_tb = 0;
    tick;
    if(ctrl_tb != S3) 
    begin
        $display("Error with S3");
        if(Done_tb != 1)  $display("Error with Done");
    end
     $display("End of Simulation");
     $finish;
end
endmodule
