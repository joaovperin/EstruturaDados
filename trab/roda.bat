@echo off
setlocal
   set PRG_DEF=lista-linear-encadeada
   set PRG=%1
   if "%PRG%"=="" echo Assumindo PRG default:%PRG_DEF%.exe & SET PRG=%PRG_DEF%
   if not exist "./%PRG%.exe" echo Programa não existente & goto :Fim
   echo. Rodando %PRG%.exe & call %PRG%.exe
:Fim
endlocal
