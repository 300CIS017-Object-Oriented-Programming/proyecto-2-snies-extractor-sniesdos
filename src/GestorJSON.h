#ifndef GESTORJSON_H
#define GESTORJSON_H

#include "GestorArchivos.h"
#include <vector>
#include <string>

class GestorJSON : public GestorArchivos
{
public:
    // Constructor y destructor
    GestorJSON() = default;
    virtual ~GestorJSON() = default;

    // Método para leer un archivo JSON
    std::vector<std::vector<std::string>> leerArchivoJSON(std::string &ruta, std::vector<std::string> &etiquetasColumnas, std::vector<int> &codigosSnies);
};

#endif // GESTORJSON_H