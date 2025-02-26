module decoder_for (A,Y, Valid);
input [7:0] A;
output reg [2:0] Y;
output reg Valid;
integer N;
always @ (A)
    begin
    Valid = 0;
    Y = 3'bx;
    for (N = 0; N < 8; N = N + 1)
    if (A[N])
    begin
    Valid = 1;
    Y = N;
end
end
endmodule