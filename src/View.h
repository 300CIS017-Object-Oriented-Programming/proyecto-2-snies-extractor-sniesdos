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
    void buscarPorPalabraClaveYFormacion();
    void salir();
public:
    View();
    ~View();
    // Estructura: El View debería tener solo una función pública.
    void mostrarMenu();
};

#endif