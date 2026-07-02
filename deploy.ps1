$dst = 'D:\Heroes3\Heroes3_2026.05.01\_HD3_Data\Packs\战斗崩溃修复'
$src = "$PSScriptRoot\Release"

if (-not (Test-Path $dst)) {
    New-Item -ItemType Directory -Path $dst -Force | Out-Null
}

Copy-Item -LiteralPath "$src\BattleCrashFix.dll" -Destination $dst -Force
Copy-Item -LiteralPath "$PSScriptRoot\BattleCrashFix.ini" -Destination $dst -Force

Write-Host "已部署到 $dst"
