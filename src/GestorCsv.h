#ifndef GESTOR_CSV_H
#define GESTOR_CSV_H

#include "Consolidado.h"
#include "GestorArchivo.h"
#include "ProgramaAcademico.h"
#include "Settings.h"

using std::ifstream;
using std::invalid_argument;
using std::list;
using std::map;
using std::ofstream;
using std::string;
using std::stringstream;
using std::vector;

class GestorCsv : public GestorArchivo {
   private:
    string DELIMITADOR;

   public:
    GestorCsv();
    // Mantenimiento: Se puede mejorar la firma y nombre de los metodos para que
    // sea mÃ¡s descriptiva
    bool crearArchivo(string &ruta,map<int, ProgramaAcademico *> &mapadeProgramasAcademicos,vector<string> etiquetasColumnas);
    bool crearArchivoBuscados(string &ruta,list<ProgramaAcademico *> &programasBuscados,vector<string> etiquetasColumnas);
    bool crearArchivoExtra(string &ruta);
};

#endif