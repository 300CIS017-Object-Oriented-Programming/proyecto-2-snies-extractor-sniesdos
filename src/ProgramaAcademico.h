#ifndef PROGRAMA_ACADEMICO_H
#define PROGRAMA_ACADEMICO_H

#include <string>
#include <map>
#include "Consolidado.h"

using std::string;
using std::map;

class ProgramaAcademico {
    map<string, string> datos;
    map<int, Consolidado *> consolidados;

public:
    ProgramaAcademico() = default;
    ~ProgramaAcademico();
    void setDato(string const &, string);
    string getDato(string const &);
    bool sinMatriculasNuevas() const;
    void addConsolidado(int, Consolidado *);
    void mostrarMatriculadosConsolidado(int);
    void mostrarDataConsolidado(int);
};

#endif