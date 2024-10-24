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


    class GestorArchivo{
    public:
        GestorArchivo() = default;
        virtual ~GestorArchivo()= default;
        virtual bool crearArchivo(string &ruta, map<int, ProgramaAcademico *> &mapaProgramaAcademico, vector<string> etiquetasColumnas) = 0;
        virtual bool crearArchivoBuscado(string &ruta, list<ProgramaAcademico *> &programaBuscados, vector<string> etiquetasColumnas) = 0;
        virtual bool crearArchivoExtra(string &ruta, vector<vector<string>> datosAImprimir) = 0;
    protected:
        bool abrirArchivoLectura(const string &ruta, ifstream &archivo);
        bool abrirArchivoEscritura(const string &ruta, ofstream &archivo);
        bool archivoVacio(ifstream &archivo);

    };

#endif