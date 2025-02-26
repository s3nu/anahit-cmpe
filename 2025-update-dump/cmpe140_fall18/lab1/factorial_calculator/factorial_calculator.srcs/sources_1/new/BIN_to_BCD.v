module BIN_to_BCD( 
    input wire [31:0] value, 
    output wire [3:0] dig0, 
    output wire [3:0] dig1, 
    output wire [3:0] dig2, 
    output wire [3:0] dig3, 
    output wire [3:0] dig4, 
    output wire [3:0] dig5, 
    output wire [3:0] dig6, 
    output wire [3:0] dig7 
    ); 
    assign dig0 = value % 10; 
    assign dig1 = (value / 10) % 10; 
    assign dig2 = (value / 100) % 10; 
    assign dig3 = (value / 1000) % 10; 
    assign dig4 = (value / 10000) % 10; 
    assign dig5 = (value / 100000) % 10; 
    assign dig6 = (value / 1000000) % 10; 
    assign dig7 = (value / 10000000) % 
10; 
endmodule     