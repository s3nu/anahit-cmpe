`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 09/02/2017 06:15:18 PM
// Design Name: 
// Module Name: clk_gen
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


module clk_gen(clk100MHz, rst, clk_4sec, clk_5KHz);
input clk100MHz, rst; 
output clk_4sec, clk_5KHz; 
reg clk_4sec, clk_5KHz; 
integer count, count1; 
always@(posedge clk100MHz)
begin
 if(rst)  
 begin
  count = 0;   
  count1 = 0;
  clk_4sec = 0;   
  clk_5KHz  =0;
 end  
 else  
 begin
  if(count == 200000000)
  begin
   clk_4sec = ~clk_4sec;    
   count = 0;
  end
  if(count1 == 10000)   
  begin
   clk_5KHz = ~clk_5KHz;    
   count1 = 0;   
   end   
   count = count + 1;   
   count1 = count1 + 1;         
  end 
 end 
 endmodule // end clk_gen
