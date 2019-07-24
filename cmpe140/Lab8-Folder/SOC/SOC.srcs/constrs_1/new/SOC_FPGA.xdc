# Based on Digilent's Nexys 4 DDR reference XDC,
# with extra pins not used in the labs removed.

# Clock signal (100 MHz)
set_property -dict { PACKAGE_PIN E3    IOSTANDARD LVCMOS33 } [get_ports { clk }]; #IO_L12P_T1_MRCC_35 Sch=clk100mhz
create_clock -add -name sys_clk_pin -period 10.00 -waveform {0 5} [get_ports {clk}];

# Slide switches
set_property -dict { PACKAGE_PIN J15   IOSTANDARD LVCMOS33 } [get_ports { switches[0] }]; #IO_L24N_T3_RS0_15 Sch=sw[0]
set_property -dict { PACKAGE_PIN L16   IOSTANDARD LVCMOS33 } [get_ports { switches[1] }]; #IO_L3N_T0_DQS_EMCCLK_14 Sch=sw[1]
set_property -dict { PACKAGE_PIN M13   IOSTANDARD LVCMOS33 } [get_ports { switches[2] }]; #IO_L6N_T0_D08_VREF_14 Sch=sw[2]
set_property -dict { PACKAGE_PIN R15   IOSTANDARD LVCMOS33 } [get_ports { switches[3] }]; #IO_L13N_T2_MRCC_14 Sch=sw[3]
set_property -dict { PACKAGE_PIN R17   IOSTANDARD LVCMOS33 } [get_ports { switches[4] }]; #IO_L12N_T1_MRCC_14 Sch=sw[4]
#set_property -dict { PACKAGE_PIN T18   IOSTANDARD LVCMOS33 } [get_ports { switches[5] }]; #IO_L7N_T1_D10_14 Sch=sw[5]
#set_property -dict { PACKAGE_PIN U18   IOSTANDARD LVCMOS33 } [get_ports { switches[6] }]; #IO_L17N_T2_A13_D29_14 Sch=sw[6]
#set_property -dict { PACKAGE_PIN R13   IOSTANDARD LVCMOS33 } [get_ports { switches[7] }]; #IO_L5N_T0_D07_14 Sch=sw[7]
#set_property -dict { PACKAGE_PIN T8    IOSTANDARD LVCMOS33 } [get_ports { switches[8] }];
#set_property -dict { PACKAGE_PIN V10   IOSTANDARD LVCMOS33 } [get_ports { switches2[4] }];
#set_property -dict { PACKAGE_PIN U11   IOSTANDARD LVCMOS33 } [get_ports { switches2[3] }];
#set_property -dict { PACKAGE_PIN U12   IOSTANDARD LVCMOS33 } [get_ports { switches2[2] }];
#set_property -dict { PACKAGE_PIN H6    IOSTANDARD LVCMOS33 } [get_ports { switches2[1] }];
#set_property -dict { PACKAGE_PIN T13   IOSTANDARD LVCMOS33 } [get_ports { switches2[0] }];

# LEDs
##set_property -dict { PACKAGE_PIN H17   IOSTANDARD LVCMOS33 } [get_ports { memwrite }]; #IO_L18P_T2_A24_15 Sch=led[0]
##set_property -dict { PACKAGE_PIN K15   IOSTANDARD LVCMOS33 } [get_ports { sinkBit }]; #IO_L24P_T3_RS1_15 Sch=led[1]
set_property -dict { PACKAGE_PIN V11   IOSTANDARD LVCMOS33 } [get_ports { dispsel }];
#set_property -dict { PACKAGE_PIN V12   IOSTANDARD LVCMOS33 } [get_ports { factErr[3] }];
#set_property -dict { PACKAGE_PIN V14   IOSTANDARD LVCMOS33 } [get_ports { factErr[2] }];
#set_property -dict { PACKAGE_PIN V15   IOSTANDARD LVCMOS33 } [get_ports { factErr[1] }];
#set_property -dict { PACKAGE_PIN T16   IOSTANDARD LVCMOS33 } [get_ports { factErr[0] }];

# 7-segment display

# Segment cathodes (common to all digits) 
set_property -dict { PACKAGE_PIN K13   IOSTANDARD LVCMOS33 } [get_ports { LEDOUT[0] }]; #IO_L17P_T2_A26_15 Sch=cd
set_property -dict { PACKAGE_PIN K16   IOSTANDARD LVCMOS33 } [get_ports { LEDOUT[1] }]; #IO_25_15 Sch=cc
set_property -dict { PACKAGE_PIN P15   IOSTANDARD LVCMOS33 } [get_ports { LEDOUT[2] }]; #IO_L13P_T2_MRCC_14 Sch=ce
set_property -dict { PACKAGE_PIN L18   IOSTANDARD LVCMOS33 } [get_ports { LEDOUT[3] }]; #IO_L4P_T0_D04_14 Sch=cg
set_property -dict { PACKAGE_PIN R10   IOSTANDARD LVCMOS33 } [get_ports { LEDOUT[4] }]; #IO_25_14 Sch=cb
set_property -dict { PACKAGE_PIN T11   IOSTANDARD LVCMOS33 } [get_ports { LEDOUT[5] }]; #IO_L19P_T3_A10_D26_14 Sch=cf
set_property -dict { PACKAGE_PIN T10   IOSTANDARD LVCMOS33 } [get_ports { LEDOUT[6] }]; #IO_L24N_T3_A00_D16_14 Sch=ca
set_property -dict { PACKAGE_PIN H15   IOSTANDARD LVCMOS33 } [get_ports { LEDOUT[7] }]; #IO_L19N_T3_A21_VREF_15 Sch=dp

# Anodes per digit
set_property -dict { PACKAGE_PIN J17   IOSTANDARD LVCMOS33 } [get_ports { LEDSEL[0] }]; #IO_L23P_T3_FOE_B_15 Sch=an[0]
set_property -dict { PACKAGE_PIN J18   IOSTANDARD LVCMOS33 } [get_ports { LEDSEL[1] }]; #IO_L23N_T3_FWE_B_15 Sch=an[1]
set_property -dict { PACKAGE_PIN T9    IOSTANDARD LVCMOS33 } [get_ports { LEDSEL[2] }]; #IO_L24P_T3_A01_D17_14 Sch=an[2]
set_property -dict { PACKAGE_PIN J14   IOSTANDARD LVCMOS33 } [get_ports { LEDSEL[3] }]; #IO_L19P_T3_A22_15 Sch=an[3]
set_property -dict { PACKAGE_PIN P14   IOSTANDARD LVCMOS33 } [get_ports { LEDSEL[4] }]; #IO_L8N_T1_D12_14 Sch=an[4]
set_property -dict { PACKAGE_PIN T14   IOSTANDARD LVCMOS33 } [get_ports { LEDSEL[5] }]; #IO_L14P_T2_SRCC_14 Sch=an[5]
set_property -dict { PACKAGE_PIN K2    IOSTANDARD LVCMOS33 } [get_ports { LEDSEL[6] }]; #IO_L23P_T3_35 Sch=an[6]
set_property -dict { PACKAGE_PIN U13   IOSTANDARD LVCMOS33 } [get_ports { LEDSEL[7] }]; #IO_L23N_T3_A02_D18_14 Sch=an[7]

# Pushbuttons

# Active low
set_property -dict { PACKAGE_PIN P17   IOSTANDARD LVCMOS33 } [get_ports { reset }]; #IO_L12P_T1_MRCC_14 Sch=btnl

#=============================================================================
