#ifndef SNIES_CONTROLLER_H
#define SNIES_CONTROLLER_H

#include <vector>
#include <map>
#include <string>
#include "ProgramaAcademico.h"
#include "GestorCsv.h"
#include "Settings.h"

using std::map;
using std::string;

class SNIESController {
    private:
        map<long, ProgramaAcademico *> programasAcademicos;

        GestorCsv gestorCsvObj;
        Settings settings;

        string rutaProgramasCSV;
        string rutaAdmitidos;
        string rutaGraduados;
        string rutaInscritos;
        string rutaMatriculados;
        string rutaMatriculadosPrimerSemestre;
        string rutaOutput;

    public:
        SNIESController();
        ~SNIESController();
        void procesarDatosCsv(string &, string &);
        void calcularDatosExtra(bool);
        void buscarProgramas(bool, string &, int);
};

#endif
