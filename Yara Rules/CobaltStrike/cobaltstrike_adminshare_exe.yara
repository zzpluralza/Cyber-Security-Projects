
/*
 Rule to track down any random letter exe files located in the admin$ share. Related to Cobalt Strike, post lateral movement.

*/

rule CobaltStrike_Admin_exe 

{
  meta:
    author = "Garrett Burt"
    date = "2024/04/14"
    description = "Finding Cobalt Strike exe after later movement."
    
  strings:
    $regex = ?^[0-9a-zA-Z]{7}(\.exe){0.1}$
    $path = "ADMIN$" nocase
    $path2 = "C:\Windows" nocase

  condition:
    $regex and 1 of ($path*)

}