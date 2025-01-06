rule DetectIcedid {
	
	meta:
    Description = "Detect Icedid malware. Part of Yara Rule training."
    Author = "Garrett Burt"
    Date = "2025/01/01"

	strings:
      $ice1 = "Sleep" ascii wide
      $ice2 = "SHLWAPI.dll" ascii
      $ice3 = "GetProcAddress"
      $ice4 = "KERNEL32.dll" ascii nocase
      $ice5 = "NTDLL.DLL" nocase ascii
      $ice6 = "GetProcessHeap" ascii

	condition:
    all of them


}