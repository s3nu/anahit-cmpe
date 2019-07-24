`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 09/02/2017 12:14:58 PM
// Design Name: 
// Module Name: showNumber
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


module showNumber(input [3:0] dig0, dig1, dig2, dig3, dig4, dig5, dig6, dig7,
                  output [6:0] out0, out1, out2, out3, out4, out5, out6, out7);
bcd_to_7seg IN1( .BCD(dig0),  .s0(out0[0]), .s1(out0[1]), .s2(out0[2]), .s3(out0[3]), .s4(out0[4]), .s5(out0[5]), .s6(out0[6])); 
bcd_to_7seg IN2( .BCD(dig1),  .s0(out1[0]), .s1(out1[1]), .s2(out1[2]), .s3(out1[3]), .s4(out1[4]), .s5(out1[5]), .s6(out1[6]));
bcd_to_7seg IN3( .BCD(dig2),  .s0(out2[0]), .s1(out2[1]), .s2(out2[2]), .s3(out2[3]), .s4(out2[4]), .s5(out2[5]), .s6(out2[6]));
bcd_to_7seg IN4( .BCD(dig3),  .s0(out3[0]), .s1(out3[1]), .s2(out3[2]), .s3(out3[3]), .s4(out3[4]), .s5(out3[5]), .s6(out3[6]));
bcd_to_7seg IN5( .BCD(dig4),  .s0(out4[0]), .s1(out4[1]), .s2(out4[2]), .s3(out4[3]), .s4(out4[4]), .s5(out4[5]), .s6(out4[6])); 
bcd_to_7seg IN6( .BCD(dig5),  .s0(out5[0]), .s1(out5[1]), .s2(out5[2]), .s3(out5[3]), .s4(out5[4]), .s5(out5[5]), .s6(out5[6]));
bcd_to_7seg IN7( .BCD(dig6),  .s0(out6[0]), .s1(out6[1]), .s2(out6[2]), .s3(out6[3]), .s4(out6[4]), .s5(out6[5]), .s6(out6[6]));
bcd_to_7seg IN8( .BCD(dig7),  .s0(out7[0]), .s1(out7[1]), .s2(out7[2]), .s3(out7[3]), .s4(out7[4]), .s5(out7[5]), .s6(out7[6]));                  
endmodule
