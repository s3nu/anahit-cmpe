`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 09/08/2018 06:38:52 PM
// Design Name: 
// Module Name: datapath_tb
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
module datapath_tb();

    reg [3:0] in;
    reg load_counter, select, load_register, enable_counter, clk, output_enable;
    wire gt;
    wire [31:0] product;

    data_path DUT 
    (
        .in(in), .load_counter(load_counter), .select(select), .load_register(load_register), .enable_counter(enable_counter), 
        .clk(clk), .output_enable(output_enable), .product(product), 
        .gt(gt)
    );

    integer i;
    integer j = 0;
    //integer k;
    integer m;
    integer n;
    
    reg [31:0] comparrison_array[15:0];
    
    task factorial;
        input [3:0] temp_in;
        output [31:0] temp_out;
        begin
            j = 1;
            for (i = temp_in; i > 0; i = i - 1) begin
                j = j * i;
            end
            temp_out = j;
        end
    endtask
    
    task toggle_clk;
        input [31:0] count;
        integer k;
        begin
            for (k = 0; k < count; k = k + 1) begin
                #10 clk = 1; 
                #10 clk = 0;
            end
        end       
    endtask

    initial begin
        $display("Begin Testbench.\n");
        
        for (m = 15; m >= 0; m = m - 1) begin
            factorial (m, n);
            comparrison_array[m] = n;
        end    
                        
        for (m = 15; m > 0; m = m - 1) begin
            in = m; 
            output_enable = 0;
            toggle_clk(10);
            select = 1; load_counter = 1; load_register = 1;
            toggle_clk(10);
            load_counter = 0;
            load_register = 0;
            toggle_clk(10);
            while(gt) begin
                select = 0;
                enable_counter = 1;
                load_register = 1;
                toggle_clk(1);
                //select = 0;
            end
            enable_counter = 0;
            load_register = 0;
            output_enable = 1;
            toggle_clk(10);   

            if (comparrison_array[m] != product)
                $display("ERROR: Expected %d! = %d, found %d.\n", m, comparrison_array[m], product);
            else
                $display("SUCCESS: %d! = %d\n", m, product);
        end
        $finish;
    end
endmodule