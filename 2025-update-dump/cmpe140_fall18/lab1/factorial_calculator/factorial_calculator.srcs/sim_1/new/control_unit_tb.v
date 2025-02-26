`timescale 1ns / 1ps

module control_unit_tb();

    reg go, clk, gt, rst;
    wire select, load_counter, enable, load_register, output_enable, done;
    wire [3:0] cs;
    
    control_unit DUT 
        (
        .go(go), 
        .gt(gt), 
        .clk(clk),
        .rst(rst), 
        .select(select), 
        .load_counter(load_counter), 
        .enable(enable), 
        .load_register(load_register), 
        .output_enable(output_enable), 
        .done(done),
        .cs(cs)
        );
    
    task toggle_clk;
        begin
            #10 clk <= 1;
            #10 clk <= 0;
        end
    endtask
    integer i;

    initial begin
        $display("begin testbench.\n");
        go = 1'b1;
        gt = 1'b1;
        i = 0;
        rst = 1'b0;
        toggle_clk;
        while (done != 1) begin
            toggle_clk;
            rst = 1'b0;
            i = i + 1;
            if (i > 5)
                gt = 1'b0;
            case (cs)
                0:  begin
                        if (select || load_counter || enable || load_register || done) begin
                            $display("ERROR: state %d\n", cs);
                            $stop;
                        end
                    end
                1:  begin
                        if (output_enable || !select || !load_counter || !load_register) begin
                            $display("ERROR: state %d\n", cs);
                            $stop;
                        end
                    end
                2:  begin
                        if (select || load_counter || enable || load_register) begin
                            $display("ERROR: state %d\n", cs);
                            $stop;
                        end
                    end
                3:  begin
                        if (!output_enable || !done) begin
                            $display("ERROR: state %d\n", cs);
                            $stop;
                        end
                    end
                4:  begin
                        if (!load_register || !enable) begin
                            $display("ERROR: state %d\n", cs);
                            $stop;
                        end
                    end
            endcase
            rst = 1'b1;
        end             
    $display("Test complete.\n");
    $finish;
    end                        
endmodule
