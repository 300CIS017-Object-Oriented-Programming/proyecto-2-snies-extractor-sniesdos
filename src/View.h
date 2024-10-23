#ifndef VIEW_H
#define VIEW_H

#include "SNIESController.h"

using namespace std;

class View {
private:
    SNIESController controlador;
    bool isConvetibleToInt(const string &);
    bool mostrarPantallaBienvenido();
    void mostrarDatosProgramaAcademico();
    void filtrarPorPalabrasClaveYFormacion();
    static void salirDePrograma();
    string obtenerAnoValido(const string&);
    //void ordenarAnios(string&, string&);

    //void seleccionarOpcionExportar(int);
public:
    View();
    ~View() = default;
    void mostrarMenu();
};

#endif