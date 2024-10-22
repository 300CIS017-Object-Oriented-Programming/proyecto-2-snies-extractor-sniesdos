#include "View.h"

// Mantenimiento: Implementar la lectura de las rutas de los archivos CSV desde un
// archivo de configuración
View::View(){
    controlador = SNIESController();
}

string View::obtenerAnoValido(const string& mensaje) {
    string ano;
    int intento = 0;

    while (!(isConvetibleToInt(ano))) {
        if (intento > 0) {
            cout << "El valor ingresado fue invalido!" << endl;
            cout << "Por favor ingrese un valor valido." << endl;
        }
        cout << mensaje << endl;
        cin >> ano;
        intento++;
    }
    return ano;
}

void View::ordenarAnios(string& anio1, string& anio2) {
    if (stoi(anio1) > stoi(anio2)) {
        swap(anio1, anio2);
    }
}

bool View::mostrarPantallaBienvenido() {
    bool seHizoParametrizado = false;

    cout << "Bienvenido al SNIES-Extractor!" << endl;
    cout << "=========================================" << endl;
    cout << "Recuerde que para el correcto funcionamiento del programa tuvo que haber parametrizado" << endl;
    cout << "antes la carpeta SNIES_EXTRACTOR en el disco duro C:, con sus respectivas carpetas inputs y outputs" << endl;
    cout << "y todos los archivo CSV del SNIES." << endl;
    cout << "Si ya hizo esto, escriba 'Y', de lo contrario 'N', y Enter: " << endl;

    char userAnswer = 'Y';
    userAnswer = static_cast<char>(tolower(userAnswer));

    if (userAnswer == 'y') {
        seHizoParametrizado = true;

        cout << "A continuacion se procesaran los datos de los programas academicos seleccionados en /programas.csv..." << endl;

        string anio1 = obtenerAnoValido("Escriba el primer ano de busqueda:");
        string anio2 = obtenerAnoValido("Escriba el segundo ano de busqueda:");

        // Usar el metodo ordenarAnios para asegurar el orden correcto
        ordenarAnios(anio1, anio2);

        cout << "Procesando datos ..." << endl;
        controlador.procesarDatosCsv(anio1, anio2);
        cout << "Datos procesados con exito!" << endl;
    }

    return seHizoParametrizado;
}


void View::salirDePrograma(){
    cout << "Cerrando programa..." << endl;
    cout << "Recuerde revisar la carpeta de outputs para los archivos .csv exportados" << endl;
    cout << "Programa Cerrado con exito!" << endl;
}


void View::mostrarDatosProgramaAcademico() {
    char userAnswer;
    cout << "A continuacion vamos a mostrar datos relevantes de los programas academicos seleccionados" << "\n"
         << endl;
    cout << "Desea Convertir los datos a un archivo CSV?(Y/N): " << endl;
    cin >> userAnswer;

    userAnswer = static_cast<char>(tolower(static_cast<unsigned char>(userAnswer)));
    cout << endl;

    try {
        if (userAnswer == 'y') {
            controlador.calcularDatosExtra(true);
        } else if (userAnswer == 'n') {
            controlador.calcularDatosExtra(false);
        } else {
            throw invalid_argument("Entrada no válida");
        }
    } catch (const invalid_argument &e) {
        cout << "|ERROR| Entrada no válida, por favor ingrese 'Y' o 'N'." << endl;
        // No hace nada si la entrada no es válida
    }
}

void View::filtrarPorPalabrasClaveYFormacion()
{

    char userAnswer = 'y', opcionCSV;
    string palabraClave;
    bool convertirCSV;
    int idFormacionAcademica;

    while (userAnswer == 'y')
    {
        cout << "Desea hacer una busqueda por palabra clave del nombre del programa(Y/N): " << endl;
        cin >> userAnswer;
        cout << endl;
        userAnswer = tolower(userAnswer);

        // Alta complejidad ciclomática, refactorizar
        if (userAnswer == 'y')
        {
            cout << "Deseas convertir convertir los datos del programa academico a un CSV?(Y/N): " << endl;
            cin >> opcionCSV;
            cout << endl;
            opcionCSV = tolower(opcionCSV);

            if (opcionCSV == 'y')
            {
                convertirCSV = true;
            }

            else
            {
                convertirCSV = false;
            }
            // Coesión y Organización: Baja coesión, este metodo hace cosas que no debería,
            // separar en métodos más pequeños
            cout << "Escriba la palabra clave para buscar los programas por nombre:" << endl;
            cin >> palabraClave;
            cout << endl;

            cout << "Seleccione un nivel de formacion para filtrar: \n 1->Especializacion Universitaria\n 2->Maestria\n 3->Doctorado\n 4->Formacion Tecnica Profesional \n 5->Tecnologico\n 6->Universitario\n 7->Especializacion Tecnico Profesional\n 8->Especializacion Tecnologica\n 10->Especializacion Medico Quirurgica\n " << endl;
            cin >> idFormacionAcademica;
            cout << "\n";
            while ((idFormacionAcademica > 10) || (idFormacionAcademica == 9) || (idFormacionAcademica < 1))
            {
                cout << "Seleccione una opcion entre 1-10 excluyendo el 9\n"
                     << endl;
                cin >> idFormacionAcademica;
            }

            controlador.buscarProgramas(convertirCSV, palabraClave, idFormacionAcademica);
        }
    }
}

bool View::isConvetibleToInt(const string &str)
{
    try
    {
        std::size_t pos = 0;
        // Verificamos si se ha convertido toda la cadena
        return pos == str.length();
    }
    catch (const std::invalid_argument &)
    {
        // No se pudo convertir: la cadena no es un número válido
        return false;
    }
    catch (const std::out_of_range &)
    {
        // No se pudo convertir: el número está fuera del rango de int
        return false;
    }
}

void View::mostrarMenu(){
    if (bool archivosParametrizados = mostrarPantallaBienvenido()){
        mostrarDatosProgramaAcademico();
        filtrarPorPalabrasClaveYFormacion();
    }
    salirDePrograma();
}