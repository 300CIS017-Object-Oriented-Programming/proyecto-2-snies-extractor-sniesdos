#ifndef GESTOR_JSON_H
#define GESTOR_JSON_H

#include "GestorArchivo.h"
#include "json.hpp"
using json = nlohmann::json;

using namespace std;
class GestorJson : public GestorArchivo {
public:
    GestorJson();

    bool crearArchivo(string &ruta, map<int, ProgramaAcademico *> &mapaProgramaAcademico, vector<string> etiquetasColumnas) override;
    bool crearArchivoBuscado(string &ruta, list<ProgramaAcademico *> &programasBuscados, vector<string> etiquetasColumnas) override;
    bool crearArchivoExtra(string &ruta, vector<vector<string>> datosAImprimir) override;
};

#endif // GESTOR_JSON_H
