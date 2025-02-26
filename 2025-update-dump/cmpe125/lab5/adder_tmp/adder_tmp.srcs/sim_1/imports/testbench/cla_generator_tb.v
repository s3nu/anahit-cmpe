module CLA_GENERATOR_TB;
  reg [3:0] P_tb, G_tb;
  reg Cin_tb;
  wire [3:0] C_tb;
  wire Cout_tb;

  integer M, N, J;

  CLA_GENERATOR DUT (
    .P(P_tb), .G(G_tb), .Cin(Cin_tb),
    .C(C_tb), .Cout(Cout_tb)
  );

initial begin
  for(J = 0; J < 2; J = J + 1) begin
    Cin_tb = J; //Iterate all combinations
    for(M = 0; M <16; M = M + 1) begin
      P_tb = M;
      for(N = 0; N <16; N = N + 1) begin
        G_tb = N; #1;
        $display("P (Sum): %b, G (Carry): %b, Cin: %b, Cout: %b, C: %b\n",
        P_tb, G_tb, Cin_tb, C_tb, Cout_tb);
        if(C_tb[0] != Cin_tb)
          $display("C[0] Failed\n");
        if(C_tb[1] != (G_tb[0] | P_tb[0] & C[0])
          $display("C[1] Failed\n");
        if(C_tb[2] != (G_tb[1] | P_tb[1] & C[1]))
          $display("C[2] Failed\\n");
        if(C_tb[3] != (G_tb[2] | P_tb[2] & C[2]))
          $display("C[3] Failed\\n");
        if(Cout_tb != (G_tb[3] | P_tb[3] & C[3]))
          $display("Cout Failed\\n");
      end //close for-loop G_tb
    end //close for-loop P_tb
  end //close for-loop Cin_tb
  #1; $display("Simulation Finished.\n");
  $finish;
end //close initial block

endmodule
