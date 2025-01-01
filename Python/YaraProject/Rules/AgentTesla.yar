import "pe"

rule agenttesla {
	
	meta:
    Description = ""
    Date = "2025/01/01"
    Author = "Garrett Burt"
    Sha256 = ""

	strings:
    $hexval = {6d 6f 64 65 2e 0d 0d 0a 24 00 00 00 00 00 00 00}
    $at1 = "PublicKeyToken="
    $at2 = "lSystem.Resources.ResourceReader, mscorlib, Version=" ascii wide
    $at3 = "mscoree.dll" ascii wide
    $at4 = ".NET Framework 4" ascii wide
    $at5 = "_CorExeMain" 
    $at6 = "Culture=neutral"

	condition:
    $hexval and pe.imports("mscoree.dll") and all of ($at*)

}