`timescale 1ns / 1ps

module factorial_top_tb();

    reg go, clk, rst; 
    wire done, error;
    reg [3:0] in; 
    wire [3:0] cs;
    wire [31:0] product;
    reg [31:0] comparrison_array[15:0];
    
    factorial_top DUT 
        (
        .go(go), 
        .clk(clk),
        .rst(rst), 
        .in(in), 
        .done(done),
        .error(error), 
        .cs(cs), 
        .product(product)
        );

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
        for (k = 15; k >= 0; k = k - 1) begin
            factorial(k, m);
            comparrison_array[k] = m;
        end
        for (n = 15; n >= 0; n = n - 1) begin
            rst = 0;        
            go = 0;
            toggle_clk;
            in = n;
            toggle_clk;
            go = 1;
            while (!done) begin
                toggle_clk;
            end
            if (error)
                $display("ERROR: input value greater than 12\n");
            else if (comparrison_array[n] != product)
                $display("ERROR: Expected %d! = %d, found %d.\n", n, comparrison_array[n], product);
            else
                $display("SUCCESS: %d! = %d\n", n, product);
            rst = 1;
            toggle_clk;
        end
    end
endmodule
