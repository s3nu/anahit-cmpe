module gpio_output_mux #(parameter w = 32) (
		input  wire [1:0]		RdSel,
		input  wire [w-1:0]		gpI1,
		input  wire [w-1:0]		gpI2,
		input  wire [w-1:0]		gpO1,
		input  wire [w-1:0]		gpO2,
		output reg  [w-1:0]		RD
	);
	
	always @ (*) begin
		case (RdSel)
			2'b00:    RD = gpI1;
			2'b01:    RD = gpI2;
			2'b10:    RD = gpO1;
			2'b11:    RD = gpO2;
			default:  RD = {32{1'bx}};
		endcase
	end
endmodule