@echo off
setlocal
   set PRG_DEF=lista-linear-encadeada
   set PRG=%1
   if "%PRG%"=="" echo Assumindo PRG default:%PRG_DEF%.c & SET PRG=%PRG_DEF%
   if exist "./a.exe" echo J� existe um programa compilado, fazendo backup... & move ./a.exe ./a.exe.bak
   echo Compilando fonte %PRG% & call gcc %PRG%.c
   if not exist "./a.exe" echo Falhou a compila��o & goto :Fim
   echo Renomeando fonte compilado & move ./a.exe %PRG%.exe
:Fim
endlocal
