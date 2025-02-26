module sys_output_mux #(parameter w = 32) (
		input  wire [1:0]		RdSel,
		input  wire [w-1:0]		DMemData,
		input  wire [w-1:0]		FactData,
		input  wire [w-1:0]		GPIOData,
		output reg  [w-1:0]		ReadData
	);
	
	always @ (*) begin
		case (RdSel)
			2'b00:    ReadData = DMemData;
			2'b01:    ReadData = DMemData;
			2'b10:    ReadData = FactData;
			2'b11:    ReadData = GPIOData;
			default:  ReadData = {32{1'bx}};
		endcase
	end
endmodule