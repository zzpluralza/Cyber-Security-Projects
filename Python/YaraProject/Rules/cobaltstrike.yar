rule CobaltStikeBeacon {

	meta:
    Description = "Detect Cobalt Strike process."
    Date = "2024/12/28"
    Author = "Garrett Burt"
    Sha256one = "9c6b75e3f0262ff0da248d147f2c13068cafd80c5c835ad5d78355440357765c"
    
  strings:
    $hex_pipe = {3c 94 00 00 00 00 00 00} //CreateNamedPipeA
    $hex_sleep = {12 96 00 00 00 00 00 00} //sleep imports
  
  condition:
    all of them
}



rule CobaltStrike2 {
meta:
  Description = "Detect Cobalt Strike process."
  Date = "2024/12/28"
  Author = "Garrett Burt"
  Sha256two = "18176a8ccc62cced9771a9fb2e2996016d79b2fbd700a15dbdd7467d1b998ee0"

strings:
  $hex_sleep = { cb 12 35 00 00 00 00 00 } //Sleep function import from Kernel32.dll
  $hex_debugger = { 5c 16 35 00 00 00 00 00 } //Isdebuggerpresent import from Kernel32.dll
  $hex_namedpipe = { 07 19 35 00 00 00 00 00 1a 19 35 00 00 00 00 00 } //namedpipe import Kernel32.dll

condition:
  all of them
}

rule cobaltstrike_go {
  
  meta:
    Description = "CobaltStrike version written in Golang. Yarapython learning project"
    Date = "2024/12/28"
    Author = "Garrett Burt"
    Sha256 = "5be1175f54a4cbbaf19a76ba8ff3c7501729c1157e0e878507b130d1ba72f0bf"
    Sha256Two = "30f23855d09b242339d3bdd20fc72ac30569be14701fe6a3080b284a15eeacf0"

  strings:
    $a1 = "runtime.rand32" nocase
    $a2 = "crypto/subtle.XORBytes" nocase
    $a3 = "crypto/aes.expandKeyGo" nocase
    $a4 = "Kernel32.dll" nocase
    $a5 = "mime.maxBase64Len" nocase

  condition:
    all of them

}