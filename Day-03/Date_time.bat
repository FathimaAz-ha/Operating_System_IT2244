@echo off

echo Date: %date%
:: Extract and display the year from the system date
echo Year: %date:~10,4%
:: Extract and display the month from the system date
echo Month: %date:~4,2%
:: Display the current time
echo Time: %time%
pause