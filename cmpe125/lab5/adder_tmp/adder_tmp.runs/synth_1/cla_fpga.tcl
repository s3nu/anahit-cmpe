# 
# Synthesis run script generated by Vivado
# 

set_msg_config -id {HDL 9-1061} -limit 100000
set_msg_config -id {HDL 9-1654} -limit 100000
create_project -in_memory -part xc7a100tcsg324-1

set_param project.singleFileAddWarning.threshold 0
set_param project.compositeFile.enableAutoGeneration 0
set_param synth.vivado.isSynthRun true
set_property webtalk.parent_dir {C:/Users/Anahit Sarao/Desktop/cmpe125labs/adder_tmp/adder_tmp.cache/wt} [current_project]
set_property parent.project_path {C:/Users/Anahit Sarao/Desktop/cmpe125labs/adder_tmp/adder_tmp.xpr} [current_project]
set_property default_lib xil_defaultlib [current_project]
set_property target_language Verilog [current_project]
set_property ip_output_repo {c:/Users/Anahit Sarao/Desktop/cmpe125labs/adder_tmp/adder_tmp.cache/ip} [current_project]
set_property ip_cache_permissions {read write} [current_project]
read_verilog -library xil_defaultlib {{C:/Users/Anahit Sarao/Desktop/cmpe125labs/adder_tmp/adder_tmp.srcs/sources_1/new/CLA.v}}
foreach dcp [get_files -quiet -all *.dcp] {
  set_property used_in_implementation false $dcp
}
read_xdc {{C:/Users/Anahit Sarao/Desktop/cmpe125labs/adder_tmp/adder_tmp.srcs/constrs_1/new/fpga.xdc}}
set_property used_in_implementation false [get_files {{C:/Users/Anahit Sarao/Desktop/cmpe125labs/adder_tmp/adder_tmp.srcs/constrs_1/new/fpga.xdc}}]


synth_design -top cla_fpga -part xc7a100tcsg324-1


write_checkpoint -force -noxdef cla_fpga.dcp

catch { report_utilization -file cla_fpga_utilization_synth.rpt -pb cla_fpga_utilization_synth.pb }
