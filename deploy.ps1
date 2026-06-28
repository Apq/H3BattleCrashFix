$dst = 'D:\Heroes3\Heroes3_2026.05.01\_HD3_Data\Packs\战斗崩溃修复'
$src = "$PSScriptRoot\..\Release"

Copy-Item "$src\BattleCrashFix.dll" $dst -Force
# INI 仅首次部署，避免覆盖游戏目录中已修改的配置
if (-not (Test-Path "$dst\BattleCrashFix.ini")) {
    Copy-Item "$PSScriptRoot\BattleCrashFix.ini" $dst
}

Write-Host "已部署到 $dst"
