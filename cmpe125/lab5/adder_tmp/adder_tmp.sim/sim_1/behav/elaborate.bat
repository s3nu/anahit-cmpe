@echo off
set xv_path=C:\\XilinxWebPack\\Vivado\\2016.4\\bin
call %xv_path%/xelab  -wto 1908d4efefca4347abb84e4ad1406211 -m64 --debug typical --relax --mt 2 -L xil_defaultlib -L unisims_ver -L unimacro_ver -L secureip --snapshot top_level_tb_behav xil_defaultlib.top_level_tb xil_defaultlib.glbl -log elaborate.log
if "%errorlevel%"=="0" goto SUCCESS
if "%errorlevel%"=="1" goto END
:END
exit 1
:SUCCESS
exit 0
