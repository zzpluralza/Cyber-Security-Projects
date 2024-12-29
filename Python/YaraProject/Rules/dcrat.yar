rule dcrat {

  meta:
    Description = "Finding DCRat"
    Date = "2024/12/28"
    Author = "Garrett Burt"
    Sha256 = "b8c9a273058d6214aeccc822fb5f304edc734bd57a4ac43450feeacef70fafb8"

  strings:
    $a1 = "RaiseException"
    $a2 = "ShellExecute"
    $a3 = "IsDebuggerPresent"
    $a4 = "pastebin.com" ascii wide
    $a5 = "UploadData"
    $a6 = "GETPASSWORD"

  condition:
    all of them

}