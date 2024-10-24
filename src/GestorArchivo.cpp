#include "GestorArchivo.h"

// Constructor

GestorArchivo::GestorArchivo() {}

// Protected methods

vector<string> GestorArchivo::leerEncabezado(ifstream &archivo) {
    string fila, dato;
    vector<string> vecFila(39);
    getline(archivo, fila);
    stringstream streamFila(fila);
    int columna = 0;
    while (getline(streamFila, dato, ';') && columna < 39) {
        vecFila[columna++] = dato;
    }
    return vecFila;
}

vector<string> GestorArchivo::leerFila(ifstream &archivo, int limiteColumnas) {
    string fila, dato;  // fila con limites
    vector<string> vecfila(39);
    getline(archivo, fila);
    stringstream streamFila(fila);
    int columna = 0;
    while (getline(streamFila, dato, ';') && columna < limiteColumnas) {
        vecfila[columna++] = dato;
    }
    return vecfila;
}

bool GestorArchivo::abrirArchivo(string &ruta, ifstream &archivo) {
    archivo.open(ruta);
    if (!archivo.is_open()) {
        cout << "Error: No se pudo abrir el archivo" << ruta << endl;
        return false;
    }
    return true;
}

bool GestorArchivo::filaRelevante(const vector<string> &fila,vector<int> &codigoSnies) {
    if (fila[12] == "Sin programa especifico") return false;
    try {
        int codigo = stoi(fila[12]);
        return find(codigoSnies.begin(), codigoSnies.end(), codigo) !=
               codigoSnies.end();
    } catch (const invalid_argument &e) {
        return false;
    }
}

void GestorArchivo::leerFilasAdicionales(ifstream &archivo,vector<vector<string>> &matrizResult) {
    for (int i = 0; i < 3; i++) {
        matrizResult.push_back(leerFila(archivo,39));
    }
}

// Public methods

vector<int> GestorArchivo::leerProgramasCsv(string &ruta) {
    vector<int> codigosSniesRetorno;
    ifstream archivo(ruta);
    if (!archivo.is_open()) {
        return codigosSniesRetorno;
    }
    string linea, dato;
    getline(archivo, linea);  // salta los encabezados
    while (getline(archivo, linea)) {
        stringstream streamLinea(linea);
        try {
            getline(streamLinea, dato, ';');
            codigosSniesRetorno.push_back(stoi(dato));
        } catch (const invalid_argument &e) {
            cout << "Error: Valor invalido en el archivo: " << dato << endl;
        }
    }
    archivo.close();
    return codigosSniesRetorno;
}

vector<vector<string>> GestorArchivo::leerArchivo(string &rutaBase, string &ano, vector<int> &codigosSnies, int colmunaCodigoSnies) {
    vector<vector<string>> matrizResultado;
    string rutaCompleta = rutaBase + ano + ".csv";
    ifstream archivo;
    if (!abrirArchivo(rutaCompleta, archivo)) {
        return matrizResultado;
    }
    matrizResultado.push_back(leerEncabezado(archivo));
    while (!archivo.eof()) {
        vector<string> fila = leerFila(archivo, 39);
        if (!fila.empty() && filaRelevante(fila, codigosSnies)) {
            matrizResultado.push_back(fila);
            leerFilasAdicionales(archivo, matrizResultado);
        }
    }
    archivo.close();
    return matrizResultado;
}

bool GestorArchivo::crearArchivo(string &ruta, map<int, ProgramaAcademico *> &mapadeProgramasAcademicos,vector<string> etiquetasColumnas) {
    return false;
}

bool GestorArchivo::crearArchivoBuscados(string &ruta, list<ProgramaAcademico *> &programasBuscados,vector<string> etiquetasColumnas) {
    return false;
}