#include "GestorJSON.h"

GestorJson::~GestorJson(){}
void GestorJson::escribirEtiquetasJson(nlohmann::json &etiquetaJson, string &codigoSnies, string &nombrePrograma, vector<vector<string>> &matrizEtiquetas, int minPosEtiqueta, int maxPosEtiqueta){

}

void GestorJson::escribirProgramasJson(nlohmann::json &jsonData, string &nombrePrograma, vector<vector<string>> &matrizEtiqueta, ProgramaAcademico * programaActual, string &codigoSnies, vector<string> &atributosPrograma){

}

void GestorJson::imprimirConsolidadosJson(nlohmann::json &jsonData, ProgramaAcademico* programaActual, vector<vector<string>> &matrizEtiqueta, vector<string> &atributosPrograma){

}

bool GestorJson::crearArchivo(string &ruta, map<int,ProgramaAcademico*> &mapaProgramaAcademico, vector<vector<string>> & matrizEtiquetas){

}

bool GestorJson::crearArchivoBuscados(string &ruta, list<ProgramaAcademico*> &programaBuscados, vector<vector<string>> & matrizEtiquetas){

}
