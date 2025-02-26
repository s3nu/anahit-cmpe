`timescale 1ns / 1ps

module factorial_wrapper_top_tb();

    reg we, rst, clk;
    reg [3:0] wd;
    reg [1:0] addr;
    wire [31:0] rd;
    wire done_sig;
    reg [31:0] comparrison_array[15:0];
    
    factorial_wrapper_top DUT (.wd(wd), .we(we), .rst(rst), .clk(clk), .addr(addr), .rd(rd), .done_sig(done_sig));
    
    task factorial;
        input [3:0] temp_in;
        output [31:0] temp_out;
        integer i, j;
        begin
            j = 1;
            for (i = temp_in; i > 0; i = i - 1) begin
                j = j * i;
            end
            temp_out = j;
        end
    endtask
    
    task toggle_clk;
        begin
            #10 clk = 1;
            #10 clk = 0;
        end
    endtask
    
    integer k, m, n;
    initial begin
        we = 1'b1;
        for (k = 15; k >= 0; k = k - 1) begin
            factorial(k, m);
            comparrison_array[k] = m;
        end
        for (n = 15; n >= 0; n = n - 1) begin
            rst = 0;
            toggle_clk;
            rst = 1;
            toggle_clk;
            rst = 0;
            wd = n;        
            addr = 2'b00;
            toggle_clk;
            addr = 2'b01;
            wd = 1;
            toggle_clk;
            addr = 2'b10;
            toggle_clk;
            while (!done_sig) begin
                toggle_clk;
            end
            if (rd == 32'b10)
                $display("ERROR: input value greater than 12\n");
            addr = 2'b11;
            toggle_clk;
            if (comparrison_array[n] != rd)
                $display("ERROR: Expected %d! = %d, found %d.\n", n, comparrison_array[n], rd);
            else
                $display("SUCCESS: %d! = %d\n", n, rd);
            rst = 1;
            toggle_clk;
        end
        $finish;
    end
endmodule

