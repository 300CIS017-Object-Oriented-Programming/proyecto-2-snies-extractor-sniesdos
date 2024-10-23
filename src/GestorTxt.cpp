#include "GestorTxt.h"


bool GestorTxt::crearArchivo(string &ruta, map<int, ProgramaAcademico *> &mapaProgramaAcademico, vector<string> etiquetasColumnas) {
    bool estadoCreacion = false;
    string rutaCompleta = ruta +  "resultados.txt";
    ofstream archivoTxt(rutaCompleta);

    if (archivoTxt.is_open()) {
        // Print header
        for (size_t i = 0; i < etiquetasColumnas.size(); i++) {
            archivoTxt << etiquetasColumnas[i] << "\t";
        }
        archivoTxt << "\n";

        // Print data
        for (auto it = mapaProgramaAcademico.begin(); it != mapaProgramaAcademico.end(); ++it) {
            ProgramaAcademico* programa = it->second;
            archivoTxt << programa->getCodigoDeLaInstitucion() << "\t"
                       << programa->getInstitucionDeEducacionSuperiorIes() << "\t"
                       << programa->getNivelAcademico() << "\t"
                       << programa->getProgramaAcademico() << "\n";
        }
        archivoTxt.close();
        estadoCreacion = true;
        cout << "Archivo TXT creado exitosamente en: " << rutaCompleta << endl;
    } else {
        cout << "Error: no se pudo crear el archivo TXT en: " << rutaCompleta << endl;
    }
    return estadoCreacion;
}