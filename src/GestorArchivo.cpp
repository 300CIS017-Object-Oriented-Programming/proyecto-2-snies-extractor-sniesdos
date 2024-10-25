#include "GestorArchivo.h"
#include <iostream>  // For basic logging


bool GestorArchivo::abrirArchivoLectura(const string &ruta, ifstream &archivo) {
    archivo.open(ruta);
    if (!archivo.is_open()) {
        std::cerr << "Error: No se pudo abrir el archivo para lectura: " << ruta << std::endl;
        return false;
    }
    return true;
}

bool GestorArchivo::abrirArchivoEscritura(const string &ruta, ofstream &archivo) {
    archivo.open(ruta);
    if (!archivo.is_open()) {
        std::cerr << "Error: No se pudo abrir el archivo para escritura: " << ruta << endl;
        return false;
    }
    return true;
}

bool GestorArchivo::archivoVacio(ifstream &archivo) {
    return archivo.peek() == ifstream::traits_type::eof();
}