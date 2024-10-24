#ifndef GESTOR_JSON_H
#define GESTOR_JSON_H

#include "Consolidado.h"
#include "GestorArchivo.h"
#include "GestorCsv.h"
#include "ProgramaAcademico.h"
#include "Settings.h"

class GestorJson : public GestorArchivo {
   public:
    GestorJson() = default;
    bool crearArchivo(string &ruta,map<int, ProgramaAcademico *> &mapaProgramaAcademico);
    bool crearArchivoBuscados(string &ruta, list<ProgramaAcademico *> &programaBuscados);
    bool crearArchivoExtra(string &ruta);
};

#endif