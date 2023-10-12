#What's starting up when the computer starts up

$reglist = get-itemproperty -Path "HKLM:\SOFTWARE\Microsoft\Windows\CurrentVersion\Run\"
$regRunOnce = get-itemproperty -Path "HKLM:\Software\Microsoft\Windows\CurrentVersion\RunOnce\"
$hkcuRun = get-itemproperty -Path "HKCU:\Software\Microsoft\Windows\CurrentVersion\Run\"
$hkcuRO = get-itemproperty -Path "HKCU:\SOFTWARE\Microsoft\Windows\CurrentVersion\RunOnce\"
#$hklmExplorer = get-itemproperty -Path "HKLM:\Software\Microsoft\Windows NT\CurrentVersion\WinLogon\"

$output = "c:\Docs\Startups.txt"
$computer = $env:COMPUTERNAME
$Startupfolder = "$env:appdata\Microsoft\Windows\Start Menu\Programs\Startup"
$PDstartup = "C:\ProgramData\Microsoft\Windows\Start Menu\Startup"

$Taskscheduled = get-scheduledtask | where {$_.State -eq "Ready"}

"Current startup programs for $computer" | out-file -FilePath $output
"Registry entries:" >> $output
$reglist >> $output
$regRunOnce >> $output
$hkcuRun >> $output
$hkcuRO >> $output
#$hklmExplorer >> $output

"Current user startup list: " >> $output
get-childitem $Startupfolder -recurse >> $output
get-childitem $PDstartup -recurse >> $output
#"All users startup list: " >> $output
#get-childitem $Allstartup >> $output

"Scheduled Tasks: " >> $output
$Taskscheduled >> $output