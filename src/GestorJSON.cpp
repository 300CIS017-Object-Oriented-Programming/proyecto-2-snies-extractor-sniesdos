#include "GestorJson.h"
#include <fstream>
#include <iostream>
#include <string>

GestorJson::GestorJson() {}

bool GestorJson::crearArchivo(string &ruta, map<int, ProgramaAcademico *> &mapaProgramaAcademico, vector<string> etiquetasColumnas) {
    bool estadoCreacion = false;
    string rutaCompleta = ruta + "resultados.json";
    json archivoJson;

    for (auto &programa : mapaProgramaAcademico) {
        json consolidadoJson;
        for (int i = 0; i < 8; i++) {
            Consolidado *consolidado = programa.second->getConsolidado(i);
            consolidadoJson.push_back({
                {"IdSexo", consolidado->getIdSexo()},
                {"Sexo", consolidado->getSexo()},
                {"Ano", consolidado->getAno()},
                {"Semestre", consolidado->getSemestre()},
                {"Admitidos", consolidado->getAdmitidos()},
                {"Graduados", consolidado->getGraduados()},
                {"Inscritos", consolidado->getInscritos()},
                {"Matriculados", consolidado->getMatriculados()},
                {"Neos", consolidado->getMatriculadosPrimerSemestre()}
            });
        }
        archivoJson[to_string(programa.first)] = consolidadoJson;
    }

    std::ofstream archivoResultados(rutaCompleta);
    if (archivoResultados.is_open()) {
        archivoResultados << archivoJson.dump(4);  // Pretty print with 4 spaces
        estadoCreacion = true;
        std::cout << "Archivo JSON creado en: " << rutaCompleta << std::endl;
    }

    archivoResultados.close();
    return estadoCreacion;
}

bool GestorJson::crearArchivoBuscado(string &ruta, list<ProgramaAcademico *> &programasBuscados, vector<string> etiquetasColumnas) {
    bool estadoCreacion = false;
    string rutaCompleta = ruta + "buscados.json";
    json archivoJson;

    for (auto &programa : programasBuscados) {
        json consolidadoJson;
        for (int i = 0; i < 8; i++) {
            Consolidado *consolidado = programa->getConsolidado(i);
            consolidadoJson.push_back({
                {"IdSexo", consolidado->getIdSexo()},
                {"Sexo", consolidado->getSexo()},
                {"Ano", consolidado->getAno()},
                {"Semestre", consolidado->getSemestre()},
                {"Admitidos", consolidado->getAdmitidos()},
                {"Graduados", consolidado->getGraduados()},
                {"Inscritos", consolidado->getInscritos()},
                {"Matriculados", consolidado->getMatriculados()},
                {"Neos", consolidado->getMatriculadosPrimerSemestre()}
            });
        }
        archivoJson[to_string(programa->getCodigoSniesDelPrograma())] = consolidadoJson;
    }

    std::ofstream archivoBuscados(rutaCompleta);
    if (archivoBuscados.is_open()) {
        archivoBuscados << archivoJson.dump(4);
        estadoCreacion = true;
        std::cout << "Archivo JSON de programas buscados creado en: " << rutaCompleta << std::endl;
    }

    archivoBuscados.close();
    return estadoCreacion;
}

bool GestorJson::crearArchivoExtra(string &ruta, vector<vector<string>> datosAImprimir) {
    bool estadoCreacion = false;
    string rutaCompleta = ruta + "extras.json";
    json archivoJson;

    for (const auto &fila : datosAImprimir) {
        archivoJson.push_back(fila);
    }

    std::ofstream archivoExtra(rutaCompleta);
    if (archivoExtra.is_open()) {
        archivoExtra << archivoJson.dump(4);
        estadoCreacion = true;
        std::cout << "Archivo JSON de extras creado en: " << rutaCompleta << std::endl;
    }

    archivoExtra.close();
    return estadoCreacion;
}
