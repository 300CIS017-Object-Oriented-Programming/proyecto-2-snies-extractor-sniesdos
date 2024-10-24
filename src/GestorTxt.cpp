#include "GestorTxt.h"
#include <fstream>
#include <iostream>

bool GestorTxt::crearArchivo(string &ruta, map<int, ProgramaAcademico *> &mapaProgramaAcademico, vector<string> *etiquetasColumnas) {
    bool estadoCreacion = false;
    string rutaCompleta = ruta + "resultados.txt";
    ofstream archivoResultados(rutaCompleta);

    if (archivoResultados.is_open()) {
        for (const auto &etiqueta : etiquetasColumnas) {
            archivoResultados << etiqueta << "\t";
        }
        archivoResultados << "GRADUADOS\tINSCRITOS\tMATRICULADOS\tNEOS\n";

        for (const auto &programa : mapaProgramaAcademico) {
            for (int i = 0; i < 8; i++) {
                Consolidado *consolidado = programa.second->getConsolidado(i);
                archivoResultados << programa.second->getCodigoDeLaInstitucion() << "\t"
                                  << consolidado->getAdmitidos() << "\t"
                                  << consolidado->getGraduados() << "\t"
                                  << consolidado->getInscritos() << "\t"
                                  << consolidado->getMatriculados() << "\n";
            }
        }
        estadoCreacion = true;
        std::cout << "Archivo TXT creado en: " << rutaCompleta << std::endl;
    }

    archivoResultados.close();
    return estadoCreacion;
}

bool GestorTxt::crearArchivoBuscado(string &ruta, list<ProgramaAcademico *> &programasBuscados, vector<string> *etiquetasColumnas) {
    bool estadoCreacion = false;
    string rutaCompleta = ruta + "buscados.txt";
    ofstream archivoBuscados(rutaCompleta);

    if (archivoBuscados.is_open()) {
        for (const auto &etiqueta : etiquetasColumnas) {
            archivoBuscados << etiqueta << "\t";
        }
        archivoBuscados << "GRADUADOS\tINSCRITOS\tMATRICULADOS\tNEOS\n";

        for (auto &programa : programasBuscados) {
            for (int i = 0; i < 8; i++) {
                Consolidado *consolidado = programa->getConsolidado(i);
                archivoBuscados << programa->getCodigoDeLaInstitucion() << "\t"
                                << consolidado->getAdmitidos() << "\t"
                                << consolidado->getGraduados() << "\t"
                                << consolidado->getInscritos() << "\t"
                                << consolidado->getMatriculados() << "\n";
            }
        }
        estadoCreacion = true;
        std::cout << "Archivo TXT de programas buscados creado en: " << rutaCompleta << std::endl;
    }

    archivoBuscados.close();
    return estadoCreacion;
}

bool GestorTxt::crearArchivoExtra(string &ruta, vector<vector<string>> *datosAImprimir) {
    bool estadoCreacion = false;
    string rutaCompleta = ruta + "extras.txt";
    ofstream archivoExtra(rutaCompleta);

    if (archivoExtra.is_open()) {
        for (const auto &fila : datosAImprimir) {
            for (const auto &dato : fila) {
                archivoExtra << dato << "\t";
            }
            archivoExtra << "\n";
        }
        estadoCreacion = true;
        std::cout << "Archivo TXT de extras creado en: " << rutaCompleta << std::endl;
    }

    archivoExtra.close();
    return estadoCreacion;
}
