#include "Settings.h"

static string BASE_PATH = "C:/SNIES_EXTRACTOR/inputs/";
static string OUT_PATH = "C:/SNIES_EXTRACTOR/outputs/";
static string LOGS_FILE_PATH = "C:/SNIES_EXTRACTOR/logs/log.txt";
static string PROGRAMAS_FILTRAR_FILE_PATH = BASE_PATH + "programas.csv";
static string ADMITIDOS_FILE_PATH = BASE_PATH + "admitidos";
static string MATRICULADOS_FILE_PATH = BASE_PATH + "matriculados";
static string MATRICULADOS_PRIMERSEMESTRE_FILE_PATH = BASE_PATH + "matriculadosPrimerSemestre";
static string INSCRITOS_FILE_PATH = BASE_PATH + "inscritos";
static string GRADUADOS_FILE_PATH = BASE_PATH + "graduados";
static string INFORME_FILE_PATH = BASE_PATH + "informe.txt";
static string DELIMITADOR = ";";

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

