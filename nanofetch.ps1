#!/usr/bin/env pwsh
Write-Host " " -b red -nonewline; Write-Host " " -b darkred -nonewline; Write-host " system "$(($PSVersionTable.OS.Split(" "))[0])
Write-Host " " -b green -nonewline; Write-Host " " -b darkgreen -nonewline; Write-host " kernel "$null$([environment]::OSVersion.Version)
Write-Host " " -b yellow -nonewline; Write-Host " " -b darkyellow -nonewline; Write-host " device "$([System.Net.Dns]::GetHostName())
if ($($PSVersionTable.Platform) -eq "Unix") {Write-Host " " -b blue -nonewline; Write-Host " " -b darkblue -nonewline; Write-host " host   " $(cat /sys/devices/virtual/dmi/id/product_name)}
if ($($PSVersionTable.Platform) -eq "Microsoft") {Write-Host " " -b blue -nonewline; Write-Host " " -b darkblue -nonewline; Write-host " host   " $null$(Get-WmiObject -Class Win32_BaseBoard | Format-Table Manufacturer, Product, SerialNumber, Version)}
Write-Host " " -b magenta -nonewline; Write-Host " " -b darkmagenta -nonewline; Write-host " shell  " powershell $PSVersionTable.PSVersion
if ($($PSVersionTable.Platform) -eq "Unix") {Write-Host " " -b cyan -nonewline; Write-Host " " -b darkcyan -nonewline; Write-host " gui    " $(printenv XDG_CURRENT_DESKTOP)}
if ($($PSVersionTable.Platform) -eq "Unix") {Write-Host " " -b white -nonewline; Write-Host " " -b gray -nonewline; Write-host " gtk    " $(grep 'gtk-theme-name' $HOME/.config/gtk-3.0/settings.ini | cut -d' ' -f 3)}
Write-Host " " -b darkgray -nonewline; Write-Host " " -b black -nonewline; Write-host " modules" $((Get-Module -All | Measure-Object -line).Lines)
