
#include "ProgramaAcademico.h"
#include "Consolidado.h"

using std::string;

ProgramaAcademico::~ProgramaAcademico() {
    for (auto const &[key, value] : consolidados) {
        delete value;
    }
}

void ProgramaAcademico::setDato(string const &atributo, string valor) {
    datos[atributo] = std::move(valor);
}

string ProgramaAcademico::getDato(string const &atributo) {
    return datos[atributo];
}

bool ProgramaAcademico::sinMatriculasNuevas() const {
    bool sinMatriculas = false;
    int contador = 0;
    auto it = consolidados.begin();
    while (it != consolidados.end() && !sinMatriculas) {
        if (it->second->getMatriculados() == 0) {
            contador++;
            if (contador == 3) {
                sinMatriculas = true;
            }
        } else {
            contador = 0;
        }
        ++it;
    }
    return sinMatriculas;
}

void ProgramaAcademico::addConsolidado(int semestre, Consolidado *consolidado) {
    consolidados[semestre] = consolidado;
}

/*
void ProgramaAcademico::mostrarMatriculadosConsolidado(int anio) {
    consolidados[semestre]->mostrarMatriculados();
}

void ProgramaAcademico::mostrarDataConsolidado(int semestre) {
    consolidados[semestre]->mostrarData();
}
*/



