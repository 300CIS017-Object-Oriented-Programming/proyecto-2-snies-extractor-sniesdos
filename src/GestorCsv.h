#ifndef GESTOR_CSV_H
#define GESTOR_CSV_H

#include <string>
#include <vector>
#include <map>
#include <fstream>
#include <sstream>
#include <list>
#include <unordered_map>
#include <algorithm>
#include "ProgramaAcademico.h"
#include "Consolidado.h"
#include "Settings.h"

using namespace std;

class GestorCsv
{
public:
    GestorCsv() = default;
    unordered_map<std::string,std::string> definirProgramas();
    std::unordered_map<std::string,int> extraerEncabezados(const string& ruta);
    std::vector<std::vector<std::string>> extraerDatos();
    std::unordered_map<std::string,int> extraerIndices();
    void eliminarIndices(std::unordered_map<std::string, int>& indices, std::vector<std::vector<std::string>>& datos);
    vector<int> leerProgramasCsv(string &ruta);
    vector<vector<string>> leerArchivoPrimera(string &rutaBase, string &ano, vector<int> &codigosSnies);
    vector<vector<string>> leerArchivoSegunda(string &rutaBase, string &ano, vector<int> &codigosSnies);
    vector<vector<string>> leerArchivo(string &rutaBase, string &ano, vector<int> &codigosSnies, int colmunaCodigoSnies);
    bool crearArchivo(string &ruta, map<int, ProgramaAcademico *> &mapadeProgramasAcademicos, vector<string> etiquetasColumnas);
    bool crearArchivoBuscados(string &ruta, list<ProgramaAcademico *> &programasBuscados, vector<string> etiquetasColumnas);
    bool crearArchivoExtra(string &ruta, vector<vector<string>> datosAImprimir);
};

#endif