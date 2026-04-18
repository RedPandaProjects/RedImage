@echo off
mkdir build64
cmake -G "Visual Studio 18 2026" -A x64 -S . -B "build64"
cmake --build build64 --config RELWITHDEBINFO
cmake --build build64 --config Debug
mkdir Library
mkdir Library\Win64
mkdir Library\Win64\Debug
xcopy /Y build64\RedImage\Debug\*.* Library\Win64\Debug
mkdir Library\Win64\Release
xcopy /Y build64\RedImage\RELWITHDEBINFO\*.* Library\Win64\Release
rmdir /S /Q build64