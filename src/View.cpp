#include "View.h"

View::View()
{
    // NEW quitar estas variables de aquí y del constructor del SNIESController
    //  estas constantes las leerá el SNIESController del archivo de Settings.h
    //  Completar el archivo con el resto de constantes necesarias
    string ruta1 = string("C:/SNIES_EXTRACTOR/inputs/programas.csv");
    string ruta2 = string("C:/SNIES_EXTRACTOR/inputs/admitidos");
    string ruta3 = string("C:/SNIES_EXTRACTOR/inputs/graduados");
    string ruta4 = string("C:/SNIES_EXTRACTOR/inputs/inscritos");
    string ruta5 = string("C:/SNIES_EXTRACTOR/inputs/matriculados");
    string ruta6 = string("C:/SNIES_EXTRACTOR/inputs/matriculadosPrimerSemestre");
    string ruta7 = string("C:/SNIES_EXTRACTOR/outputs/");
    controlador = SNIESController(ruta1, ruta2, ruta3, ruta4, ruta5, ruta6, ruta7);
}

View::~View()
{
    controlador.~SNIESController();
}

bool View::esEntero(const std::string& str) {
    if (str.empty()) return false;

    for (char const &c : str) {
        if (!std::isdigit(c)) {
            return false; 
        }
    }
    return true;
}

bool View::mostrarPantallaBienvenido()
{
    char userAnswer;
    cout << "Bienvenido al SNIES-Extractor!" << endl;
    cout << "====================================================================" << endl;
    cout << "Recuerde: Los archivos deben estar en una carpeta SNIES_EXTRACTOR" << endl;
    cout << "en el disco duro C:, con sus respectivas carpetas inputs y outputs" << endl;
    cout << "y todos los archivo CSV del SNIES." << endl;
    cout << "====================================================================" << endl;
    cout << "Si ya hizo esto, escriba 'Y', de lo contrario 'N', y Enter: " << endl;
    cin >> userAnswer;
    userAnswer = static_cast<char>(tolower(userAnswer));

    if (userAnswer != 'y' && userAnswer != 'n')
    {
        throw std::invalid_argument("La opcion ingresada es incorrecta");
    }

    if(userAnswer == 'n'){
        parametrizacion();
    }

    string userText;
    cout << endl;
    cout << "A continuacion, se procesaran los datos de los programas academicos seleccionados" << endl;

    string anio1;
    string anio2;
    cout << "Escriba el primer anio de busqueda: ";
    cin >> anio1;
    cout << endl;
    
    if (!esEntero(anio1)){
        throw std::invalid_argument("El valor ingresado no es correcto");
    }
    
    cout << "Escriba el segundo ano de busqueda: ";
    cin >> anio2;
    cout << endl;

    if (!esEntero(anio2)){
        throw std::invalid_argument("El valor ingresado no es correcto");
    }

    if(anio1>=anio2){
        throw std::invalid_argument("El segundo anio debe ser mayor que el primero");
    }

    cout << "Procesando datos ..." << endl;
    controlador.procesarDatosCsv(anio1, anio2);
    cout << "Datos procesados con exito!" << endl;
    
    return true;
}

void View::parametrizacion(){
    cout << "====================================================================" << endl;
    cout << "¿Desea indicar una nueva ruta base donde se encuentran las carpetas"<< endl;
    cout << "INPUT y OUTPUT?"<< endl;
    cout<<ajustes.BASE_PATH;
}
void View::salir()
{
    cout << "Cerrando programa..." << endl;
    cout << "Recuerde revisar la carpeta de outputs para los archivos .csv exportados" << endl;
    cout << "Programa Cerrado con exito!" << endl;
}

void View::mostrarDatosExtra()
{
    char opcionYN;
    cout << "A continuacion vamos a mostrar datos relevantes de los programas academicos seleccionados" << "\n"
         << endl;
    cout << "Desea Convertir los datos a un archivo CSV?(Y/N): " << endl;
    cin >> opcionYN;
    opcionYN = tolower(opcionYN);
    cout << "\n";
    // FIXME verificar que el usuario ingrese un valor igual al esperado, return true si es Y, false si es N, y no sale si no retorna un valor válido
    // Simplificar el código de acuerdo a ese ajuste
    if (opcionYN == 'y')
    {
        controlador.calcularDatosExtra(true);
    }

    else
    {
        controlador.calcularDatosExtra(false);
    }
}

void View::buscarPorPalabraClaveYFormacion()
{
    char opcionYN = 'y', opcionCSV;
    string palabraClave;
    bool convertirCSV;
    int idFormacionAcademica;

    while (opcionYN == 'y')
    {
        cout << "Desea hacer una busqueda por palabra clave del nombre del programa(Y/N): " << endl;
        cin >> opcionYN;
        cout << "\n";
        opcionYN = tolower(opcionYN);

        if (opcionYN == 'y')
        {
            cout << "Deseas convertir convertir los datos del programa academico a un CSV?(Y/N): " << endl;
            cin >> opcionCSV;
            cout << "\n";
            opcionCSV = tolower(opcionCSV);

            if (opcionCSV == 'y')
            {
                convertirCSV = true;
            }

            else
            {
                convertirCSV = false;
            }

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
        std::size_t pos;
        int num = std::stoi(str, &pos);

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