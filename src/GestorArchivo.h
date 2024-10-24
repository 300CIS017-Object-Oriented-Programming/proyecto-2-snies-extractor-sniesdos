// Gestor archivo
#ifndef GESTOR_ARCHIVO_H
#define GESTOR_ARCHIVO_H

#include <algorithm>
#include <fstream>
#include <list>
#include <map>
#include <sstream>
#include <string>
#include <vector>

#include "Consolidado.h"
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

class GestorArchivo {
   protected:
    Settings settings;
    vector<string> leerEncabezado(ifstream &archivo);
    vector<string> leerFila(ifstream &archivo, int limiteColumnas = 13);
    bool abrirArchivo(string &ruta, ifstream &archivo);
    bool filaRelevante(const vector<string> &fila, vector<int> &codigoSnies);
    void leerFilasAdicionales(ifstream &archivo,vector<vector<string>> &matrizResult);

   public:
    GestorArchivo();
    vector<int> leerProgramasCsv(string &ruta);
    vector<vector<string>> leerArchivo(string &rutaBase, string &ano,vector<int> &codigosSnies,int colmunaCodigoSnies);
    bool crearArchivo(string &ruta,map<int, ProgramaAcademico *> &mapadeProgramasAcademicos,vector<string> etiquetasColumnas);
    bool crearArchivoBuscados(string &ruta,list<ProgramaAcademico *> &programasBuscados,vector<string> etiquetasColumnas);
};

#endif
