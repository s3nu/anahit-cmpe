module mips (
        input  wire        clk,
        input  wire        rst,
        input  wire [4:0]  ra3,
        input  wire [31:0] instr_f,
        input  wire [31:0] rd_dm_m,
        output wire        we_dm,
        output wire [31:0] pc_current_f,
        output wire [31:0] alu_shift_out,
        output wire [31:0] wd_dm,
        output wire [31:0] rd3
    );
    
    wire       branch_d;
    wire [1:0] jump_d;
    wire       reg_dst_d;
    wire       we_reg_d;
    wire       alu_src_d;
    wire       dm2reg_d, dm2reg_m;
    
    wire [2:0] alu_ctrl_d;
    
    wire        HILO_we_d;
    wire        HI_LO_mux_en;
    wire        alu_HILO_mux_en;
    wire        jra_d;
    wire        jal;
    wire        lr_sel_d;
    wire        shift_sel_d;
    wire [1:0]  Jal_Mult_DM_d;
    wire [31:0] instr_d, instr_e;
    wire [4:0]  rf_wa_e, rf_wa_m, rf_wa_w;
    wire        stall_f, stall_d, clr_e;
    wire        fwd_ad, fwd_bd;
    wire [1:0]  fwd_ae, fwd_be;
    wire        we_reg_e, we_reg_m, we_reg_w;
    wire        we_dm_m;


    datapath dp (
            .clk                (clk),
            .rst                (rst),
            .branch_d           (branch_d),
            .jump_d             (jump_d),
            .reg_dst_d          (reg_dst_d),
            .we_reg_d           (we_reg_d),
            .alu_src_d          (alu_src_d),
            .dm2reg_d           (dm2reg_d),
            .jal_d              (jal),
            .alu_ctrl_d         (alu_ctrl_d),
            .HILO_we_d          (HILO_we_d),
            .jra_d              (jra_d),
            .lr_sel_d           (lr_sel_d),
            .shift_sel_d        (shift_sel_d),
            .mem_we_d           (we_dm), 
            .stall_f            (stall_f),
            .stall_d            (stall_d),
            .clr_e              (clr_e), 
            .Jal_Mult_DM_d      (Jal_Mult_DM_d),
            .fwd_ad             (fwd_ad),
            .fwd_bd             (fwd_bd),
            .fwd_ae             (fwd_ae),
            .fwd_be             (fwd_be),
            .ra3                (ra3),
            .rd_dm_m            (rd_dm_m),
            .instr_f            (instr_f),
            .instr_d            (instr_d),
            .instr_e            (instr_e),
            .pc_current_f       (pc_current_f),
            .alu_shift_out      (alu_shift_out),
            .wd_dm_mux_out_m    (wd_dm),
            .rd3                (rd3),
            .rf_wa_e            (rf_wa_e),
            .rf_wa_m            (rf_wa_m),
            .rf_wa_w            (rf_wa_w),
            .we_reg_e           (we_reg_e),
            .we_reg_m           (we_reg_m),      
            .we_reg_w           (we_reg_w),
            .mem_we_m           (we_dm_m),
            .dm2reg_m           (dm2reg_m)
        );

    controlunit cu (
            .opcode             (instr_d[31:26]),
            .funct              (instr_d[5:0]),
            .branch             (branch_d),
            .jump               (jump_d),
            .reg_dst            (reg_dst_d),
            .we_reg             (we_reg_d),
            .alu_src            (alu_src_d),
            .we_dm              (we_dm),
            .dm2reg             (dm2reg_d),
            .jal                (jal),
            .alu_ctrl           (alu_ctrl_d),
            .HILO_we            (HILO_we_d),
            .lr_sel             (lr_sel_d),
            .shift_sel          (shift_sel_d),
            .Jal_Mult_DM        (Jal_Mult_DM_d)
        );

    hazard_unit hu (
            .clk                (clk),
            .instr_d            (instr_d),
            .instr_e            (instr_e),
            .rf_wa_e            (rf_wa_e),
            .rf_wa_m            (rf_wa_m),
            .rf_wa_w            (rf_wa_w),
            .we_reg_e           (we_reg_e),
            .we_reg_m           (we_reg_m),
            .we_reg_w           (we_reg_w),
            .branch_d           (branch_d),
            .dm2reg_m           (dm2reg_m),
            .jal                (jal),
            .stall_f            (stall_f),
            .stall_d            (stall_d),
            .clr_e              (clr_e),
            .fwd_ad             (fwd_ad),
            .fwd_bd             (fwd_bd),
            .fwd_ae             (fwd_ae),
            .fwd_be             (fwd_be)
        );
endmodule