// After
#ifndef GESTOR_CSV_H
#define GESTOR_CSV_H

#include "GestorBase.h"
#include <string>
#include <vector>
#include <map>
#include <list>
#include <fstream>
#include <unordered_map>
#include <cctype>
#include "ProgramaAcademico.h"

using std::string;
using std::vector;
using std::map;
using std::list;
using std::unordered_map;

class GestorCsv : public GestorBase
{
private:
    string convertirStringFormaEstandar(string &stringIn);
public:
    GestorCsv() = default;
    vector<int> leerProgramasCsv(string &ruta);
    // Mantenimiento: Se puede mejorar la firma y nombre de los metodos para que sea más descriptiva
    vector<vector<string>> leerArchivoPrimera(string &rutaBase, string &ano, vector<int> &codigosSnies);
    vector<vector<string>> leerArchivoSegunda(string &rutaBase, string &ano, vector<int> &codigosSnies);
    vector<vector<string>> leerArchivo(string &rutaBase, string &ano, vector<int> &codigosSnies, int colmunaCodigoSnies);
    bool crearArchivo(string &, map<int, ProgramaAcademico*>&, vector<string>) override;
    bool crearArchivoBuscados(string &, list<ProgramaAcademico*>&, vector<string>) override;
    bool crearArchivoExtra(string &, vector<vector<string>>) override;
    map<string, int> conseguirPosicionesColumnas(string &rutaArchivo);
    int conseguirCantColumnas(map<string, int>);
    string quitarEspacioYAgregarMayus(string cadena);
};

#endif