#ifndef SETTINGS_H
#define SETTINGS_H
#include <string>

using std::string;

class Settings {
    public:
        static const string BASE_PATH;
        static const string OUT_PATH;
        static const string LOGS_FILE_PATH;
        static const string PROGRAMAS_FILTRAR_FILE_PATH;
        static const string ADMITIDOS_FILE_PATH;
        static const string MATRICULADOS_FILE_PATH;
        static const string MATRICULADOS_PRIMERSEMESTRE_FILE_PATH;
        static const string INSCRITOS_FILE_PATH;
        static const string GRADUADOS_FILE_PATH;
        static const string INFORME_FILE_PATH;
        static const char DELIMITADOR;
        static const int COLUMNAS_CONSOLIDADOS;
        static const int DATOS_ACADEMICOS;
};

#endif