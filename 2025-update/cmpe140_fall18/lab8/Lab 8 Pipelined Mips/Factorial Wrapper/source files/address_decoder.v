`timescale 1ns / 1ps


module address_decoder (
    input wire [1:0] addr,
    input wire we,
    output reg we1, we2,
    output reg [1:0] RdSel
    );
    
    always @(*) begin
        case(addr)
            2'b00: begin
                   we1 = 1'b1;
                   we2 = 1'b0;
                   RdSel = 2'b00;
                   end
            2'b01: begin
                   we1 = 1'b0;
                   we2 = 1'b1;
                   RdSel = 2'b01;
                   end
            2'b10: begin
                   we1 = 1'b0;
                   we2 = 1'b0;
                   RdSel = 2'b10;
                   end
            2'b11: begin
                   we1 = 1'b0;
                   we2 = 1'b0;
                   RdSel = 2'b11;
                   end
        endcase
        
    end            
endmodule
