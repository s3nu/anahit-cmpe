//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 03/13/2017 07:20:35 PM
// Design Name: 
// Module Name: tb.v
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
module tb_cla();
    reg [3:0] a_tb;
    reg [3:0] b_tb;
    reg cin_tb;
    wire cla_cout_tb;
    wire [3:0] cla_sum_tb;
    wire inf_cout_tb;
    wire [3:0] inf_sum_tb;
    cla DUT0 (.a(a_tb), .b(b_tb), .c_in(cin_tb), .c_out(cla_cout_tb), .sum(cla_sum_tb));
    //infer_add DUT1 (.a(a_tb), .b(b_tb), .cin(cin_tb), .sum(inf_sum_tb), .cout(inf_cout_tb));
    integer i,x,z;
    initial
    begin
    a_tb = 4'b0000;
    b_tb = 4'b0000;
    for(i=0; i < 16;i = i + 1)
    begin
        a_tb = i;
        for(x=0; x < 16; x = x + 1)
        begin
            b_tb = x;
            for(z=0; z < 2; z = z + 1)
                begin
                cin_tb = z;
                #1;
                if({cla_cout_tb, cla_sum_tb} != (a_tb + b_tb + cin_tb))
                    $display("Error");
                if({inf_cout_tb, inf_sum_tb} != (a_tb + b_tb + cin_tb))
                    $display("Error");
                end
        end
    end
    $display("Succesfull"); 
    $finish;
    end
endmodule
