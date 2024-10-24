#ifndef SNIES_CONTROLLER_H
#define SNIES_CONTROLLER_H

#include <vector>
#include <map>
#include <string>
#include "ProgramaAcademico.h"
#include "GestorCsv.h"
#include "Settings.h"
#include "Consolidado.h"
#include "GestorCsv.h"
#include "GestorJSON.h"
#include "GestorTxt.h"
#include "GestorArchivo.h"

using std::map;
using std::string;
using std::to_string;

class SNIESController {
    private:
        map<long, ProgramaAcademico *> programasAcademicos;
        vector<string> etiquetasColumnas;

        GestorCsv *gestorCsvObj;
        GestorJson *gestorJsonObj;
        GestorTxt *gestorTxtObj;

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
        void setProgramasAcademicos(vector<vector<string>> &, string &, string &, vector<int> &, int);
        void crearArchivo(map<int, ProgramaAcademico *> &, vector<string> &);
        void procesarDatos(string &, string &);
        void calcularDatosExtra(bool);
        void buscarProgramas(bool, string &, int);
};

#endif