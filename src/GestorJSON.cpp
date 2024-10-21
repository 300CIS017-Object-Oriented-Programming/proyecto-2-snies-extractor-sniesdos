#include "GestorJSON.h"
#include <fstream>
#include <nlohmann/json.hpp>

using json = nlohmann::json;

vector<vector<string>> GestorJSON::leerArchivoJSON(string &ruta, vector<string> &etiquetasColumnas, vector<int> &codigosSnies)
{
    vector<vector<string>> matrizResultado;

    // Abrir el archivo JSON
    ifstream archivoJson(ruta + string(".json"));
    if (!archivoJson.is_open())
    {
        string errorMsg = string("Archivo ") + ruta + string(" no se pudo abrir correctamente");
        throw out_of_range(errorMsg);
    }

    // Leer el contenido del archivo JSON
    json jsonData;
    archivoJson >> jsonData;

    // Procesar el JSON y extraer la información
    // Se asume que jsonData es un array de objetos
    for (const auto &item : jsonData)
    {
        vector<string> filaActual;
        bool codigoCoincide = false;

        // Verificar si el objeto tiene la clave "codigo_snies"
        if (item.contains("codigo_snies"))
        {
            int codigo = item["codigo_snies"];
            if (find(codigosSnies.begin(), codigosSnies.end(), codigo) != codigosSnies.end())
            {
                codigoCoincide = true; // Código SNIES coincide
            }
        }

        // Agregar los datos de interés a la filaActual
        for (const auto &etiqueta : etiquetasColumnas)
        {
            if (item.contains(etiqueta))
            {
                filaActual.push_back(item[etiqueta].get<string>());
            }
        }

        // Solo añadir la fila si el código coincide
        if (codigoCoincide)
        {
            matrizResultado.push_back(filaActual);
        }
    }

    archivoJson.close();
    return matrizResultado;
}