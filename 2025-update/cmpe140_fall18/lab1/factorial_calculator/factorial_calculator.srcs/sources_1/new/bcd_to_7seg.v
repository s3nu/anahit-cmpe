

module bcd_to_7seg
    (
    input [3:0] BCD,
    output reg [7:0] s
    );
    
    always @(BCD) begin
        case (BCD)
            0:          s = 8'b1000_1000;
            1:          s = 8'b1110_1101;
            2:          s = 8'b1010_0010;
            3:          s = 8'b1010_0100;
            4:          s = 8'b1100_0101;
            5:          s = 8'b1001_0100;
            6:          s = 8'b1001_0000;
            7:          s = 8'b1010_1101;
            8:          s = 8'b1000_0000;
            9:          s = 8'b1000_0100;
            default:    s = 8'b0111_1111;
        endcase
    end
endmodule
