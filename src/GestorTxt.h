#ifndef GESTOR_TXT_H
#define GESTOR_TXT_H

#include "GestorArchivo.h"

class GestorTxt : public GestorArchivo {
public:
    GestorTxt();

    bool crearArchivo(string &ruta, map<int, ProgramaAcademico *> &mapaProgramaAcademico, vector<string> etiquetasColumnas) override;
    bool crearArchivoBuscado(string &ruta, list<ProgramaAcademico *> &programasBuscados, vector<string> etiquetasColumnas) override;
    bool crearArchivoExtra(string &ruta, vector<vector<string>> datosAImprimir) override;
};

#endif // GESTOR_TXT_H
