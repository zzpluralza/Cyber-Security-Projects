﻿#Captures baseline information for tasks, startup programs, services and tcp connections
#Run this script again at a later date and compare the two output files. Any differences should be carefully
#looked at.
#Check execution policy if running the script is blocked. 
#Set-ExecutionPolicy -Scope CurrentUser -ExecutionPolicy Bypass -Force
#After running the script, recheck the execution policy, make sure it is still set to the original setting
#Date: 07/11/2024
#Author: Garrett Burt
#-----------------------------------------------------------------------------------------------------------
$today = get-date -format o
$today = $today.split("T")
$sysname = $env:COMPUTERNAME
write-host "This script must be run with administrator rights."
write-host "Output file will be stored in the same location the PowerShell script is run from."

$filename = $sysname + "_" + $today[0] + ".txt"
write-host "Tasks" | out-file $filename
get-childitem -path $env:windir\system32\tasks | select name, mode | out-file $filename -append
get-childitem -path $env:windir\tasks | select name, mode | out-file $filename -append

write-host "Startup Programs" | out-file $filename -append
get-childitem -path $env:appdata'\microsoft\windows\start menu\programs\startup' | out-file $filename -append
Get-ItemProperty -path 'HKLM:\software\microsoft\windows\currentversion\run\' | out-file $filename -append
Get-ItemProperty -path 'HKLM:\software\microsoft\windows\currentversion\runonce\' | out-file $filename -append
Get-ItemProperty -path 'HKCU:\software\microsoft\windows\currentversion\run\' | out-file $filename -append

write-host "Services" | out-file $filename -append
get-service | select Name, Displayname | out-file $filename -append

write-host "TCP Connections" | out-file $filename -append
Get-NetTCPConnection | select localaddress, remoteaddress, state | out-file $filename -append

write-host "Script completed. Please transfer the baseline file."