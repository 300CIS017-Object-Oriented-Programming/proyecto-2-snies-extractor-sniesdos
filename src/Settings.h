/**
 * @file Settings.h
 * @brief Este archivo de encabezado define la clase Settings, que contiene variables de ruta de archivo constantes estáticas.
 *
 * La clase Settings se utiliza para almacenar rutas de archivos como constantes estáticas. Estas rutas están destinadas para su uso
 * en toda la aplicación, permitiendo un acceso fácil a las ubicaciones de varios archivos de entrada.
 *
 * Las siguientes constantes estáticas están definidas:
 * - ADMITIDOS_FILE_PATH: Ruta al archivo de entrada "admitidos".
 * - MATRICULADOS_FILE_PATH: Ruta al archivo de entrada "matriculados".
 * - INSCRITOS_FILE_PATH: Ruta al archivo de entrada "inscritos".
 * - PROGRAMAS_FILTRAR_FILE_PATH: Ruta al archivo de entrada "programas filtrar".
 *
 * Nota: Las constantes estáticas deben definirse fuera de la clase para asignar memoria a ellas.
 *
 *
 */

#ifndef SETTINGS_H
#define SETTINGS_H

#include <string>

using std::string;

class Settings {
    public:
        // En la clase Settings, las variables ADMITIDOS_FILE_PATH, MATRICULADOS_FILE_PATH y ETC se declaran como static const std::string. Esto significa que son constantes de tipo string que pertenecen a la clase en lugar de a instancias individuales de la clase.
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
        static const string DELIMITADOR;
        void setBasePath(const string& newPath);
};

#endif