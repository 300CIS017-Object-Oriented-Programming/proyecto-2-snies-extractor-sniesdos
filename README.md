[![Review Assignment Due Date](https://classroom.github.com/assets/deadline-readme-button-22041afd0340ce965d47ae6ef1cefeee28c7c493a6346c4f15d667ab976d596c.svg)](https://classroom.github.com/a/QApazJy0)

## SNIES Extractor
Gracias al grupo que me presetó el código fuente de este proyecto

## Presentación general
En este proyecto se utilizarán 5 clases para cumplir el propósito de extraer la información del Sistema Nacional de Información de Educación Superior. Para el usuario, este tendrá una interfaz por terminal que le indicará los pasos a seguir y la información que necesita digitar.

## Cumplimiento de Requerimientos

1. **Solicitar rango de años a analizar**  
   En el menú, se le pregunta al usuario cuál es el primer año de búsqueda, tomando en cuenta que los rangos de años siempre son consecutivos, el segundo año de búsqueda se calcula a partir del primero.

2. **Lectura de archivos .csv correspondientes**  
   A partir de los años ingresados por el usuario, el controlador (clase `SNIESController`) leerá la información de los archivos apropiados uno por uno.

3. **Calcular admitidos, inscritos, graduados, matriculados y matriculados de primer semestre por programa y por año**  
   El SNIES-Extractor, mediante su controlador, calculará estos datos por cada programa y año a partir de los datos en bruto que extrae de los archivos .csv apropiados.

4. **Generación de Archivos de Salida**  
   Al terminar de extraer la información y procesarla, el SNIES-Extractor generará un archivo de resultados en la siguiente carpeta que ya debería estar parametrizada en el disco duro:  
   `C:\SNIES_EXTRACTOR\outputs\resultados.csv`.

5. **Visualización de Datos**  
   El SNIES-Extractor muestra al usuario el consolidado de estudiantes por año en programas presenciales o virtuales, la diferencia porcentual anual entre la cantidad de nuevos matriculados durante los años de búsqueda por programa y la lista de programas sin nuevos matriculados en 3 semestres consecutivos. Además, permitirá al usuario exportar esta información en un archivo ubicado en la carpeta ya parametrizada:  
   `C:\SNIES_EXTRACTOR\outputs\extras.csv`.

6. **Filtrado de Programas**  
   Se le pregunta al usuario si desea hacer una búsqueda con 2 filtros entre los programas solicitados: una palabra clave para buscar según los nombres de programas y el nivel de formación de los programas.

7. **Validación de Datos**  
   El SNIES-Extractor es un programa de C++ robusto que puede detectar errores a la hora de recibir información fuera de rangos esperados, tanto de parte del usuario como de la lectura de los archivos .csv.

Más abajo podrán encontrar el diagrama UML de las clases.


# Diagrama Mermaid

*El vector de Consolidados tendrá siempre 8 posiciones [0-7] donde:*
*vector[0] es primer año, primer semestre, hombres*
*vector[1] es primer año, segundo semestre, hombres*
*vector[2] es primer año, primer semestre, mujeres*
*vector[3] es primer año, segundo semestre, mujeres*
*vector[4] es segundo año, primer semestre, hombres*
*vector[5] es segundo año, segundo semestre, hombres*
*vector[6] es segundo año, primer semestre, mujeres*
*vector[7] es segundo año, segundo semestre, mujeres*
```mermaid
classDiagram
direction BT
    class ProgramaAcademico {
        -map~string, string~ datos
        -map~int, Consolidado*~ consolidado
        -int codigoDeLaInstitucion
        -int iesPadre
        -string institucionDeEducacionSuperiorIes
        -string principalOSeccional
        -int idSectorIes
        -string sectorIes
        -int idCaracter
        -string caracterIes
        -int codigoDelDepartamentoIes
        -string departamentoDeDomicilioDeLaIes
        -int codigoDelMunicipioIes
        -string municipioDeDomicilioDeLaIes
        -int codigoSniesDelPrograma
        -string programaAcademico
        -int idNivelAcademico
        -string nivelAcademico
        -int idNivelDeFormacion
        -string nivelDeFormacion
        -int idMetodologia
        -string metodologia
        -int idArea
        -string areaDeConocimiento
        -int idNucleo
        -string nucleoBasicoDelConocimientoNbc
        -int idCineCampoAmplio
        -string descCineCampoAmplio
        -int idCineCampoEspecifico
        -string descCineCampoEspecifico
        -int idCineCodigoDetallado
        -string descCineCodigoDetallado
        -int codigoDelDepartamentoPrograma
        -string departamentoDeOfertaDelPrograma
        -int codigoDelMunicipioPrograma
        -string municipioDeOfertaDelPrograma
        -vector~Consolidado*~ consolidados
        +ProgramaAcademico()
        +~ProgramaAcademico()
        +sets()...
        +gets()...
    }
    class Consolidado {
        -int idSexo
        -string sexo
        -int ano
        -int semestre
        -int inscritos
        -int admitidos
        -int matriculados
        -int matriculadosPrimerSemestre
        -int graduados
        +Consolidado()
        +Consolidado(int, string, int, int, int, int, int, int, int)
        +sets()...
        +gets()...
    }
    class GestorArchivo {
        #bool abrirArchivoLectura(const string &, ifstream &)
        #bool abrirArchivoEscritura(const string &, ofstream &)
        #bool archivoVacio(ifstream &)
        +GestorArchivo() = default
        +virtual ~GestorArchivo() = default
        +virtual bool crearArchivo(string &, map~int, ProgramaAcademico*~ &, vector~string~)
        +virtual bool crearArchivoBuscado(string &, list~ProgramaAcademico*~ &, vector~string~)
        +virtual bool crearArchivoExtra(string &, vector~vector~string~~)
    }
    class GestorCsv {
        <<Abstract>>
        -Settings settings
        -string DELIMITADOR
        -leerEncabezado(ifstream &)
        -leerFila(ifstream &, int)
        -abrirArchivo(string &, ifstream &)
        -filaRelevante(const vector~string~ &, vector~int~ &)
        -leerFilasAdicionales(ifstream &, vector~vector~string~~ &)
        +GestorCsv()
        +vector~int~ leerProgramasCsv(string &ruta)
        +vector~vector~string~~ leerArchivo(string &, string &, vector~int~ &)
        +bool crearArchivo(string &, map~int, ProgramaAcademico*~ &, vector~string~)
        +bool crearArchivoBuscado(string &, list~ProgramaAcademico*~ &, vector~string~)
        +bool crearArchivoExtra(string &, vector~vector~string~~)
    }
    class GestorJson {
        <<Abstract>>
        +GestorJson()
        +bool crearArchivo(string &, map~int, ProgramaAcademico*~ &, vector~string~)
        +bool crearArchivoBuscado(string &, list~ProgramaAcademico*~ &, vector~string~)
        +bool crearArchivoExtra(string &, vector~vector~string~~)
    }
    class GestorTxt {
        <<Abstract>>
        +GestorTxt()
        +bool crearArchivo(string &, map~int, ProgramaAcademico*~ &, vector~string~)
        +bool crearArchivoBuscado(string &, list~ProgramaAcademico*~ &, vector~string~)
        +bool crearArchivoExtra(string &, vector~vector~string~~)
    }
    class Settings {
        +static const string BASE_PATH
        +static const string OUT_PATH
        +static const string LOGS_FILE_PATH
        +static const string PROGRAMAS_FILTRAR_FILE_PATH
        +static const string ADMITIDOS_FILE_PATH
        +static const string MATRICULADOS_FILE_PATH
        +static const string MATRICULADOS_PRIMERSEMESTRE_FILE_PATH
        +static const string INSCRITOS_FILE_PATH
        +static const string GRADUADOS_FILE_PATH
        +static const string INFORME_FILE_PATH
        +static const char DELIMITADOR
        +static const int COLUMNAS_CONSOLIDADOS
        +static const int DATOS_ACADEMICOS
    }
    class SNIESController {
        -map~long, ProgramaAcademico*~ programasAcademicos
        -vector~string~ etiquetasColumnas
        -GestorCsv* gestorCsvObj
        -GestorJson* gestorJsonObj
        -GestorTxt* gestorTxtObj
        -Settings settings
        -string rutaProgramasCSV
        -string rutaAdmitidos
        -string rutaGraduados
        -string rutaInscritos
        -string rutaMatriculados
        -string rutaMatriculadosPrimerSemestre
        -string rutaOutput
        +SNIESController()
        +~SNIESController()
        +void setProgramasAcademicos(vector~vector~string~~ &, string &, string &, vector~int~ &, int)
        +void procesarDatos(string &, string &)
        +void calcularDatosExtra(bool)
        +void buscarProgramas(bool, string &, int)
    }
    class View {
        -SNIESController controlador
        -bool isConvetibleToInt(const string &)
        -bool mostrarPantallaBienvenido()
        -void mostrarDatosProgramaAcademico()
        -void filtrarPorPalabrasClaveYFormacion()
        -static void salirDePrograma()
        -string obtenerAnoValido(const string &)
        -void ordenarAnios(string &, string &)
        -bool preguntarSiConvertirCSV()
        -string obtenerPalabraClave()
        -int obtenerIdFormacionAcademica()
        +View()
        +~View() = default
        +void mostrarMenu()
    }
    class Main {
        + int main()
    }
ProgramaAcademico o-- Consolidado : tiene varios
View <.. Main : usa
View --> SNIESController : tiene un
SNIESController --> Settings: tiene un
SNIESController --> GestorCsv: tiene un
SNIESController --> GestorJson: tiene un
SNIESController --> GestorTxt: tiene un
SNIESController o-- Consolidado
GestorArchivo<|--GestorCsv: Hereda
GestorCsv --> Settings : tiene un
GestorArchivo<|--GestorJson: Hereda
GestorArchivo<|--GestorTxt: Hereda
```
