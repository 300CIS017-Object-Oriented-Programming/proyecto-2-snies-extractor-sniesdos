#ifndef GESTOR_TXT_H
#define GESTOR_TXT_H

#include "Settings.h"
#include "GestorCsv.h"
#include "GestorJSON.h"
#include "Consolidado.h"
#include "GestorArchivo.h"
#include "ProgramaAcademico.h"

class GestorTxt : public GestorArchivo {
public:
    // Default constructor
    GestorTxt() = default;
    bool crearArchivo(string &ruta, map<int, ProgramaAcademico *> &mapaProgramaAcademico, vector<string> etiquetasColumnas);
    bool crearArchivoExtra(string &ruta, vector<string> etiquetasColumnas);

};

#endif