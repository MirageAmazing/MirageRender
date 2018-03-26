Write-Host '****************************************'
Write-Host 'MERender build begin'
Write-Host '****************************************'

Set-Location ../

if( -not (Test-Path MERender_Build_Windows) )
{
    Write-Host 'This dictionary not here!'
    New-Item ./MERender_Build_Windows -ItemType Directory
}
Set-Location ./MERender_Build_Windows

#cmake -G "Visual Studio 15 2017 Win64" ../MirageRender
cmake -G "Visual Studio 14 2015 Win64" ../MirageRender

Write-Host '****************************************'
Write-Host 'MERender build over'
Write-Host '****************************************'

Set-Location ../MirageRender