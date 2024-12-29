rule FindLummaStealerDLL {
  meta:
    description = "Finds variant of lummastealer. Part of yarapython learing project"
    date = "2024-12-14"
    author = "Garrett Burt"
    Sha256hash = "2de30f3d500adcd4335c27dcc96006ac36c860e7591914e13fac061bd5841881"

  strings:
    $st1 = "FlsAlloc"
    $st2 = "IsDebuggerPresent"
    $st3 = "VirtualAlloc"
    $st4 = "CreateHardLinkA"
    $pipe1 = "WaitNamedPipeA"
    $pipe2 = "CreatePipe"
    $st5 = "GetCommandLine"

  condition:
    all of them
}

rule FindLummaStealerEXE {

  meta:
    Description = "Finds variant of Lummastealer. Part of yarapython project"
    Date = "2024-12-28"
    Author = "Garrett Burt"
    Sha256hash = "dd6f96d0d6f6ed2b83df7552f77523688f2a2272fce63564bc9ffdcb3157b70e"

  strings:
    $a1 = "net/url.UserPassword" ascii
    $a2 = "(*Userinfo).Username" ascii
    $a3 = "CryptQueryObject"
    $a4 = "GetNamedPipe"
    $a5 = "crypto/x509"
    $a6 = "encoding/base64.init" ascii
    $a7 = "AdjustTokenPrivilege" ascii

  condition:
    all of them

}
