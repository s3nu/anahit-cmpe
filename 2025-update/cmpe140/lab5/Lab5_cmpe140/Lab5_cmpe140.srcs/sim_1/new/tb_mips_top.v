`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 10/08/2017 06:34:27 PM
// Design Name: 
// Module Name: tb_mips_top
// Project Name: 
// Target Devices: 
// Tool Versions: 
// Description: 
// 
// Dependencies: 
// 
// Revision:
// Revision 0.01 - File Created
// Additional Comments:
// 
//////////////////////////////////////////////////////////////////////////////////

module tb_mips_top;
    reg         clk, rst;
    wire        we_dm;
    wire [31:0] pc_current, instr, alu_out, wd_dm, rd_dm;
    
 
    mips_top DUT (clk, rst, we_dm, pc_current, instr, alu_out, wd_dm, rd_dm);
    task tick; begin #5 clk = 1; #5 clk = 0; end endtask
    task rest; begin #5 rst = 1; #5 rst = 0; end endtask
    
    initial begin
        clk = 0;
        rst = 1;
        rest;
        while(pc_current != 32'h48)
        begin
            tick;
            case(pc_current)
                32'h0: begin 
                            if(alu_out != 5) $display("Error with alu at instruction addr: 0");
                            if(instr != 32'h20020005) $display("Error with instr at instruction addr: 0");
                            if(rd_dm != 32'hffffffff) $display("Error with rd_dm at instruction addr: 0");
                            if(we_dm != 1) $display("Error with we_dm at instruction addr: 0");  
                       end
                32'h4: begin 
                            if(alu_out != 12) $display("Error with alu at instruction addr: 4");
                            if(instr != 32'h2003000c) $display("Error with instr at instruction addr: 4");
                            if(rd_dm != 32'hffffffff) $display("Error with rd_dm at instruction addr: 4");
                            if(we_dm != 0) $display("Error with we_dm at instruction addr: 4");   
                       end
                32'h8: begin 
                            if(alu_out != 3) $display("Error with alu at instruction addr: 8");
                            if(instr != 32'h2067fff7) $display("Error with instr at instruction addr: 8");
                            if(we_dm != 0) $display("Error with we_dm at instruction addr: 8");
                            if(rd_dm != 32'hffffffff) $display("Error with rd_dm at instruction addr: 8");   
                       end
                32'hc: begin 
                            if(alu_out != 7) $display("Error with alu at instruction addr: c"); 
                            if(instr != 32'h00e22025) $display("Error with instr at instruction addr: c");
                            if(we_dm != 0) $display("Error with we_dm at instruction addr: c");
                            if(rd_dm != 32'hffffffff) $display("Error with rd_dm at instruction addr: c");  
                        end
                32'h10: begin 
                            if(alu_out != 4) $display("Error with alu at instruction addr: 10"); 
                            if(instr != 32'h00642824) $display("Error with instr at instruction addr: 10");
                            if(we_dm != 0) $display("Error with we_dm at instruction addr: 10");
                            if(rd_dm != 32'hffffffff) $display("Error with rd_dm at instruction addr: 10");  
                        end
               32'h14:  begin
                            if(alu_out != 11) $display("Error with alu at instruction addr: 14"); 
                            if(instr != 32'h00a42820) $display("Error with instr at instruction addr: 14");
                            if(we_dm != 0) $display("Error with we_dm at instruction addr: 14");
                            if(rd_dm != 32'hffffffff) $display("Error with rd_dm at instruction addr: 14");  
                        end
               32'h18:  begin
                            if(instr != 32'h10a7000a) $display("Error with instr at instruction addr: 18");
                            if(we_dm != 0) $display("Error with we_dm at instruction addr: 18");
                            if(rd_dm != 32'hffffffff) $display("Error with rd_dm at instruction addr: 18");    
                        end
               32'h1c:  begin
                            if(alu_out != 0) $display("Error with alu at instruction addr: 1c"); 
                            if(instr != 32'h0064202a) $display("Error with instr at instruction addr: 1c"); 
                            if(we_dm != 0) $display("Error with we_dm at instruction addr: 1c");
                            if(rd_dm != 32'hffffffff) $display("Error with rd_dm at instruction addr: 1c");  
                        end
               32'h20:  begin
                            if(instr != 32'h10080001) $display("Error with instr at instruction addr: 20");
                            if(we_dm != 0) $display("Error with we_dm at instruction addr: 20");
                             if(rd_dm != 32'hffffffff) $display("Error with rd_dm at instruction addr: 20");   
                        end
               32'h24:  begin $display("Error with beq instr at instruction addr: 24"); end
               32'h28: begin
                           if(instr != 32'h00e2202a) $display("Error with instr at instruction addr: 28");
                           if(alu_out != 1) $display("Error with alu instr at instruction addr: 28");
                           if(we_dm != 0) $display("Error with we_dm at instruction addr: 28");
                            if(rd_dm != 32'hffffffff) $display("Error with rd_dm at instruction addr: 28");    
                       end
               32'h2c: begin
                              if(instr != 32'h00853820) $display("Error with instr at instruction addr: 2c");
                              if(alu_out != 12) $display("Error with alu instr at instruction addr: 2c");
                              if(we_dm != 0) $display("Error with we_dm at instruction addr: 2c");   
                              if(rd_dm != 32'hffffffff) $display("Error with rd_dm at instruction addr: 2c"); 
                       end
               32'h30: begin
                              if(instr != 32'h00e23822) $display("Error with instr at instruction addr: 30");
                              if(alu_out != 7) $display("Error with alu instr at instruction addr: 30");
                              if(we_dm != 0) $display("Error with we_dm at instruction addr: 30");  
                               if(rd_dm != 32'hffffffff) $display("Error with rd_dm at instruction addr: 30");  
                       end
               32'h34: begin
                              if(instr != 32'hac670044) $display("Error with instr at instruction addr: 34");
                              if(wd_dm != 32'h7) $display("Error with wd_dm at instruction addr: 34");
                              if(we_dm != 1) $display("Error with we_dm at instruction addr: 34");
                              if(alu_out != 32'h50) $display("Error with alu at instruction addr: 34");
                               if(rd_dm != 32'hffffffff) $display("Error with rd_dm at instruction addr: 34"); 
                              
                       end
               32'h38: begin
                              if(instr != 32'h8c020050) $display("Error with instr at instruction addr: 38");
                              if(rd_dm != 32'h7) $display("Error with wd_dm at instruction addr: 38");
                              if(we_dm != 0) $display("Error with we_dm at instruction addr: 38");
                              if(alu_out != 32'h50) $display("Error with alu at instruction addr: 38");  
                       end
               32'h3c: begin
                              if(instr != 32'h08000011) $display("Error with instr at instruction addr: 3c");
                              if(we_dm != 0) $display("Error with we_dm at instruction addr: 3c");
                              if(alu_out != 32'h0) $display("Error with alu at instruction addr: 3c");
                              if(rd_dm != 32'hffffffff) $display("Error with rd_dm at instruction addr: 3c");   
                       end
               32'h40: begin
                              $display("Error with jump instr at instruction addr: 3c");  
                       end
               32'h44: begin
                              if(we_dm != 1) $display("Error with we_dm at instruction addr: 44");
                              if(alu_out != 32'h54) $display("Error with alu_out at instruction addr: 44");
                              if(wd_dm != 32'h7) $display("Error with wd_dm at instruction addr: 44");
                              if(instr != 32'hac020054) $display("Error with instr at instruction addr: 44");
                              if(rd_dm != 32'hffffffff) $display("Error with rd_dm at instruction addr: 44");  
                       end
               32'h48: begin                         
                              if(instr != 32'h08000000) $display("Error with instr at instruction addr: 48");
                              if(we_dm != 0) $display("Error with we_dm at instruction addr: 48"); 
                              if(alu_out != 32'h0) $display("Error with alu_out at instruction addr: 48");
                              if(rd_dm != 32'hffffffff) $display("Error with rd_dm at instruction addr: 48"); 
                       end
            endcase
        end
        $display("End of Simulation");
        $finish;
    end
endmodule
