#include "GestorTxt.h"

void GestorTxt::escribirEtiquetas(string &codigoSNIES, string &nombrePrograma, string &fila, string &delimitador, vector<vector<string>> &matrizEtiquetas, int minPosEtiquetas, int maxPosEtiquetas){

}

void GestorTxt::escribirPrograma(string &codigoSNIES, string &nombrePrograma, string &fila, string &delimitador, vector<vector<string>> &matrizEtiquetas, ProgramaAcademico* programaActual){

}

void GestorTxt::imprimirConsolidados(string &fila, ofstream &archivoResultados, string &delimitador,  vector<vector<string>> &matrizEtiqueta, ProgramaAcademico* porgramaActual){

}

void GestorTxt::escribirConsolidado(string &fila, string &delimitador, Consolidado* consolidadoActual, vector<vector<string>> &matrizEtiquetas){

}

GestorTxt::GestorTxt(){

}

bool GestorTxt::crearArchivo(string &ruta, map<int, ProgramaAcademico *> &mapadeProgramasAcademicos, vector<string> etiquetasColumnas){

}

bool GestorTxt::crearArchivoBuscados(string &ruta, list<ProgramaAcademico *> &programasBuscados, vector<string> etiquetasColumnas){
    
}
