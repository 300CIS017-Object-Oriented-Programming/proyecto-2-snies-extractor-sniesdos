#include "GestorArchivo.h"
#include <iostream>  // For basic logging

GestorArchivo::~GestorArchivo() = default;

bool GestorArchivo::abrirArchivoLectura(const std::string &ruta, std::ifstream &archivo) {
    archivo.open(ruta);
    if (!archivo.is_open()) {
        std::cerr << "Error: No se pudo abrir el archivo para lectura: " << ruta << std::endl;
        return false;
    }
    return true;
}

bool GestorArchivo::abrirArchivoEscritura(const std::string &ruta, std::ofstream &archivo) {
    archivo.open(ruta);
    if (!archivo.is_open()) {
        std::cerr << "Error: No se pudo abrir el archivo para escritura: " << ruta << std::endl;
        return false;
    }
    return true;
}

bool GestorArchivo::archivoVacio(std::ifstream &archivo) {
    return archivo.peek() == std::ifstream::traits_type::eof();
}
