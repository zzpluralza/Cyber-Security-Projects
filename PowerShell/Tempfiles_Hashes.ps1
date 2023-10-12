$extensions = @('.exe', '.ps1', '.js', '.bat')
$directories = @("$env:APPDATA\Local", "$env:APPDATA\Roaming")
$outputFile = "$env:USERPROFILE\Desktop\FileList.txt"

foreach ($directory in $directories) {
    Get-ChildItem $directory -Recurse -Include $extensions -ErrorAction SilentlyContinue | ForEach-Object {
        $hash = Get-FileHash $_.FullName -Algorithm MD5 | Select-Object -ExpandProperty Hash
        $line = "File found: $($_.FullName) | MD5 hash: $hash"
        Write-Output $line | Out-File -FilePath $outputFile -Append
    }
}

Write-Output "File search complete. Results saved to $outputFile"
