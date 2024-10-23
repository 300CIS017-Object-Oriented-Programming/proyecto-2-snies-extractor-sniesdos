#ifndef GESTOR_ARCHIVO_H
#define GESTOR_ARCHIVO_H

#include "ProgramaAcademico.h"
#include <algorithm>
#include <iostream>
#include <sstream>
#include <fstream>
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

class GestorArchivo {
public:
    virtual ~GestorArchivo() = default;
    virtual vector<int> leerEntrada(string &ruta) = 0;
    virtual vector<vector<string>> leerArchivo(string &rutaBase, vector<string> &etiquetasColumnas, vector<int> &codigoSnies) = 0;
    virtual bool crearArchivo(string &ruta, map<int, ProgramaAcademico *> &mapaProgramasAcademicos, vector<vector<string>> &matrizEtiquetas) = 0;
    virtual bool crearArchivoBuscado(string &ruta, list<ProgramaAcademico *> &programaBuscados, vector<vector<string>> &matrizEtiquetas) = 0;

protected:
    // Common functionality for derived classes
    bool abrirArchivoLectura(const std::string &ruta, std::ifstream &archivo);
    bool abrirArchivoEscritura(const std::string &ruta, std::ofstream &archivo);
    bool archivoVacio(std::ifstream &archivo);
    
};

#endif
