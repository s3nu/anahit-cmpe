`timescale 1ns / 1ps

module control_unit
    (
    input wire go, gt, gt12, clk, rst,
    output reg select, load_counter, enable, load_register, output_enable, done, error,
    output wire [3:0] cs
    );
    
    parameter state0 = 4'd0,
              state1 = 4'd1,
              state2 = 4'd2,
              state3 = 4'd3,
              state4 = 4'd4;
              
    reg [3:0] cur_state, next_state;
    
    always @(cur_state, go, gt, rst) begin
        case(cur_state)
            state0:     begin
                            if (gt12)
                                next_state <= state3;
                            else
                                next_state <= (go) ? state1 : state0;
                        end
            state1:     next_state <= state2;
            state2:     next_state <= (gt) ? state4 : state3;
            state3:     next_state <= (rst) ? state0 : state3;
            state4:     next_state <= state2;
            default:    next_state <= state0;
        endcase
    end
    
    always @(posedge clk) begin
        cur_state <= next_state;
    end
    
    always @(cur_state) begin
        case(cur_state)
            state0:     begin
                            select <= 0;
                            load_counter <= 0;
                            enable <= 0;
                            load_register <= 0;
                            done <= 0;
                            error <= 0;                            
                        end
            state1:     begin
                            output_enable <= 0;
                            select <= 1;
                            load_counter <= 1;
                            load_register <= 1;

                        end
            state2:     begin
                            select <= 0;
                            load_counter <= 0;
                            load_register <= 0;
                            enable <= 0;
                        end
            state4:     begin
                            load_register <= 1;
                            enable <= 1;
                        end
            state3:     begin
                            output_enable <= (gt12) ? 0 : 1;
                            done <= 1;
                            error <= (gt12) ? 1 : 0;
                        end
        endcase
    end 
    assign cs = cur_state;                  
endmodule
