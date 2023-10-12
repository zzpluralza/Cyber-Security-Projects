$CurrentUser = get-wmiobject -class win32_computersystem | select username
$computerSystem = Get-CimInstance CIM_ComputerSystem
$computerBIOS = Get-CimInstance CIM_BIOSElement
$computerOS = Get-CimInstance CIM_OperatingSystem
$computerCPU = Get-CimInstance CIM_Processor
$computerHDD = Get-CimInstance Win32_LogicalDisk -Filter "DeviceID = 'C:'"
$LUsers = Get-LocalGroupMember -Group "Administrators"
Clear-Host

#Write-Host $CurrentUser.username
#Write-Host "Current User:" + $Computername
Write-Host "System Information for: " $computerSystem.Name -BackgroundColor DarkCyan
"Manufacturer: " + $computerSystem.Manufacturer
"Model: " + $computerSystem.Model
"Serial Number: " + $computerBIOS.SerialNumber
"CPU: " + $computerCPU.Name
"HDD Capacity: "  + "{0:N2}" -f ($computerHDD.Size/1GB) + "GB"
"HDD Space: " + "{0:P2}" -f ($computerHDD.FreeSpace/$computerHDD.Size) + " Free (" + "{0:N2}" -f ($computerHDD.FreeSpace/1GB) + "GB)"
"RAM: " + "{0:N2}" -f ($computerSystem.TotalPhysicalMemory/1GB) + "GB"
"Operating System: " + $computerOS.caption + ", Version: " + $computerOS.Version
"Current User logged In: " + $computerSystem.UserName
write-host 'Admin Users ' $LUsers

write-host 'Hard drive: '
Get-PhysicalDisk | Select FriendlyName, MediaType, OperationalStatus, HelathStatus, Size
write-host 'Network adapters: '
Get-NetAdapter -Name * -Physical | Select DriverDescription, InterfaceAlias, LinkSpeed, ConnectorPresent, Driverinformation
