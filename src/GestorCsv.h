#ifndef GESTOR_CSV_H
#define GESTOR_CSV_H

#include "ProgramaAcademico.h"
#include "GestorArchivo.h"
#include "Consolidado.h"
#include "Settings.h"

const int LIMIT_COLUMNAS_FILA = 13;

class GestorCsv {
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
    vector<vector<string>> leerArchivo(string &rutaBase, string &ano, vector<int> &codigosSnies, int colmunaCodigoSnies);
    bool crearArchivo(string &ruta, map<int, ProgramaAcademico *> &mapadeProgramasAcademicos, vector<string> etiquetasColumnas);
    bool crearArchivoBuscados(string &ruta, list<ProgramaAcademico *> &programasBuscados, vector<string> etiquetasColumnas);
};

#endif
