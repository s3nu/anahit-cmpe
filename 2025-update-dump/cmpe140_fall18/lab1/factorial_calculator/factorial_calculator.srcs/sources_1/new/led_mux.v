module led_mux
    (
    input wire clk,
    input wire [7:0] LED7, LED6, LED5, LED4, LED3, LED2, LED1, LED0,
    output wire [7:0] LEDSEL, LEDOUT
    );
    
    reg [2:0] index;
    reg [15:0] led_ctrl;
    
    assign {LEDSEL, LEDOUT} = led_ctrl;
    
    /*always @(posedge clk) 
        index <= (rst) ? 3'b0 : (index + 3'd1);*/
        
    always @(index, LED7, LED6, LED5, LED4, LED3, LED2, LED1, LED0) begin
        case (index)
            0:          led_ctrl <= {8'b1111_1110, LED0};
            1:          led_ctrl <= {8'b1111_1101, LED1};
            2:          led_ctrl <= {8'b1111_1011, LED2};
            3:          led_ctrl <= {8'b1111_0111, LED3};
            4:          led_ctrl <= {8'b1110_1111, LED4};
            5:          led_ctrl <= {8'b1101_1111, LED5};
            6:          led_ctrl <= {8'b1011_1111, LED6};
            7:          led_ctrl <= {8'b0111_1111, LED7};
            default:    led_ctrl <= {8'b1111_1111, 8'hF};
        endcase
    end
endmodule
            