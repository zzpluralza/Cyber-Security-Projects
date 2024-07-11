#Comparison script - Used in malware investigations
#Second baseline should have been run and both output files should be put into this script.
#Date: 07/11/2024
#Author: Garrett Burt
$today = get-date -format o
$today = $today.split("T")
$systemname = $env:COMPUTERNAME
#Put the file path and name in the two variables below
$Firstbaseline = #Path and filename for original baseline
$Secondbaseline = #Path and filename for new baseline

$comparisonfile = $systemname + "_Comparison_" + $today[0] + ".txt"
write-host "Comparing both baseline files"
Compare-Object (get-content $Firstbaseline) (get-content $Secondbaseline) | format-list | Out-file $comparisonfile
write-host "Comparison complete. Check the output file, " + $comparisonfile + "."
 
