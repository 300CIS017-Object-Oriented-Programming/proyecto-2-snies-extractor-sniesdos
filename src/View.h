#ifndef VIEW_H
#define VIEW_H

#include "SNIESController.h"

using namespace std;

class View {
private:
    SNIESController controlador;
    bool isConvetibleToInt(const string &);
    bool mostrarPantallaBienvenido();
    void mostrarDatosExtra();
    void filtrarPorPalabrasClaveYFormacion();
    void salirDePrograma();
    string obtenerAnoValido(const string&);
    void ordenarAnios(string&, string&);
public:
    View();
    ~View() = default;
    // Estructura: El View debería tener solo una función pública.
    void mostrarMenu();
};

#endif