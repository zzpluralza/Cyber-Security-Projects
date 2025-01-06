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
    $a4 = "pastebin.com" ascii
    $a5 = "UploadData"
    $a6 = "GETPASSWORD"

  condition:
    all of them

}


rule moredcrat {
  meta:
    description = "Additional DCRat detection rule. Part of Yara training."

  strings:
    $dc1 = "Queue`1"
    $dc2 = "Stack`1"
    $dc3 = "KeyValuePair`2"
    $dc4 = "Mutex"
    $dc5 = "PublicKeyToken="

  condition:
    all of them
}