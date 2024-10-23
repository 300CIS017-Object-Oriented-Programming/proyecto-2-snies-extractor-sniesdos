#ifndef GESTOR_TXT_H
#define GESTOR_TXT_H

#include "Settings.h"
#include "GestorCsv.h"
#include "GestorJSON.h"
#include "Consolidado.h"
#include "GestorArchivo.h"
#include "ProgramaAcademico.h"


class GestorTxt : public GestorArchivo{
private:
    void escribirEtiquetas(string &codigoSNIES, string &nombrePrograma, string &fila, string &delimitador, vector<vector<string>> &matrizEtiquetas, int minPosEtiquetas, int maxPosEtiquetas);
    void escribirPrograma(string &codigoSNIES, string &nombrePrograma, string &fila, string &delimitador, vector<vector<string>> &matrizEtiquetas, ProgramaAcademico* programaActual);
    void imprimirConsolidados(string &fila, ofstream &archivoResultados, string &delimitador,  vector<vector<string>> &matrizEtiqueta, ProgramaAcademico* porgramaActual);
    void escribirConsolidado(string &fila, string &delimitador, Consolidado* consolidadoActual, vector<vector<string>> &matrizEtiquetas);
    
public:
    GestorTxt() = default;
    bool crearArchivo(string &ruta, map<int, ProgramaAcademico *> &mapadeProgramasAcademicos, vector<string> etiquetasColumnas);
    bool crearArchivoBuscados(string &ruta, list<ProgramaAcademico *> &programasBuscados, vector<string> etiquetasColumnas);
};


#endif