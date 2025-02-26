module decoder_if (A,Y, Valid);
input [7:0] A;
output reg [2:0] Y;
output reg Valid;
always@(A)
begin
Valid = 1;
if (A[7]) Y = 7; // same as Y = (A[7] = = 1) ? Y = 7:
    else if (A[6]) Y = 6; // (A[6] = = 1) ? Y = 6:
    else if (A[5]) Y = 5; // (A[5] = = 1) ? Y = 5:
    else if (A[4]) Y = 4; // (A[4] = = 1) ? Y = 4:
    else if (A[3]) Y = 3; // (A[3] = = 1) ? Y = 3:
    else if (A[2]) Y = 2; // (A[2] = = 1) ? Y = 2:
    else if (A[1]) Y = 1; // (A[1] = = 1) ? Y = 1:
    else if (A[0]) Y = 0; // 0;
else
    begin
    Valid = 0;
    Y = 3'bx;
    end
end
endmodule