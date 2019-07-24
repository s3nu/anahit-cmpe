`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 08/29/2017 09:24:31 PM
// Design Name: 
// Module Name: Factorial_tb
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


module Factorial_tb();
reg [3:0] n_tb;
reg Go_tb, clk_tb, rst_tb;
wire Done_tb;
wire [31:0] out_tb;
integer i;
Factorial DUT (.n(n_tb), .Go(Go_tb), .clk(clk_tb), .rst(rst_tb),.Done(Done_tb), .out(out_tb));
task tick; 
    begin 
        #5 clk_tb = 1; 
        #5 clk_tb = 0; 
    end 
endtask
initial
begin
    n_tb = 0; clk_tb = 0; rst_tb = 0; 
    Go_tb = 0; tick; tick; tick; tick; tick; tick; tick; tick; tick; tick;
    Go_tb = 1;
    for(i = 0; i < 11; i = i + 1)
    begin
            n_tb = i;
            tick;
            while(!Done_tb)
            begin
               tick;
            end
            case(i)
                4'd0: begin if(out_tb != 1) $display("Error with 0"); end
                4'd1: begin if(out_tb != 1) $display("Error with 1"); end
                4'd2: begin if(out_tb != 2) $display("Error with 2"); end
                4'd3: begin if(out_tb != 6) $display("Error with 3"); end
                4'd4: begin if(out_tb != 24) $display("Error with 4"); end
                4'd5: begin if(out_tb != 120) $display("Error with 5"); end
                4'd6: begin if(out_tb != 720) $display("Error with 6"); end
                4'd7: begin if(out_tb != 5040) $display("Error with 7"); end
                4'd8: begin if(out_tb != 40320) $display("Error with 8"); end
                4'd9: begin if(out_tb != 362880) $display("Error with 9"); end
                4'd10: begin if(out_tb != 3628800) $display("Error with 10"); end
           endcase
   end
   $display("End of Simulation");
   $finish;
end
endmodule
