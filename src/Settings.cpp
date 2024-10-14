#include "Settings.h"

const string BASE_PATH = "C:/SNIES_EXTRACTOR/inputs/";
const string OUT_PATH = "C:/SNIES_EXTRACTOR/outputs/";
const string LOGS_FILE_PATH = "C:/SNIES_EXTRACTOR/logs/log.txt";
const string PROGRAMAS_FILTRAR_FILE_PATH = BASE_PATH + "programas.csv";
const string ADMITIDOS_FILE_PATH = BASE_PATH + "admitidos";
const string MATRICULADOS_FILE_PATH = BASE_PATH + "matriculados";
const string MATRICULADOS_PRIMERSEMESTRE_FILE_PATH = BASE_PATH + "matriculadosPrimerSemestre";
const string INSCRITOS_FILE_PATH = BASE_PATH + "inscritos";
const string GRADUADOS_FILE_PATH = BASE_PATH + "graduados";
const string INFORME_FILE_PATH = BASE_PATH + "informe.txt";
const string DELIMITADOR = ";";

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

void Settings::setDelimitador(const std::string& newDelimitador) {
    DELIMITADOR = newDelimitador; // Modificar el delimitador
}