module mips (
        input  wire        clk,
        input  wire        rst,
        input  wire [4:0]  ra3,
        input  wire [31:0] instr,
        input  wire [31:0] rd_dm,
        output wire        we_dm,
        output wire [31:0] pc_current,
        output wire [31:0] alu_shift_out,
        output wire [31:0] wd_dm,
        output wire [31:0] rd3
    );
    
    wire       branch;
    wire       jump;
    wire       reg_dst;
    wire       we_reg;
    wire       alu_src;
    wire       dm2reg;
    
    wire [2:0] alu_ctrl;
    
    wire        HILO_we;
    wire        HI_LO_mux_en;
    wire        alu_HILO_mux_en;
    wire        jra;
    wire        jal;
    wire        lr_sel;
    wire        shift_sel;

    datapath dp (
            .clk                (clk),
            .rst                (rst),
            .branch             (branch),
            .jump               (jump),
            .reg_dst            (reg_dst),
            .we_reg             (we_reg),
            .alu_src            (alu_src),
            .dm2reg             (dm2reg),
            .jal                (jal),
            .alu_ctrl           (alu_ctrl),
            .HILO_we            (HILO_we),
            .HI_LO_mux_en       (HI_LO_mux_en),
            .alu_HILO_mux_en    (alu_HILO_mux_en),
            .jra                (jra),
            .lr_sel             (lr_sel),
            .shift_sel          (shift_sel),
            .ra3                (ra3),
            .instr              (instr),
            .rd_dm              (rd_dm),
            .pc_current         (pc_current),
            .alu_shift_out      (alu_shift_out),
            .wd_dm              (wd_dm),
            .rd3                (rd3)
        );

    controlunit cu (
            .opcode             (instr[31:26]),
            .funct              (instr[5:0]),
            .branch             (branch),
            .jump               (jump),
            .reg_dst            (reg_dst),
            .we_reg             (we_reg),
            .alu_src            (alu_src),
            .we_dm              (we_dm),
            .dm2reg             (dm2reg),
            .jal                (jal),
            .alu_ctrl           (alu_ctrl),
            .HILO_we            (HILO_we),
            .HI_LO_mux_en       (HI_LO_mux_en),
            .alu_HILO_mux_en    (alu_HILO_mux_en),
            .jra                (jra),
            .lr_sel             (lr_sel),
            .shift_sel          (shift_sel)
        );

endmodule