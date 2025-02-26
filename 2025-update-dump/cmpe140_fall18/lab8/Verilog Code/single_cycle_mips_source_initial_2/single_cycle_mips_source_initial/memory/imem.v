module imem (
        input  wire [5:0]  a,
        output wire [31:0] y
    );

    reg [31:0] rom [0:63];

    initial begin
        $readmemh ("C:/Users/Ryan/Documents/SJSU School Work/Fall 2018/CMPE 140/Verilog Code/single_cycle_mips_source_initial_2/single_cycle_mips_source_initial/test_memfile.dat", rom);
    end

    assign y = rom[a];
    
endmodule