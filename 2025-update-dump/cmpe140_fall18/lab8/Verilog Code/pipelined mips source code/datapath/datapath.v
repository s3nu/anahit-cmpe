module datapath (
        input  wire        clk,
        input  wire        rst,
        input  wire        branch_d,
        input  wire [1:0]  jump_d,
        input  wire        reg_dst_d,
        input  wire        we_reg_d,
        input  wire        alu_src_d,
        input  wire        dm2reg_d,
        input  wire        jal_d,
        input  wire [2:0]  alu_ctrl_d,
        input  wire        HILO_we_d,
//        input  wire        HI_LO_mux_en,
//        input  wire        alu_HILO_mux_en,
        input  wire        jra_d,
        input  wire        lr_sel_d,
        input  wire        shift_sel_d,
        input  wire        mem_we_d, 
        input  wire        stall_f,
        input  wire        stall_d,
        input  wire        clr_e, 
        input  wire [1:0]  Jal_Mult_DM_d,
        input  wire        fwd_ad,
        input  wire        fwd_bd,
        input  wire [1:0]  fwd_ae,
        input  wire [1:0]  fwd_be,
        input  wire [4:0]  ra3,
        input  wire [31:0] rd_dm_m,
        input  wire [31:0] instr_f,
        output wire [31:0] instr_d,
        output wire [31:0] instr_e,
        output wire [31:0] pc_current_f,
        output wire [31:0] alu_shift_out,
        output wire [31:0] wd_dm_mux_out_m,
        output wire [31:0] rd3,
        output wire [4:0] rf_wa_e,
        output wire [4:0] rf_wa_m,
        output wire [4:0] rf_wa_w,
        output wire we_reg_e,
        output wire we_reg_m,
        output wire we_reg_w,
        output wire mem_we_m,
        output wire dm2reg_m
    );
    
    wire lr_sel_e;
    wire [1:0] Jal_Mult_DM_e, Jal_Mult_DM_m, Jal_Mult_DM_w;
    wire reg_dst_e;
    wire [1:0] jump_e;
    wire jal_e;
    wire shift_sel_e;
    wire dm2reg_e;
    wire mem_we_e;
    wire alu_src_e;
    wire HILO_we_e;
    wire [2:0] alu_ctrl_e;
    
    wire dm2reg_w;
    
    wire        pc_src_d;
    wire [31:0] pc_plus4_f;
    wire [31:0] pc_plus4_d;
    wire [31:0] pc_pre;
    wire [31:0] pc_next;
    wire [31:0] sext_imm_d;
    wire [31:0] sext_imm_e;
    wire [31:0] ba;
    wire [31:0] bta;
    wire [31:0] jta_d, jta_e;
    wire [31:0] alu_pa_d;
    wire [31:0] alu_pa_e;
    wire [31:0] alu_pb_e;
    wire [31:0] rd_dm_w;
    wire        zero;
    
    wire [31:0] rd1_out_d;
    wire [31:0] rd1_out_e;
    wire [31:0] rd2_out_d;
    wire [31:0] rd2_out_e;
    
    wire [31:0] wd_dm_d;
    wire [31:0] wd_dm_e;
    
    wire [31:0] wd_rf_w;    
    wire [31:0] wd_rf_mid;
    wire [31:0] wd_rf_final;
//    wire [31:0] wd_mux_out_e;
//    wire [31:0] wd_mux_out_w;

    wire [31:0] rd1_mux_out;
    wire [31:0] rd2_mux_out;
    
    wire [63:0] mult_out;
    wire [31:0] hi_reg_out_e;
    wire [31:0] lo_reg_out_e;
    wire [31:0] hi_reg_out_m;
    wire [31:0] lo_reg_out_m;
    wire [31:0] hilo_mux_out;
    wire [31:0] alu_hilo_mux_out;
    wire [31:0] alu_pa_mux_out_e;
    wire [31:0] wd_dm_mux_out_e;
    wire [31:0] wd_jal_rf_d;
    wire [4:0]  rf_jal_wa_w;
    wire [31:0] alu_out_e;
    wire [31:0] alu_out_m;
    wire [31:0] alu_out_w;
    wire [31:0] alu_out_f;
    wire [31:0] pc_next_jra_w;
    wire [31:0] shift_out_e;
    wire [31:0] shift_out_m;
    
    wire compare_val = (rd1_mux_out == rd2_mux_out) ? 1:0;
    
    assign pc_src_d = branch_d & compare_val;
    assign ba = {sext_imm_d[29:0], 2'b00};
    assign jta_d = {pc_plus4_d[31:28], instr_d[25:0], 2'b00};
    
    // --- PC Logic --- //
    stage_dreg pc_reg (
            .clk            (clk),
            .rst            (rst),
            .en             (stall_f),
            .d              (pc_next),
            .q              (pc_current_f)
        );

    adder pc_plus_4 (
            .a              (pc_current_f),
            .b              (32'd4),
            .y              (pc_plus4_f)
        );

    adder pc_plus_br (
            .a              (pc_plus4_f),
            .b              (ba),
            .y              (bta)
        );

    mux2 #(32) pc_src_mux_primary (
            .sel            (pc_src_d),
            .a              (pc_plus4_f),
            .b              (ba + pc_plus4_d),
            .y              (pc_pre)
        );
        
    mux4 #(32) pc_src_mux_final (
            .sel            (jump_e),
            .a              (pc_pre),
            .b              (jta_e),
            .c              (alu_pa_mux_out_e),
            .d              (32'b0),
            .out            (pc_next)
        );
/*
    mux2 #(32) pc_src_mux (
            .sel            (pc_src),
            .a              (pc_plus4_f),
            .b              (bta),
            .y              (pc_pre)
        );

    mux2 #(32) pc_jmp_mux (
            .sel            (jump),
            .a              (pc_pre),
            .b              (jta),
            .y              (pc_next)
        );
       
    mux2 #(32) pc_jr_mux (
            .sel            (jra),
            .a              (pc_next),
            .b              (alu_pa_e),
            .y              (pc_next_jra_w)
        );
*/
    // --- RF Logic --- //
    mux4 #(5) rf_wa_mux (
            .sel            ({jal_e, reg_dst_e}),
            .a              (instr_d[20:16]),
            .b              (instr_d[15:11]),
            .c              (5'b11111),
            .d              (5'b0),
            .out            (rf_wa_e)
        );
    
    /*mux2 #(5) jal_mux (
            .sel            (jal),
            .a              (rf_wa_w),
            .b              (5'b11111),
            .y              (rf_jal_wa_w)
        );
    */
    
    mux4 #(32) wd_rf_mux_mid (
            .sel            (Jal_Mult_DM_w),
            .a              (wd_rf_w),
            .b              (hi_reg_out_m),
            .c              (lo_reg_out_m),
            .d              (pc_plus4_d),
            .out            (wd_rf_mid)
        );
        
    mux2 #(32) wd_rf_mux_final (
            .sel            (shift_sel_e),
            .a              (wd_rf_mid),
            .b              (shift_out_m),
            .y              (wd_rf_final)
        );
        
    regfile rf (
            .clk            (clk),
            .we             (we_reg_w),
            .ra1            (instr_d[25:21]),
            .ra2            (instr_d[20:16]),
            .ra3            (ra3),
            .wa             (rf_wa_w),
            .wd             (wd_rf_final),
            .rd1            (alu_pa_d),
            .rd2            (wd_dm_d),
            .rd3            (rd3)
        );

    mux2 #(32) rd1_mux (
            .sel            (fwd_ad),
            .a              (alu_pa_d),
            .b              (alu_out_m),
            .y              (rd1_mux_out)
        );
    
    mux2 #(32) rd2_mux (
            .sel            (fwd_bd),
            .a              (wd_dm_d),
            .b              (alu_out_m),
            .y              (rd2_mux_out)
        );

    signext se (
            .a              (instr_d[15:0]),
            .y              (sext_imm_d)
        );

    // --- ALU Logic --- //
    mux2 #(32) alu_pb_mux (
            .sel            (alu_src_e),
            .a              (wd_dm_mux_out_e),
            .b              (sext_imm_e),
            .y              (alu_pb_e)
        );

    mux4 #(32) wd_dm_mux (
            .sel            (fwd_be),
            .a              (wd_dm_e),
            .b              (wd_rf_w),
            .c              (alu_out_m),
            .d              (32'b0),
            .out            (wd_dm_mux_out_e)
        );

    mux4 #(32) alu_pa_mux (
            .sel            (fwd_ae),
            .a              (alu_pa_e),
            .b              (wd_rf_w),
            .c              (alu_out_m),
            .d              (32'b0),
            .out            (alu_pa_mux_out_e)
        );

    alu alu (
            .op             (alu_ctrl_e),
            .a              (alu_pa_mux_out_e),
            .b              (alu_pb_e),
            .zero           (zero),
            .y              (alu_out_e)
        );
/*        
    mux2 #(32) alu_shift_mux (
            .sel            (shift_sel),
            .a              (alu_out_w),
            .b              (shift_out_e),
            .y              (alu_shift_out)
        );
*/        
    mult #(32) multiplier (
            .a              (wd_dm_mux_out_e),
            .b              (alu_pa_mux_out_e),
            .y              (mult_out)
        );
        
    dreg_en #(32) HI_reg (
            .clk            (clk),
            .rst            (rst),
            .en             (HILO_we_e),
            .d              (mult_out[63:32]),
            .q              (hi_reg_out_e)
        );
        
    dreg_en #(32) LO_reg (
            .clk            (clk),
            .rst            (rst),
            .en             (HILO_we_e),
            .d              (mult_out[31:0]),
            .q              (lo_reg_out_e)
        );
/*        
    mux2 #(32) HI_LO_mux (
            .sel            (HI_LO_mux_en),
            .a              (hi_reg_out_m),
            .b              (lo_reg_out_m),
            .y              (hilo_mux_out)
        );
*/        
    shifter #(32) shift (
            .a              (lr_sel_e),
            .b              (wd_dm_mux_out_e),
            .c              (instr_e[10:6]),
            .y              (shift_out_e)
        );

    // --- MEM Logic --- //
    mux2 #(32) wd_rf_mux_primary (
            .sel            (dm2reg_w),
            .a              (alu_out_w),
            .b              (rd_dm_w),
            .y              (wd_rf_w)
        );
/*        
    mux2 #(32) alu_HILO_mux (
            .sel            (alu_HILO_mux_en),
            .a              (hilo_mux_out),
            .b              (wd_rf_mux_out_d),
            .y              (alu_hilo_mux_out)
        );

    mux2 #(32) wd_jal_mux (
            .sel            (jal),
            .a              (alu_hilo_mux_out),
            .b              (pc_plus4_d),
            .y              (wd_jal_rf)
        );
 */       
    // --- Stage Logic --- //
    stage_dreg #(64) decode_reg (
            .clk            (clk),
            .rst            (rst),
            .en             (stall_d),
            .d              ({instr_f, pc_plus4_f}),
            .q              ({instr_d, pc_plus4_d})
        );
    
    stage_dreg #(208) execute_reg (
            .clk            (clk),
            .rst            (clr_e | rst),
            .en             (1'b0),
            .d              ({Jal_Mult_DM_d, 
                              jump_d,
                              jta_d,
                              shift_sel_d,
                              jal_d, 
                              we_reg_d, 
                              dm2reg_d, 
                              mem_we_d,
                              reg_dst_d,
                              lr_sel_d,
                              alu_pa_d,
                              alu_src_d,
                              alu_ctrl_d,
                              HILO_we_d,
                              rd1_out_d, 
                              rd2_out_d, 
                              sext_imm_d, 
                              instr_d}),
            .q              ({Jal_Mult_DM_e, 
                              jump_e,
                              jta_e,
                              shift_sel_e,
                              jal_e, 
                              we_reg_e, 
                              dm2reg_e, 
                              mem_we_e,
                              reg_dst_e,
                              lr_sel_e,
                              alu_pa_e,
                              alu_src_e,
                              alu_ctrl_e,
                              HILO_we_e,
                              rd1_out_e, 
                              rd2_out_e, 
                              sext_imm_e, 
                              instr_e}) 
        );
        
    stage_dreg #(170) memory_reg (
            .clk            (clk),
            .rst            (rst),
            .en             (1'b0),
            .d              ({we_reg_e,
                              dm2reg_e,
                              mem_we_e,
                              alu_out_e, 
                              wd_dm_mux_out_e,
                              Jal_Mult_DM_e, 
                              rf_wa_e, 
                              hi_reg_out_e, 
                              lo_reg_out_e, 
                              shift_out_e}),
            .q              ({we_reg_m, 
                              dm2reg_m,
                              mem_we_m,
                              alu_out_m, 
                              wd_dm_mux_out_m,
                              Jal_Mult_DM_m, 
                              rf_wa_m, 
                              hi_reg_out_m, 
                              lo_reg_out_m, 
                              shift_out_m})
        );
        
    stage_dreg #(73) writeback_reg (
            .clk            (clk),
            .rst            (rst),
            .en             (1'b0),
            .d              ({Jal_Mult_DM_m, we_reg_m, dm2reg_m, alu_out_m, rd_dm_m, rf_wa_m}),
            .q              ({Jal_Mult_DM_w, we_reg_w, dm2reg_w, alu_out_w, rd_dm_w, rf_wa_w})
        );
endmodule