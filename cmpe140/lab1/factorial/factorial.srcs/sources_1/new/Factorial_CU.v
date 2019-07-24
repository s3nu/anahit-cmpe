`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 08/29/2017 08:04:11 PM
// Design Name: 
// Module Name: Factorial_CU
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


module Factorial_CU(input Go, clk, rst, Is_Gt,
                    output reg Done,
                    output reg [5:0] ctrl);
reg [3:0] ns, cs;
parameter
    IDLE = 6'b0_0_0_0_0_0,
    S1 =   6'b0_1_0_1_1_0,
    S2 =   6'b1_0_0_0_0_0,
    S3 =   6'b1_0_0_0_0_1,
    S4 =   6'b1_1_0_0_1_0;
    

always @(Go, Is_Gt, Done, ns, cs)
begin
        case(cs)
            4'd0:
                begin
                    Done = 0;
                    if(Go) begin ns = 4'd1; end
                    else begin ns = 4'd0; end
                end
            4'd1:   begin Done = 0; ns = 4'd2; end
            4'd2: 
                begin
                    if(Is_Gt) begin ns = 4'd4; Done = 0; end
                    else begin ns = 4'd3; Done = 0; end 
                end
            4'd3:   
                begin 
                    Done = 1; 
                    ns = 4'd0; 
                end
            4'd4: 
                begin 
                    Done = 0; 
                    ns = 4'd2; 
                end
            default: ns = 4'd0;                 
        endcase
end

always @(posedge clk, posedge rst)
begin
         if(rst)
             cs <= 0;
         else
             cs <= ns;
end

always @(cs, ctrl) //{Sel1, ce, ud, ld1, ld2, sel2} = ctrl;
begin
        case(cs)
            4'd0:   ctrl = IDLE;
            4'd1:   ctrl = S1;
            4'd2:   ctrl = S2;
            4'd3:   ctrl = S3;
            4'd4:   ctrl = S4; 
        endcase
end        
endmodule


