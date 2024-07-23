#Registries to look for 
#Hidden tasks: "HKLM:\SOFTWARE\Microsoft\Windows NT\CurrentVersion\Schedule\TaskCache\Tree" -- Key "Index" Value = 0x00000000 
<#
Looking for threats within registry. 
Date: 07/22/2024
Author: Garrett
#>


# Test b64: Q2FuIHlvdSBwYXJzZSB0aGlzIGludG8gYmFzZTY0IGlmIHNvIGNhbiBJIHNlZSBpdD8=
# Answer: Can you parse this into base64 if so can I see it?

<# Notes to consider USING THE ITEMS BELOW AS A REGISTRY SCAN SCRIPT
https://github.com/SigmaHQ/sigma/blob/master/rules/windows/registry/registry_set/registry_set_vbs_payload_stored.yml ********
https://github.com/SigmaHQ/sigma/blob/master/rules/windows/registry/registry_set/registry_set_treatas_persistence.yml *******
https://github.com/SigmaHQ/sigma/blob/master/rules/windows/registry/registry_set/registry_set_susp_user_shell_folders.yml ***
https://github.com/SigmaHQ/sigma/blob/master/rules/windows/registry/registry_set/registry_set_susp_service_installed.yml ****
https://github.com/SigmaHQ/sigma/blob/master/rules/windows/registry/registry_set/registry_set_susp_run_key_img_folder.yml ***
https://github.com/SigmaHQ/sigma/blob/master/rules/windows/registry/registry_set/registry_set_susp_reg_persist_explorer_run.yml
https://github.com/SigmaHQ/sigma/blob/master/rules/windows/registry/registry_set/registry_set_special_accounts.yml **********
https://github.com/SigmaHQ/sigma/blob/master/rules/windows/registry/registry_set/registry_set_powershell_in_run_keys.yml ****
https://github.com/SigmaHQ/sigma/blob/master/rules/windows/registry/registry_set/registry_set_powershell_as_service.yml *****
https://github.com/SigmaHQ/sigma/blob/master/rules/windows/registry/registry_set/registry_set_lolbin_onedrivestandaloneupdater.yml
https://github.com/SigmaHQ/sigma/blob/master/rules/windows/registry/registry_set/registry_set_hide_scheduled_task_via_index_tamper.yml
https://github.com/SigmaHQ/sigma/blob/master/rules/windows/registry/registry_set/registry_set_hidden_extention.yml **********
https://github.com/SigmaHQ/sigma/blob/master/rules/windows/registry/registry_set/registry_set_cobaltstrike_service_installs.yml

 #>

 #Beginning of script -----------------------------------------------------

$today = get-date -format o
$today = $today.split("T")
$outfile = $today[0] + "_" + $env:COMPUTERNAME + "_Registrycheck.txt"

"Checking HKCU:\Software for system: $env:computername" | out-file $outfile
"Date: $today[0]" | Out-File $outfile -Append

#key words are written in regular expression format, looking for case insensitive variations
$keywords = @("\w*powershell\w*", "\w*wscript\w*", "\w*shell\w*", "\w*Hidden\w*", "\w*pwsh\w*", "\w*wget\w*", "\w*curl\w*", "\w*download\w*", "\w*regsrv32\w*", "\w*SilentlyContinue\w*", "\w*\s-o\s\w*")

$powershellcmd = @("\w*Get-ChildItem\w*", "\w*-Path\w*", "\w*Bypass\w*", "\w*Base64\w*", "\w*\$env:\w*", "\w*iex\w*", "\w*Download\w*" )
$base64strings = "(?:[A-Za-z0-9+\/]{4})*(?:[A-Za-z0-9+\/]{2}==|[A-Za-z0-9+\/]{3}=)?$"

$regpath = "HKCU:\SOFTWARE\"
$registryvalues = Get-ChildItem -path $regpath -Recurse | select name, PSPath, property | where {$_.property -ne $null}
$mainreg = get-childitem -path $regpath | select name, property
foreach ($reg in $registryvalues) {
    
    foreach ($word in $keywords) {
         
        if ($reg.property -match $word) {
            $printout = $reg | select pspath, property | format-list   
            write-host $printout 
            $printout | out-file $outfile -append
        }
    }
    
    foreach ($pshell in $powershellcmd) {
        if ($reg.property -match $pshell) {
            $printout = $reg | select pspath, property | format-list   
            write-host $printout 
            $printout | out-file $outfile -append
        }
    }
    if (reg.property -match $base64strings) {
        write-host "Base64 code detected"
        "Possible Base64 code detected" | out-file $outfile -append
        $printout = $reg | select pspath, property | format-list
        write-host $printout
        $printout | out-file $outfile -append                   
    }  
}