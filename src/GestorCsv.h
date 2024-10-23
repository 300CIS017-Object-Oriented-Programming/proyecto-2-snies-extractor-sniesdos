#ifndef GESTOR_CSV_H
#define GESTOR_CSV_H

#include "ProgramaAcademico.h"
#include "GestorArchivo.h"
#include "Consolidado.h"
#include "Settings.h"


using std::string;
using std::vector;
using std::map;
using std::list;
using std::ofstream;
using std::ifstream;
using std::stringstream;
using std::invalid_argument;

const int LIMIT_COLUMNAS_FILA = 13;

class GestorCsv: public GestorArchivo {
private:
    Settings settings;
    string DELIMITADOR;
    vector<string> leerEncabezado(ifstream &archivo);
    vector<string> leerFila(ifstream &archivo, int limitecolumnas = LIMIT_COLUMNAS_FILA);
    bool abrirArchivo(string &ruta, ifstream &archivo);
    bool filaRelevante(const vector<string> &fila, vector<int> &codigoSnies);
    void leerFilasAdicionales(ifstream &archivo, vector<vector<string>> &matrizResult);

public:
    GestorCsv();
    vector<int> leerProgramasCsv(string &ruta);
    // Mantenimiento: Se puede mejorar la firma y nombre de los metodos para que sea más descriptiva
    vector<vector<string>> leerArchivo(string &rutaBase, string &ano, vector<int> &codigosSnies, int colmunaCodigoSnies);
    bool crearArchivo(string &ruta, map<int, ProgramaAcademico *> &mapadeProgramasAcademicos, vector<string> etiquetasColumnas);
    bool crearArchivoBuscados(string &ruta, list<ProgramaAcademico *> &programasBuscados, vector<string> etiquetasColumnas);
};

#endif
