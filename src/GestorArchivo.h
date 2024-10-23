//Gestor archivo
#ifndef GESTOR_ARCHIVO_H
#define GESTOR_ARCHIVO_H

#include "ProgramaAcademico.h"
#include "Consolidado.h"
#include "Settings.h"
#include <algorithm>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <list>
#include <map>

using std::string;
using std::vector;
using std::map;
using std::list;
using std::ofstream;
using std::ifstream;
using std::stringstream;
using std::invalid_argument;


class GestorArchivo{
    public:
    GestorArchivo() = default;
    virtual ~GestorArchivo()= default;
    virtual vector<int> leerEntrada(string &ruta);
    virtual vector<vector<string>> leerArchivo(string &rutaBase, vector<string> &etiquetasColumnas, vector<int> &codigoSnies);

    virtual bool crearArchivo(string &ruta, map<int, ProgramaAcademico *> &mapaProgramasAcademicos, vector<vector<string>> &matrizEtiquetas) = 0;
    virtual bool crearArchivoBuscado(string &ruta, list<ProgramaAcademico *> &programaBuscados, vector<vector<string>> &matrizEtiquetas) = 0;
};

#endif 