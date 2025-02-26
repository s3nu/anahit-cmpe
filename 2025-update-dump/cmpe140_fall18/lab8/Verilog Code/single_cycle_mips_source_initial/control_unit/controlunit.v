module controlunit (
        input  wire [5:0]  opcode,
        input  wire [5:0]  funct,
        output wire        branch,
        output wire        jump,
        output wire        reg_dst,
        output wire        we_reg,
        output wire        alu_src,
        output wire        we_dm,
        output wire        dm2reg,
        output wire        jal,
        output wire [2:0]  alu_ctrl,
        output wire        HILO_we,
        output wire        HI_LO_mux_en,
        output wire        alu_HILO_mux_en,
        output wire        jra,
        output wire        lr_sel,
        output wire        shift_sel
    );
    
    wire [1:0] alu_op;

    maindec md (
        .opcode         (opcode),
        .branch         (branch),
        .jump           (jump),
        .reg_dst        (reg_dst),
        .we_reg         (we_reg),
        .alu_src        (alu_src),
        .we_dm          (we_dm),
        .dm2reg         (dm2reg),
        .jal            (jal),
        .alu_op         (alu_op)
    );

    auxdec ad (
        .alu_op           (alu_op),
        .funct            (funct),
        .alu_ctrl         (alu_ctrl),
        .HILO_we          (HILO_we),
        .HI_LO_mux_en     (HI_LO_mux_en),
        .alu_HILO_mux_en  (alu_HILO_mux_en),
        .jra              (jra),
        .lr_sel           (lr_sel),
        .shift_sel        (shift_sel)
    );

endmodule