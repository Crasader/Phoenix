﻿<##########################################################################################
* configure.ps1
* Copyright (C) 2014 The ForceStudio All Rights Reserved.
* Note: Phoeinx Configure PowerShell Script
* E-mail:<forcemz@outlook.com>
* @2014.08
###########################################################################################>
$PBVMAX=1
$PBVMIN=0
$PBVPATCH=0
$PBVBUILD=1
$PBRevision=115
$PhoenixBuildSystemVersion = "${PBVMAX}.${PBVMIN}.${PBVPATCH}.${PBVBUILD}"
$Host.UI.RawUI.WindowTitle ="Phoenix Configure TaskScheduler |PowerShell"

Function USAGE
{
    Write-Host "OVERVIEW: Phoeinx Configure Script Assistant"
    Write-Host "USAGE: configure.ps1 [options] <input> `n"
    Write-Host "OPTIONS:"
    Write-Host "`t--build=release|debug"
    Write-Host "`t--prefix=folder"
}

Function PrintVersion
{
   Write-Host "Phoeinx Configure Script Assistant"
   Write-Host "Phoenix Build System version: ${PhoenixBuildSystemVersion}  (${PBRevision}.Revision)"
   Write-Host "Copyright © 2014 The Force Studio .All Rights Reserved."
}

IF($args.Count -ge 1)
{
   IF([System.String]::Compare($args[0],"--help",$true) -eq 0)
   {
    USAGE
    $Enkey=[System.Console]::ReadKey()
    Exit

   }ELSEIF([System.String]::Compare($args[0],"--version",$true) -eq 0)
   {
   PrintVersion
   $Enkey=[System.Console]::ReadKey()
   Exit
   }
}
<#

Import-Module BitsTransfer
$url = 'http://dldir1.qq.com/qqfile/qq/QQ5.3/10702/QQ5.3.exe'
Start-BitsTransfer $url D:\QQ5.3.exe
Invoke-Item D:\QQ5.3.exe

#>

#Write-Host "Start Configure Phoenix Pro Text Editor Build Environment"
