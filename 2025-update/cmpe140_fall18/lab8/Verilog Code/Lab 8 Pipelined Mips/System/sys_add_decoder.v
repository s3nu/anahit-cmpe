module sys_add_decoder (
    input wire [31:0] addr,
    input wire we,
    output reg we1, we2, wem,
    output reg [1:0] RdSel
    );
    
    always @(*) begin
		if(addr >= 32'h00000000 && addr <= 32'h000000FC && we)
        begin
			wem = 1'b1;
			we1 = 1'b0;
			we2 = 1'b0;
			RdSel = 2'b00;
		end
		else if(addr >= 32'h00000800 && addr <= 32'h0000080C && we)
		begin
			wem = 1'b0;
			we1 = 1'b1;
			we2 = 1'b0;
			RdSel = 2'b10;
        end
		else if(addr >= 32'h00000900 && addr <= 32'h0000090C && we)
		begin
			wem = 1'b0;
			we1 = 1'b0;
			we2 = 1'b1;
			RdSel = 2'b11;
        end
        else if(addr >= 32'h00000000 && addr <= 32'h000000FC && !we)
        begin
            wem = 1'b0;
            we1 = 1'b0;
            we2 = 1'b0;
            RdSel = 2'b00;
        end
        else if(addr >= 32'h00000800 && addr <= 32'h0000080C && !we)
        begin
            wem = 1'b0;
            we1 = 1'b0;
            we2 = 1'b0;
            RdSel = 2'b10;
        end
        else if(addr >= 32'h00000900 && addr <= 32'h0000090C && !we)
        begin
            wem = 1'b0;
            we1 = 1'b0;
            we2 = 1'b0;
            RdSel = 2'b11;
        end
    end            
endmodule
