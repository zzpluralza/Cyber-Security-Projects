<# 
All Purpose Emerging Threats 2024
Based on Sigma Rules: https://github.com/SigmaHQ/sigma/blob/master/rules-emerging-threats/2024/Malware/
This script is strictly looking at running processes and their properties, such as commandline arguments
Future scripts will do similar and scrape for malicious registry entries

Date: 07/15/2024
Author: Garrett Burt
Threat hunting PS script

 Testing Phase 07/15/2024
Script must be run as administrator
If you change the Execution Policy, make sure you change it back before logging off from the system


First version of script - Not very well optimized. Will look into better ways to code these checks in future versions
General workflow has been tested. Currently unknown if we will get false positives. If so, the script will need to be refined
#>

write-host "Checking for emerging threats. Based on Sigma Rules from SigmaHQ's Sigma Rule repository."
$systemname = $env:Computername
$today = get-date -format o
$today = $today.split("T")
$Outputfile = $systemname + "_" + $today[0] + ".txt"

write-host "Output file is in the same location the script is run from. File name is: $Outputfile"

#Getting full list of running processes
$proclist = gwmi win32_process | select processname, processid, parentprocessid, commandline, path

write-host "Searching emerging threats for $systemname"
"Searching emerging threats for $systemname" | Out-File $Outputfile

#Large loop reviewing running processes for hints of specific malware families
foreach ($proc in $proclist) {
    
 <#
 Some malware indicators come from parent process and even from the grandparent process. Script may output red error text if it can't find a parent or grandparent processes.
 Script should continue despite the errors
 #>
    $parentproc = gwmi win32_process | where {$_.processid -eq $proc.parentprocessid} | select processname, processid, commandline, path, parentprocessid
    $grandpa = gwmi win32_process | where {$_.processid -eq $parentproc.processid} | select processname, processid, commandline, path, parentprocessid
    
    #DarkGate----------------------------------------------------------------------------------------------
    If ($proc.commandline -match "\:\\temp\\") {
    
        if (($proc.commandline -match "autoit3\.exe") -or ($proc.commandline -match "\.au3") -or ($proc.commandline -match "curl\.exe") -or ($proc.commandline -match "ExtExport\.exe") -or ($proc.commandline -match "KeyScamblerLogon\.exe") -or ($proc.commandline -match "\wmprph\.exe"))  {
            write-host "Possible DarkGate infection at: " + $proc.ProcessName + ". ProcessID: " + $proc.processid + "."
            "Possible DarkGate infection at: " + $proc.ProcessName + ". ProcessID: " + $proc.processid + "." | out-file $Outputfile -append
            write-host "Parent process is: " + $parentproc.processname
            "Parent process is: " + $parentproc.processname | out-file $Outputfile -append          
        }
        elseif (($proc.processname -eq "Autoit3.exe") -and ($proc.commandline -match "msiexec\.exe")) {
            write-host "Possible DarkGate infection at: $proc.ProcessName. ProcessID: $proc.processid."
            "Possible DarkGate infection at: $proc.ProcessName. ProcessID: $proc.processid." | out-file $Outputfile -append
            write-host "Parent process is: $parentproc.processname. ProcessID: $parentproc.processid."
            "Parent process is: $parentproc.processname. ProcessID: $parentproc.processid."| out-file $Outputfile -append          
        }
      
    } 
    elseif (($proc.ProcessName -eq "net.exe") -or ($proc.ProcessName -eq "net1.exe")) {
        if (($proc.commandline -match "user") -and ($proc.commandline -match "add") -and ($proc.commandline -match "DarkGate")) {
            write-host "Possible DarkGate infection at: $proc.ProcessName. ProcessID:$proc.processid."
            "Possible DarkGate infection at: $proc.ProcessName. ProcessID:$proc.processid." | out-file $Outputfile -append
            write-host "Parent process is: $parentproc.processname. ProcessID: $parentproc.processid."
            "Parent process is: $parentproc.processname. ProcessID: $parentproc.processid."| out-file $Outputfile -append          
        }
    }   
        
    #KamiKakaBot----------------------------------------------------------------------------------------------
    elseif (($proc.processname -eq "cmd.exe") -and ($proc.commandline -match "\/c") -and ($proc.commandline -match "\.lnk") -and ($proc.commandline -match "Start Menu\\Programs\\Word") -and ($proc.commandline -match "\.doc")) {
        write-host "Possible KamiKakabot infection at " + $proc.ProcessName + ". Processid: " + $proc.processid
        "Possible KamiKakabot infection at " + $proc.ProcessName + ". Processid: " + $proc.processid | out-file $Outputfile -append
    } 
        
    #Raspberry-Robin----------------------------------------------------------------------------------------------
    elseif (($parentproc.processname -eq "rundll32.exe") -or ($parentproc.processname -eq "control.exe")) {
        if (($proc.ProcessName -eq "rundll32.exe") -and ($proc.commandline -match "\\AppData\\Local\\Temp\\")) {
            if (($proc.commandline -match "shell32\.dll") -or ($proc.commandline -match "Control_RunDLL") -or ($proc.commandline -match "\.CPL")) {
                write-host "Possible Raspberry-Robin detection at: " + $proc.ProcessName + ". ProcessID: " + $proc.processid
                write-host "Parent Process is: " + $parentproc.processname + ". ProcessID: " + $parentproc.processid
                "Possible Raspberry-Robin detection at: " + $proc.ProcessName + ". ProcessID: " + $proc.processid | out-file $Outputfile -append
                "Parent Process is: " + $parentproc.processname + ". ProcessID: " + $parentproc.processid | out-file $Outputfile -append
            }
        }
     }  
      
    #Kapeka-------------------------------------------------------------------------------------------------------------
    elseif (($proc.commandline -match ":\\ProgramData\\") -or ($proc.commandline -match "\\AppData\\Local\\")) {
        if (($proc.commandline -match "\\[a-zA-Z]{5,6}\.wil") -or ($proc.commandline -match "\\win32log\.exe") -or ($proc.commandline -match "\\crdss\.exe")){
            write-host "Possible Kapeka threat detection: " + $proc.processname + ". ProcessID: " + $proc.processid
            write-host "Parent process: " + $parentproc.processname + ". ProcessID: " + $parentproc.processid
            "Possible Kapeka threat detection: " + $proc.processname + ". ProcessID: " + $proc.processid | Out-File $Outputfile -append
            "Parent process: " + $parentproc.processname + ". ProcessID: " + $parentproc.processid | Out-File $Outputfile -append
        }
    }
    elseif (($proc.processname -eq "rundll32.exe") -and ($proc.commandline -match "[a-zA-Z]{5,6}\.wll")) {
            write-host "Possible Kapeka threat detection: " + $proc.processname + ". ProcessID: " + $proc.processid
            write-host "Parent process: " + $parentproc.processname + ". ProcessID: " + $parentproc.processid
            "Possible Kapeka threat detection: " + $proc.processname + ". ProcessID: " + $proc.processid | Out-File $Outputfile -append
            "Parent process: " + $parentproc.processname + ". ProcessID: " + $parentproc.processid | Out-File $Outputfile -append
    }

    #IceID----------------------------------------------------------------------------------------------
    elseif (($proc.commandline -match "\\1\.dll") -and ($proc.commandline -match "DllRegisterServer")){
        write-host "Possible IceID infection at: " + $proc.ProcessName + ". ProcessID: " + $proc.processid
        write-host "Parent Process at: " + $parentproc.processname + ". ProcessID: " + $parentproc.processid
        "Possible IceID infection at: " + $proc.ProcessName + ". ProcessID: " + $proc.processid | Out-File $Outputfile -append
        "Parent Process at: " + $parentproc.processname + ". ProcessID: " + $parentproc.processid | Out-File $Outputfile -append
    }
   
    #Pikabot----------------------------------------------------------------------------------------------
    elseif ($grandpa.processname -eq "rundll32.exe") {
        if (($proc.commandline -match "\\SearchFilterHost\.exe") -or ($proc.commandline -match "\\SearchProtocol\.exe")) {
            if (($proc.commandline -match "ipconfig\.exe \/all") -or ($proc.commandline -match "netstat\.exe -aon") -or ($proc.commandline -match "whoami\.exe \/all")) {
                write-host "Pikabot infection detected at: " + $proc.ProcessName + ". ProcessID: " + $proc.processid
                write-host "Parent process: " + $parentproc.processname + ". ProcessID: " + $parentproc.processid
                write-host "Grandparent process: " + $grandpa.processname + ". ProcessID: " + $grandpa.processid
                "Pikabot infection detected at: " + $proc.ProcessName + ". ProcessID: " + $proc.processid | out-file $Outputfile -append
                "Parent process: " + $parentproc.processname + ". ProcessID: " + $parentproc.processid | out-file $Outputfile -append
                "Grandparent process: " + $grandpa.processname + ". ProcessID: " + $grandpa.processid | out-file $Outputfile -append
            }
        }
    }
    elseif (($proc.commandline -match "\\SearchFilterHost\.exe") -or ($proc.commandline -match "\\SearchProtocolHost\.exe") -or ($proc.commandline -match "\\sndvol\.exe") -or ($proc.commandline -match "\\wermgr\.exe") -or ($proc.commandline -match "\\wwahost\.exe")) {
        if ($parentproc.commandline -match "mmsys\.cpl") {
                write-host "Pikabot infection detected at: " + $proc.ProcessName + ". ProcessID: " + $proc.processid
                write-host "Parent process: " + $parentproc.processname + ". ProcessID: " + $parentproc.processid
                write-host "Grandparent process: " + $grandpa.processname + ". ProcessID: " + $grandpa.processid
                "Pikabot infection detected at: " + $proc.ProcessName + ". ProcessID: " + $proc.processid | out-file $Outputfile -append
                "Parent process: " + $parentproc.processname + ". ProcessID: " + $parentproc.processid | out-file $Outputfile -append
                "Grandparent process: " + $grandpa.processname + ". ProcessID: " + $grandpa.processid | out-file $Outputfile -append
        } 
    }

    #Qakbot----------------------------------------------------------------------------------------------
    elseif (($proc.commandline -match "(\\regsvr32\.exe)") -and ($proc.commandline -match "-s") -and ($proc.commandline -match "calc")) {
        write-host "Qakbot infection seen at: " + $proc.ProcessName + ". ProcessID: " + $proc.processid
        write-host "Parent process at: " + $parentproc.processname + ". ProcessID: " + $parentproc.processid
        "Qakbot infection seen at: " + $proc.ProcessName + ". ProcessID: " + $proc.processid | Out-File $Outputfile -append
        "Parent process at: " + $parentproc.processname + ". ProcessID: " + $parentproc.processid | Out-File $Outputfile -append
    }
    elseif (($parentproc.comamndline -match "(\\cmd\.exe)") -or ($parentproc.commandline -match "(\\cscript\.exe)") -or ($parentproc.commandline -match "(\\curl\.exe)") -or ($parentproc.commandline -match "(\\mshta\.exe)") -or ($parentproc.commandline -match "(\\powershell\.exe)") -or ($parentproc.commandline -match "(\\pwsh\.exe)") -or ($parentproc.commandline -match "(\\wscript\.exe)")) {
        if ($proc.commandline -match "\\rundll32\.exe") {
            if (($proc.commandline -match ":\\ProgramData\\") -or ($proc.commandline -match ":\\Users\\Public\\") -or ($proc.commandline -match "\\AppData\\Local\\Temp\\") -or ($proc.commandline -match "\\AppData\\Roaming")) {
                write-host "Qakbot infection seen at: " + $proc.ProcessName + ". ProcessID: " + $proc.processid
                write-host "Parent process at: " + $parentproc.processname + ". ProcessID: " + $parentproc.processid
                "Qakbot infection seen at: " + $proc.ProcessName + ". ProcessID: " + $proc.processid | Out-File $Outputfile -append
                "Parent process at: " + $parentproc.processname + ". ProcessID: " + $parentproc.processid | Out-File $Outputfile -append
            }
        }
    }

    #Rhadamanthys------------------------------------------------------------------------------------------
    if (($proc.processname -eq "rundll32.exe") -and ($proc.commandline -match "nsis_uns") -and ($proc.commandline -match "PrintUIEntry")) {
        write-host "Rhadamanthys Stealer detected at: " + $proc.processname + ". ProcessID: " + $proc.processid
        write-host "Parent process at: " + $parentproc.processname + ". ProcessID: " + $parentproc.processid
        "Rhadamanthys Stealer detected at: " + $proc.processname + ". ProcessID: " + $proc.processid | out-file $Outputfile -append
        "Parent process at: " + $parentproc.processname + ". ProcessID: " + $parentproc.processid | out-file $Outputfile -append
    }
    
    #Rorschach Ransomware-----------------------------------------------------------------------------------------------
    elseif (($proc.commandline -match "\\bcdedit\.exe") -or ($proc.commandline -match "\\net\.exe") -or ($proc.commandline -match "\\net1\.exe") -or ($proc.commandline -match "\\netsh\.exe") -or ($proc.commandline -match "\\wevtutil\.exe") -or ($proc.commandline -match "\\vssadmin\.exe")) {
        if ($proc.commandline -match "1{8}") {
            write-host "Rorschach Ransomware detected at: " + $proc.ProcessName + ". ProcessID: " + $proc.processid
            write-host "Parent process: " + $parentproc.processname
            "Rorschach Ransomware detected at: " + $proc.ProcessName + ". ProcessID: " + $proc.processid | out-file $Outputfile -append
            "Parent process: " + $parentproc.processname | Out-File $Outputfile -append
        }
    
    }
    
    #SNAKE---------------------------------------------------------------------------------------------------------------
    elseif (($proc.commandline -match "\\jpsetup\.exe") -or ($proc.commandline -match "\\jpinst\.exe")) {
        write-host "Possible SNAKE infection: " + $proc.processname + ". ProcessID: " + $proc.processid
        "Possible SNAKE infection: " + $proc.processname + ". ProcessID: " + $proc.processid | out-file $Outputfile -append
    }
    elseif (($proc.commandline -match "C:\\Windows\\WinSxS\\") -and ($proc.commandline -match "\\WerFault\.exe")) {
        write-host "Possible SNAKE infection: " + $proc.processname + ". ProcessID: " + $proc.processid
        "Possible SNAKE infection: " + $proc.processname + ". ProcessID: " + $proc.processid | out-file $Outputfile -append
    }
    elseif ($proc.commandline -match "\s[a-fA-F0-9]{64}\s[a-fA-F0-9]{16}") {
        write-host "Possible SNAKE infection: " + $proc.processname + ". ProcessID: " + $proc.processid
        "Possible SNAKE infection: " + $proc.processname + ". ProcessID: " + $proc.processid | out-file $Outputfile -append
    }

 } #end of foreach iteration

 write-host "Script completed. Output file saved: " + $Outputfile + "."
