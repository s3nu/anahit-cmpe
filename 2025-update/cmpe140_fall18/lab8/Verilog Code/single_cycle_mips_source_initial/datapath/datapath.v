module datapath (
        input  wire        clk,
        input  wire        rst,
        input  wire        branch,
        input  wire        jump,
        input  wire        reg_dst,
        input  wire        we_reg,
        input  wire        alu_src,
        input  wire        dm2reg,
        input  wire        jal,
        input  wire [2:0]  alu_ctrl,
        input  wire        HILO_we,
        input  wire        HI_LO_mux_en,
        input  wire        alu_HILO_mux_en,
        input  wire        jra,
        input  wire        lr_sel,
        input  wire        shift_sel,
        input  wire [4:0]  ra3,
        input  wire [31:0] instr,
        input  wire [31:0] rd_dm,
        output wire [31:0] pc_current,
        output wire [31:0] alu_shift_out,
        output wire [31:0] wd_dm,
        output wire [31:0] rd3
    );

    wire [4:0]  rf_wa;
    wire        pc_src;
    wire [31:0] pc_plus4;
    wire [31:0] pc_pre;
    wire [31:0] pc_next;
    wire [31:0] sext_imm;
    wire [31:0] ba;
    wire [31:0] bta;
    wire [31:0] jta;
    wire [31:0] alu_pa;
    wire [31:0] alu_pb;
    wire [31:0] wd_rf;
    wire        zero;
    
    wire [63:0] mult_out;
    wire [31:0] hi_reg_out;
    wire [31:0] lo_reg_out;
    wire [31:0] hilo_mux_out;
    wire [31:0] alu_hilo_mux_out;
    wire [31:0] wd_jal_rf;
    wire [4:0]  rf_jal_wa;
    wire [31:0] alu_out;
    wire [31:0] pc_next_jra;
    wire [31:0] shift_out;
    
    assign pc_src = branch & zero;
    assign ba = {sext_imm[29:0], 2'b00};
    assign jta = {pc_plus4[31:28], instr[25:0], 2'b00};
    
    // --- PC Logic --- //
    dreg pc_reg (
            .clk            (clk),
            .rst            (rst),
            .d              (pc_next_jra),
            .q              (pc_current)
        );

    adder pc_plus_4 (
            .a              (pc_current),
            .b              (32'd4),
            .y              (pc_plus4)
        );

    adder pc_plus_br (
            .a              (pc_plus4),
            .b              (ba),
            .y              (bta)
        );

    mux2 #(32) pc_src_mux (
            .sel            (pc_src),
            .a              (pc_plus4),
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
            .b              (alu_pa),
            .y              (pc_next_jra)
        );

    // --- RF Logic --- //
    mux2 #(5) rf_wa_mux (
            .sel            (reg_dst),
            .a              (instr[20:16]),
            .b              (instr[15:11]),
            .y              (rf_wa)
        );
    
    mux2 #(5) jal_mux (
            .sel            (jal),
            .a              (rf_wa),
            .b              (5'b11111),
            .y              (rf_jal_wa)
        );
    
    regfile rf (
            .clk            (clk),
            .we             (we_reg),
            .ra1            (instr[25:21]),
            .ra2            (instr[20:16]),
            .ra3            (ra3),
            .wa             (rf_jal_wa),
            .wd             (wd_jal_rf),
            .rd1            (alu_pa),
            .rd2            (wd_dm),
            .rd3            (rd3)
        );

    signext se (
            .a              (instr[15:0]),
            .y              (sext_imm)
        );

    // --- ALU Logic --- //
    mux2 #(32) alu_pb_mux (
            .sel            (alu_src),
            .a              (wd_dm),
            .b              (sext_imm),
            .y              (alu_pb)
        );

    alu alu (
            .op             (alu_ctrl),
            .a              (alu_pa),
            .b              (alu_pb),
            .zero           (zero),
            .y              (alu_out)
        );
        
    mux2 #(32) alu_shift_mux (
            .sel            (shift_sel),
            .a              (alu_out),
            .b              (shift_out),
            .y              (alu_shift_out)
        );
        
    mult #(32) multiplier (
            .a              (wd_dm),
            .b              (alu_pa),
            .y              (mult_out)
        );
        
    dreg_en #(32) HI_reg (
            .clk            (clk),
            .rst            (rst),
            .en             (HILO_we),
            .d              (mult_out[63:32]),
            .q              (hi_reg_out)
        );
        
    dreg_en #(32) LO_reg (
            .clk            (clk),
            .rst            (rst),
            .en             (HILO_we),
            .d              (mult_out[31:0]),
            .q              (lo_reg_out)
        );
        
    mux2 #(32) HI_LO_mux (
            .sel            (HI_LO_mux_en),
            .a              (hi_reg_out),
            .b              (lo_reg_out),
            .y              (hilo_mux_out)
        );
        
    shifter #(32) shift (
            .a              (lr_sel),
            .b              (wd_dm),
            .c              (instr[10:6]),
            .y              (shift_out)
        );

    // --- MEM Logic --- //
    mux2 #(32) rf_wd_mux (
            .sel            (dm2reg),
            .a              (alu_shift_out),
            .b              (rd_dm),
            .y              (wd_rf)
        );
        
    mux2 #(32) alu_HILO_mux (
            .sel            (alu_HILO_mux_en),
            .a              (hilo_mux_out),
            .b              (wd_rf),
            .y              (alu_hilo_mux_out)
        );
        
    mux2 #(32) wd_jal_mux (
            .sel            (jal),
            .a              (alu_hilo_mux_out),
            .b              (pc_plus4),
            .y              (wd_jal_rf)
        );

endmodule