#include "Settings.h"

string Settings::BASE_PATH = "C:/SNIES_EXTRACTOR/inputs/";
string Settings::OUT_PATH = "C:/SNIES_EXTRACTOR/outputs/";
string Settings::LOGS_FILE_PATH = "C:/SNIES_EXTRACTOR/logs/log.txt";
string Settings::PROGRAMAS_FILTRAR_FILE_PATH = BASE_PATH + "programas.csv";
string Settings::ADMITIDOS_FILE_PATH = BASE_PATH + "admitidos";
string Settings::MATRICULADOS_FILE_PATH = BASE_PATH + "matriculados";
string Settings::MATRICULADOS_PRIMERSEMESTRE_FILE_PATH = BASE_PATH + "matriculadosPrimerSemestre";
string Settings::INSCRITOS_FILE_PATH = BASE_PATH + "inscritos";
string Settings::GRADUADOS_FILE_PATH = BASE_PATH + "graduados";
string Settings::INFORME_FILE_PATH = BASE_PATH + "informe.txt";
string Settings::DELIMITADOR = ";";

// Implementación de los métodos setters
void Settings::setBasePath(const string& newPath) {
    BASE_PATH = newPath;
    // Actualiza las rutas que dependen de BASE_PATH
    OUT_PATH = BASE_PATH + "outputs";
    LOGS_FILE_PATH = BASE_PATH + "logs/log.txt"; // Actualiza la ruta de logs
    PROGRAMAS_FILTRAR_FILE_PATH = BASE_PATH + "programas.csv";
    ADMITIDOS_FILE_PATH = BASE_PATH + "admitidos";
    MATRICULADOS_FILE_PATH = BASE_PATH + "matriculados";
    MATRICULADOS_PRIMERSEMESTRE_FILE_PATH = BASE_PATH + "matriculadosPrimerSemestre";
    INSCRITOS_FILE_PATH = BASE_PATH + "inscritos";
    GRADUADOS_FILE_PATH = BASE_PATH + "graduados";
    INFORME_FILE_PATH = BASE_PATH + "informe.txt";
}

void Settings::setDelimitador(const string& newDelimitador) {
    DELIMITADOR = newDelimitador; // Modificar el delimitador
}