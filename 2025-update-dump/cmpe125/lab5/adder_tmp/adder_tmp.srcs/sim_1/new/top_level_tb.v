`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 03/22/2017 04:15:14 PM
// Design Name: 
// Module Name: top_level_tb
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


module top_level_tb();
reg [3:0] A_Mul;
reg [3:0] B_Mul;
reg [3:0] A_IM;
reg [3:0] B_IM;

wire [7:0] PMul;
wire [7:0] PIM;
integer i, x; //loop variables

top_level DUT1(.a(A_Mul), .b(B_Mul), .top_level_out(PMul));
initial
begin
    for(i= 0; i<15; i = i + 1)
        begin
        //#5;
        for(x=0; x<15; x = x + 1)
        //#5;
            begin
            //#1;
            A_Mul= i;
           // #1;
            A_IM= i;
            //#1;
            B_Mul=x;
            //#1;
            B_IM=x;
            #1;
            //if(PMul!= A_Mul*B_Mul)
            
            if(PMul!=PIM)
                begin
                $display("Error");
                $stop;
                end
            end
        end
    $display("succesfull");
    $stop;
end
endmodule
 