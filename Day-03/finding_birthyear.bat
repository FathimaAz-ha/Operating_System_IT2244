@echo off
set /p dob='Enter birth year(yyyy--MM-DD):'
::set year=%dob:~0,4%
set /a age=%date:~10,4% - %dob%
echo your age is:%age%
pause