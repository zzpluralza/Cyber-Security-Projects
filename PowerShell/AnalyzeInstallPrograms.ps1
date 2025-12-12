#12-11-2025 - Cybersecurity research
#Script to anlayze csv file containing list of installed programs for entire set of computers. Identifies installed PUAs and exports the complete list of computers and installed PUAs
#List of matcharray is incomplete

$inputfile = "big_sample.csv"
$outputfile= "outputfile.csv"

$matcharray = @("Web AceLauncher", "Manualfinder", "WebNavigator","OneStart", "EpiStart")

$filtercolumn = @("NAME", "DEVICE_TYPE", "SITE_UNIQUE_ID", "OS", "APPLICATION_NAME", "VERSION", "PUBLISHER")

$Checkthis = "APPLICATION_NAME"

$datafrominput = import-csv -path $inputfile

$filtered = $datafrominput | where-object {
	$_.$Checkthis in $matcharray
}

$filtered | Select-object -property $filtercolumn | export-csv -path $outputfile -notypeinformation
