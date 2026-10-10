$ErrorActionPreference = 'Stop'
# 共享部署目标：$env:H3_GAME_DIR > 仓库根 H3Env.ps1 > 内置默认值（换版本改 H3Env.ps1）。
$h3root = Split-Path -Parent $PSScriptRoot
if (Test-Path -LiteralPath "$h3root\H3Env.ps1") { . "$h3root\H3Env.ps1" }
if (-not (Get-Command Get-H3GameDir -ErrorAction SilentlyContinue)) {
    function Get-H3GameDir {
        if ($env:H3_GAME_DIR -and (Test-Path -LiteralPath $env:H3_GAME_DIR)) { $env:H3_GAME_DIR }
        else { 'D:\Heroes3\Heroes3_2026.10.09' }
    }
}
$gameDir = Get-H3GameDir
$dst = "$gameDir\_HD3_Data\Packs\战斗崩溃修复"
$src = "$PSScriptRoot\Release"

if (-not (Test-Path $dst)) {
    New-Item -ItemType Directory -Path $dst -Force | Out-Null
}

Copy-Item -LiteralPath "$src\BattleCrashFix.dll" -Destination $dst -Force
Copy-Item -LiteralPath "$PSScriptRoot\BattleCrashFix.ini" -Destination $dst -Force

Write-Host "已部署到 $dst"
