@rem ---------------------------------------------
@rem This file is need to build app
@rem if you use this file, type batchfile path and type dotnetpath(need dotnet sdk 4.8.)
@rem This project is GPL3.0 license.
@rem made by nrhx, for havent visual studio users.
@rem ---------------------------------------------

@echo off

echo [!]welcome to dotbetbuilds!
echo [!]made by nrhx

set dotnetpath=%1

if "%dotnetpath%"=="" (
	goto :f
)

goto :c

:f
	echo [error] invalid
	exit /b

:c
\t%dotnetpath%\dotnet build c:\
	exit /b
