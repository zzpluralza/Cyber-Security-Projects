rule BlackoutRansomware {
	
	meta:
		Description = "Yara Rule to identify Blackout ransomware. Part of my Yarapython test project"
		Author = "Garrett Burt"
		Date = "2024-12-28"
    Sha256 = "ecfb5c95d0f3d112650ef4047936e8fa5244c21c921f6c7a6963e92abab4949d"

	strings:
    $st1 = "$encryptedPassword" ascii
    $st2 = "AES_Encrypt1" ascii
    $st3 = "CipherMode" ascii
    $st4 = "KillCtrlAltDelete" ascii
    $st5 = "DebuggerNonUserCodeAttribute" ascii
    $st6 = "CryptoStream" ascii

  condition:
    all of them
}

rule BlackoutRansomware2 {

  meta:
    Description = "Yara Rule to identify Blackout ransomware. Part of my Yarapython test project"
    Author = "Garrett Burt"
    Date = "2024-12-28" 
    Sha256 = "cc8bc43bf3a13c2542d6c5dc820e354228955dc6f661e9d4d1d2b628b5877272"

  strings:
    $a1 = "ConsoleApplication1" ascii
    $a2 = "RandomNumberGenerator" ascii
    $a3 = "get_Culture" ascii
    $a4 = "RNGCryptoServiceProvider" ascii

  condition:

    all of them
}