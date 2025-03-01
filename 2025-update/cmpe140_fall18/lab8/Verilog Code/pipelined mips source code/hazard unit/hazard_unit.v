module hazard_unit(
    input wire clk,
    input wire [31:0] instr_d,
    input wire [31:0] instr_e,
    input wire [4:0]  rf_wa_e,
    input wire [4:0]  rf_wa_m,
    input wire [4:0]  rf_wa_w,
    input wire we_reg_e,
    input wire we_reg_m,
    input wire we_reg_w,
    input wire branch_d,
    input wire dm2reg_m,
    input wire jal,
    output reg stall_f,
    output reg stall_d,
    output reg clr_e,
    output reg fwd_ad,
    output reg fwd_bd,
    output reg [1:0] fwd_ae,
    output reg [1:0] fwd_be   
    );
    
    wire rsD, rtD, rsE, rtE; 
    reg lwstall, branchstall;
    
    assign rsD = instr_d[25:21];
    assign rtD = instr_d[20:16];
    assign rsE = instr_e[25:21];
    assign rtE = instr_e[20:16];
    
    initial begin
        stall_f = 1'b0;
        stall_d = 1'b0;
        clr_e = 1'b0;
    end
    
    always @(posedge clk) begin
        if ((rsE) & (rsE == rf_wa_m) & we_reg_m)
            fwd_ae = 2'b10;
        else if((rsE) & (rsE == rf_wa_w) & we_reg_w)
            fwd_ae = 2'b01;
        else
            fwd_ae = 2'b00;
        
        if ((rtE) & (rtE == rf_wa_m) & we_reg_m)
            fwd_be = 2'b10;
        else if((rtE) & (rtE == rf_wa_w) & we_reg_w)
            fwd_be = 2'b01;
        else
            fwd_be = 2'b00; 
        
        fwd_ad = ((rsD) & (rsD == rf_wa_m) & we_reg_m);
        fwd_bd = ((rtD) & (rtD == rf_wa_m) & we_reg_m);
                
        
        lwstall = (((rsD == rtE) | (rtD == rtE)) & we_reg_e & !jal & !(instr_d == 32'b0 & instr_e == 32'b0) & !(instr_d[31:26] == 6'b10_1011));
        branchstall = ((branch_d & we_reg_e & ((rf_wa_e == rsD) | (rf_wa_e == rtD))) |
                       (branch_d & dm2reg_m &((rf_wa_m == rsD) | (rf_wa_m == rsD))));
        stall_f = lwstall | branchstall;
        stall_d = lwstall | branchstall;
        clr_e = lwstall | branchstall;
        
    end
endmodule
