#include "Settings.h"
// Declaración:
// Inicialización: La inicialización de estas variables se realiza fuera de la clase. 
// Esto es necesario porque las variables estáticas deben ser definidas en un solo lugar en el archivo de implementación (o en el mismo archivo, pero fuera de la clase) para que el compilador sepa cuánto espacio reservar en memoria.
string Settings::BASE_PATH = "C:/SNIES_EXTRACTOR/inputs/";
string Settings::DELIMITADOR = ";";
string Settings::PROGRAMAS_FILTRAR_FILE_PATH = "";
string Settings::ADMITIDOS_FILE_PATH = BASE_PATH + "admitidos";
string Settings::MATRICULADOS_FILE_PATH = BASE_PATH + "matriculados";
string Settings::INSCRITOS_FILE_PATH = BASE_PATH + "inscritos";
string Settings::GRADUADOS_FILE_PATH = BASE_PATH + "graduados";

void Settings::setRutaBase(const string& nuevaRutaBase){
    BASE_PATH = nuevaRutaBase;
    ADMITIDOS_FILE_PATH = BASE_PATH + "admitidos";
    MATRICULADOS_FILE_PATH = BASE_PATH + "matriculados";
    INSCRITOS_FILE_PATH = BASE_PATH + "inscritos";
    GRADUADOS_FILE_PATH = BASE_PATH + "graduados";
}
void Settings::setAnioProgramas(string anioProgramas){
    PROGRAMAS_FILTRAR_FILE_PATH = BASE_PATH + "admitidos"+anioProgramas+".csv";
}
void Settings::setDelimitador(const char& delimitador){
    DELIMITADOR = delimitador;
}


