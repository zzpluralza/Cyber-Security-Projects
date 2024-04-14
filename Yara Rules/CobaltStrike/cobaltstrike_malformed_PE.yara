
/*
 Find malformed PE header, MZARUH, or possibly ......
*/

rule CobaltStrike_malformedPE

{
  meta:
    author = "Garrett Burt"
    date = "2024/04/14"
    
  strings:


    $header1 = {4d 5a 41 52 55 48}
    $header2 = {00 00 00 00 00 00}
  
  condition:
    ($header1 at 0) or ($header2 at 0)

}