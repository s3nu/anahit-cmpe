`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 05/19/2017 04:26:53 PM
// Design Name: 
// Module Name: dp_tb
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


module dp_tb();
reg [3:0] n_tb;
reg [5:0] ctrl_tb;
reg clk_tb, rst_tb;
wire [31:0] out_tb;
wire Is_GT_tb;
integer i;
    
Factorial_DP DUT( .n(n_tb), .ctrl(ctrl_tb), .clk(clk_tb), .rst(rst_tb), .out(out_tb), .Is_GT(Is_GT_tb));

parameter
    IDLE = 6'b0_0_0_0_0_0,
    S1 =   6'b0_1_0_1_1_0,
    S2 =   6'b1_0_0_0_0_0,
    S3 =   6'b1_0_0_0_0_1,
    S4 =   6'b1_1_0_0_1_0;

task tick; begin #5 clk_tb = 1; #5 clk_tb = 0; end endtask  
    initial
    begin
        clk_tb = 0; rst_tb = 0;
    
        
        for(i = 0; i < 11; i = i + 1)
        begin
            n_tb = i;
            ctrl_tb = IDLE; tick;
            ctrl_tb = S1; tick;
            while(Is_GT_tb)
            begin
                ctrl_tb = S2; tick;
                ctrl_tb = S4; tick;
            end
            ctrl_tb = S3; tick;
            case(i)
                4'd0: begin if(out_tb != 0) $display("Error with 0"); end
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
        $display("End of Sim");
        $finish;
    end
   
endmodule
