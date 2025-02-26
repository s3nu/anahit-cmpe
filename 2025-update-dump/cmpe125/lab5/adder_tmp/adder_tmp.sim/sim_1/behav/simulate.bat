@echo off
set xv_path=C:\\XilinxWebPack\\Vivado\\2016.4\\bin
call %xv_path%/xsim top_level_tb_behav -key {Behavioral:sim_1:Functional:top_level_tb} -tclbatch top_level_tb.tcl -log simulate.log
if "%errorlevel%"=="0" goto SUCCESS
if "%errorlevel%"=="1" goto END
:END
exit 1
:SUCCESS
exit 0
