cmake_minimum_required(VERSION 3.19)

set(CMAKE_CXX_STANDARD 17)
SET(CMAKE_C_COMPILER C:\\\\MinGW\\\\bin\\\\gcc)
SET(CMAKE_CXX_COMPILER C:\\\\MinGW\\\\bin\\\\g++)
project(SNIES_extractor_V2)

include(CTest)
enable_testing()


add_executable(SNIES_extractor_V2 src/Settings.h src/ProgramaAcademico.h 
src/ProgramaAcademico.cpp src/Consolidado.h src/Consolidado.cpp src/GestorCsv.h src/GestorCsv.cpp 
src/SNIESController.h src/SNIESController.cpp src/View.h src/View.cpp src/main.cpp
src/GestorArchivo.h src/GestorArchivo.cpp src/GestorJSON.h src/GestorJSON.cpp src/GestorTxt.h src/GestorTxt.cpp
src/Settings.cpp)

