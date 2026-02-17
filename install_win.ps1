Write-Host "Installing Lamon..."

$target = "$env:USERPROFILE\\AppData\\Local\\Programs\\Lamon"
New-Item -ItemType Directory -Force -Path $target | Out-Null

Copy-Item ".\\lamon.exe" "$target\\lamon.exe" -Force

$envPath = [Environment]::GetEnvironmentVariable("Path", "User")

if ($envPath -notlike "*$target*") {
    [Environment]::SetEnvironmentVariable(
        "Path",
        "$envPath;$target",
        "User"
    )
}

Write-Host "Lamon installed!"
Write-Host "Restart terminal and run: lamon"
