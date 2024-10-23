#ifndef GESTOR_JSON_H
#define GESTOR_JSON_H


#include "Settings.h"
#include "GestorCsv.h"
#include "Consolidado.h"
#include "GestorArchivo.h"
#include "ProgramaAcademico.h"


class GestorJson : public GestorArchivo{
public:
    GestorJson() = default;
    void escribirEtiquetasJson(nlohmann::json &etiquetaJson, string &codigoSnies, string &nombrePrograma, vector<vector<string>> &matrizEtiquetas, int minPosEtiqueta, int maxPosEtiqueta);
    void escribirProgramasJson(nlohmann::json &jsonData, string &nombrePrograma, vector<vector<string>> &matrizEtiqueta, ProgramaAcademico * programaActual, string &codigoSnies, vector<string> &atributosPrograma);
    void imprimirConsolidadosJson(nlohmann::json &jsonData, ProgramaAcademico* programaActual, vector<vector<string>> &matrizEtiqueta, vector<string> &atributosPrograma);
    bool crearArchivo(string &ruta, map<int,ProgramaAcademico*> &mapaProgramaAcademico, vector<vector<string>> & matrizEtiquetas);
    bool crearArchivoBuscados(string &ruta, list<ProgramaAcademico*> &programaBuscados, vector<vector<string>> & matrizEtiquetas);
    
};


#endif