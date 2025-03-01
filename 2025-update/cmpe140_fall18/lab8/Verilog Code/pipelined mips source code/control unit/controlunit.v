module controlunit (
        input  wire [5:0]  opcode,
        input  wire [5:0]  funct,
        output wire        branch,
        output wire [1:0]  jump,
        output wire        reg_dst,
        output wire        we_reg,
        output wire        alu_src,
        output wire        we_dm,
        output wire        dm2reg,
        output wire        jal,
        output wire [2:0]  alu_ctrl,
        output wire        HILO_we,
//        output wire        HI_LO_mux_en,
//        output wire        alu_HILO_mux_en,
//        output wire        jra,
        output wire        lr_sel,
        output reg        shift_sel,
        output reg [1:0]  Jal_Mult_DM
    );
    
    wire [1:0] alu_op;
    wire HI_LO_mux_en;
    wire alu_HILO_mux_en;
    wire jra;
    wire shift_sel_pre;
    
    assign jump[1] = jra;
                
    maindec md (
        .opcode         (opcode),
        .branch         (branch),
        .jump           (jump[0]),
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
        .shift_sel        (shift_sel_pre)
    );
    
    always @(*) begin
        case({HI_LO_mux_en, alu_HILO_mux_en, jra})
            3'b000: Jal_Mult_DM = (jal) ? 2'b11:2'b01;
            3'b011: Jal_Mult_DM = (jal) ? 2'b11:2'b00;
            3'b100: Jal_Mult_DM = (jal) ? 2'b11:2'b10;
            default: Jal_Mult_DM = (jal) ? 2'b11:2'b00;
        endcase
        if (jal)
            shift_sel = 1'b0;
        else
            shift_sel = shift_sel_pre;       
    end
endmodule