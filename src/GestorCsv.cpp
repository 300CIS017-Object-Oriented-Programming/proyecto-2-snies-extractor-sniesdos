#include "GestorCsv.h"
GestorCsv::GestorCsv() {
    this->DELIMITADOR = Settings::DELIMITADOR;
}
// FIXME: LA LECTURA DE ARCHIVOS CON GETLINE FUNCIONA HORRIBLEMENTE, NO TENEMOS IDEA DE POR QUÉ
vector<int> GestorCsv::leerProgramasCsv( string &ruta){
    vector<int> codigosSniesRetorno;
    ifstream archivo(ruta);
    if (!archivo.is_open())
    {
        cout << "Archivo " << ruta << " no se pudo abrir correctamente" << endl;
    }
    else
    {   
        string linea, dato;
        getline(archivo, linea);
        // Leer los programas
        while (getline(archivo, linea)){
            stringstream streamLinea(linea);
            try{
                getline(streamLinea, dato, ';');
                codigosSniesRetorno.push_back(stoi(dato));
            }catch(const invalid_argument &e){
                cout<<"Error: Valor invalido: "<<dato<<"en el archivo"<<endl;
            }
        }
    }
    archivo.close();
    return codigosSniesRetorno;
}

vector<string> leerEncabezado(ifstream &archivo){
    string fila, dato;
    vector<string>vecFila(39);
    getline(archivo,fila);
    stringstream streamFila(fila);
    int columna = 0;
    while(getline(streamFila, dato, ';') && columna < 39){
        vecFila[columna++] = dato;
    }
    return vecFila;
}

vector<string>leerFila(ifstream &archivo, int limiteColumnas = LIMIT_COLUMNAS_FILA){
    string fila, dato;
    vector<string> vecfila(39);
    getline(archivo, fila);
    stringstream streamFila(fila);
    int columna = 0;
    while(getline(streamFila, dato, ';') && columna < limiteColumnas){
        vecfila[columna++] = dato;
    }
    return vecfila;
}

bool filaRelevante(const vector<string>&fila, vector<int>&codigoSnies){
    if(fila[12] == "Sin programa especifico") return false;
    try{
        int codigo = stoi(fila[12]);
        return find(codigoSnies.begin(), codigoSnies.end(), codigo) != codigoSnies.end();;
    }catch(const invalid_argument &e){
        return false;
    }
}

void leerFilasAdicionales(ifstream& archivo, vector<vector<string>>& matrizResult){
    for(int i = 0; i < 3; i++){
        matrizResult.push_back(leerFila(archivo));
    }
}

//funcion inicial
vector<vector<string>>GestorCsv::leerArchivoPrimera(string &rutaBase, string &ano, vector<int> &codigoSnies){
    vector<vector<string>> matrizResultado;
    string rutaCompleta= rutaBase + ano + ".csv";
    ifstream archivo(rutaCompleta);
    if(!archivo.is_open()){
        cout<<"archivo"<<rutaCompleta<<"no se puedo abrir correctamente"<<endl;
        return matrizResultado;
    }
    matrizResultado.push_back(leerEncabezado(archivo));
    while(!archivo.eof()){
        vector<string> fila = leerFila(archivo);
        if(!fila.empty() && filaRelevante(fila, codigoSnies)){
            matrizResultado.push_back(fila);
            leerFilasAdicionales(archivo, matrizResultado);
        }
    }
    archivo.close();    
    return matrizResultado;
}

//----------------------------------------------------------------------------------------------------------------------
// Complejidad: Este metodo tiene una alta complejidad ciclomática y computacional, reducir en metodos más pequeños
// Parece hacer lo mismo que el metodo leerArchivoPrimera
vector<vector<string>> GestorCsv::leerArchivoSegunda(string &rutaBase, string &ano, vector<int> &codigosSnies)
{
    vector<vector<string>> matrizResultado;
    string rutaCompleta = rutaBase + ano + ".csv";
    ifstream archivoSegundo(rutaCompleta);
    if (!(archivoSegundo.is_open()))
    {
        cout << "Archivo " << rutaCompleta << " no se pudo abrir correctamente" << endl;
    }
    else
    {
        string fila;
        string dato;
        vector<string> vectorFila(6);
        stringstream streamFila;
        int columnaArchivo;
        int columnaVector;
        vector<int>::iterator it;

        // Nos saltamos las etiquetas para no interferir en el bucle
        getline(archivoSegundo, fila);

        // Leemos las filas
        while (getline(archivoSegundo, fila))
        {
            streamFila = stringstream(fila);
            columnaArchivo = 0;
            columnaVector = 0;
            while ((getline(streamFila, dato, ';')) && (columnaArchivo < 13))
            {
                if (columnaArchivo == 12)
                {
                    vectorFila[columnaVector] = dato;
                    columnaVector++;
                }
                columnaArchivo++;
            }

            // Verificamos que la fila no sea una fila de error
            if (vectorFila[0] != "Sin programa especifico")
            {
                it = find(codigosSnies.begin(), codigosSnies.end(), stoi(vectorFila[0]));
            }
            else
            {
                it = codigosSnies.end();
            }

            // Verificar si hace parte de los programas que me interesan
            if (it != codigosSnies.end()) // Caso cuando SI es parte de los que me interesan
            {
                // Termino de leer y guardar primera fila
                columnaArchivo++; // Esto se debe a la iteracion en que hacemos getline sin subirle a la columaArchivo porque nos salimos del bucle
                while (getline(streamFila, dato, ';'))
                {
                    if (columnaArchivo >= 34)
                    {
                        vectorFila[columnaVector] = dato;
                        columnaVector++;
                    }
                    columnaArchivo++;
                }
                matrizResultado.push_back(vectorFila);

                // Leer las otras 3 filas
                for (int i = 0; i < 3; i++)
                {
                    getline(archivoSegundo, fila);
                    streamFila = stringstream(fila);
                    columnaArchivo = 0;
                    columnaVector = 0;
                    while (getline(streamFila, dato, ';'))
                    {
                        if ((columnaArchivo >= 34) || (columnaArchivo == 12))
                        {
                            vectorFila[columnaVector] = dato;
                            columnaVector++;
                        }
                        columnaArchivo++;
                    }
                    matrizResultado.push_back(vectorFila);
                }
            }
            // Cuando no me interesa no hago nada
        }
    }

    /*
    Ejemplo de matrizResultado: (No tendría las etiquetas incluidas)
    CodigoSnies;IdSexo;SexoString;Ano;Semestre;Admitidos
    1; 1; Masculino; 2022; 1, 56
    */
    archivoSegundo.close();

    /*// Imprimir matriz resultado para verificaciones
    for (int h = 0; h < matrizResultado.size(); h++)
    {
        for (int k = 0; k < matrizResultado[h].size(); k++)
        {
            cout << matrizResultado[h][k];
            if (k != (matrizResultado[h].size() - 1))
            {
                cout << ";";
            }
        }
        cout << endl;
    }*/
    return matrizResultado;
}

vector<vector<string>> GestorCsv::leerArchivo(string &rutaBase, string &ano, vector<int> &codigosSnies, int colmunaCodigoSnies)
{
    vector<vector<string>> matrizResultado;
    string rutaCompleta = rutaBase + ano + ".csv";
    ifstream archivoSegundo(rutaCompleta);
    if (!(archivoSegundo.is_open()))
    {
        cout << "Archivo " << rutaCompleta << " no se pudo abrir correctamente" << endl;
    }
    else
    {
        string fila;
        string dato;
        vector<string> vectorFila(2);
        stringstream streamFila;
        int columnaArchivo;
        int columnaVector;
        vector<int>::iterator it;

        // Nos saltamos las etiquetas para no interferir en el bucle
        getline(archivoSegundo, fila);

        // Leemos las filas
        while (getline(archivoSegundo, fila))
        {
            streamFila = stringstream(fila);
            columnaArchivo = 0;
            columnaVector = 0;
            while ((getline(streamFila, dato, ';')) && (columnaArchivo < (colmunaCodigoSnies + 1)))
            {
                if (columnaArchivo == colmunaCodigoSnies)
                {
                    vectorFila[columnaVector] = dato;
                    columnaVector++;
                }
                columnaArchivo++;
            }

            // Verificamos que la fila no sea una fila de error
            if (vectorFila[0] != "Sin programa especifico")
            {
                it = find(codigosSnies.begin(), codigosSnies.end(), stoi(vectorFila[0]));
            }
            else
            {
                it = codigosSnies.end();
            }

            // Verificar si hace parte de los programas que me interesan
            if (it != codigosSnies.end()) // Caso cuando SI es parte de los que me interesan
            {
                // Terminar de leer primera fila
                while (getline(streamFila, dato, ';'))
                {
                }
                vectorFila[columnaVector] = dato;
                matrizResultado.push_back(vectorFila);

                // Leer las otras 3 filas
                for (int i = 0; i < 3; i++)
                {
                    getline(archivoSegundo, fila);
                    streamFila = stringstream(fila);
                    columnaArchivo = 0;
                    columnaVector = 0;
                    while (getline(streamFila, dato, ';'))
                    {
                        if (columnaArchivo == colmunaCodigoSnies)
                        {
                            vectorFila[columnaVector] = dato;
                            columnaVector++;
                        }
                        columnaArchivo++;
                    }
                    vectorFila[columnaVector] = dato;
                    matrizResultado.push_back(vectorFila);
                }
            }
            else // Caso cuando NO es parte de los que me interesan
            {
                /*// Saltarme las 3 siguientes filas con mismo codigo Snies
                for (int j = 0; j < 3; j++)
                {
                    getline(archivoSegundo, fila);
                }*/
            }
        }
    }

    /*
    Ejemplo de matrizResultado: (No tendría las etiquetas incluidas)
    CodigoSnies;DatoExtradelArchivo
    12;5
    */
    archivoSegundo.close();
    /*// Imprimir matriz resultado para verificaciones
    for (int h = 0; h < matrizResultado.size(); h++)
    {
        for (int k = 0; k < matrizResultado[h].size(); k++)
        {
            cout << matrizResultado[h][k];
            if (k != (matrizResultado[h].size() - 1))
            {
                cout << ";";
            }
        }
        cout << endl;
    }*/
    return matrizResultado;
}

bool GestorCsv::crearArchivo(string &ruta, map<int, ProgramaAcademico *> &mapadeProgramasAcademicos, vector<string> etiquetasColumnas)
{
    // Este bool nos ayudará a saber si se creo exitosamente el archivo
    bool estadoCreacion = false;
    string rutaCompleta = ruta + "resultados.csv";
    ofstream archivoResultados(rutaCompleta);
    if (archivoResultados.is_open())
    {
        // Imprimimos en el archivo las etiquetas (Primera fila)
        for (int i = 0; i < etiquetasColumnas.size(); i++)
        {
            archivoResultados << etiquetasColumnas[i] << DELIMITADOR;
        }
        archivoResultados << "GRADUADOS;INSCRITOS;MATRICULADOS;NEOS" << endl;

        map<int, ProgramaAcademico *>::iterator it;
        // Leemos todos los programas del mapa para imprimirlos en el archivo
        for (it = mapadeProgramasAcademicos.begin(); it != mapadeProgramasAcademicos.end(); it++)
        {
            // Imprimimos cada uno de los 8 consolidados por programa
            for (int i = 0; i < 8; i++)
            {
                // Imprimimos toda la información base del programa academico
                archivoResultados << (it->second)->getCodigoDeLaInstitucion() << DELIMITADOR;
                archivoResultados << (it->second)->getIesPadre() << DELIMITADOR;
                archivoResultados << (it->second)->getInstitucionDeEducacionSuperiorIes() << DELIMITADOR;
                archivoResultados << (it->second)->getPrincipalOSeccional() << DELIMITADOR;
                archivoResultados << (it->second)->getIdSectorIes() << DELIMITADOR;
                archivoResultados << (it->second)->getSectorIes() << DELIMITADOR;
                archivoResultados << (it->second)->getIdCaracter() << DELIMITADOR;
                archivoResultados << (it->second)->getCaracterIes() << DELIMITADOR;
                archivoResultados << (it->second)->getCodigoDelDepartamentoIes() << DELIMITADOR;
                archivoResultados << (it->second)->getDepartamentoDeDomicilioDeLaIes() << DELIMITADOR;
                archivoResultados << (it->second)->getCodigoDelMunicipioIes() << DELIMITADOR;
                archivoResultados << (it->second)->getMunicipioDeDomicilioDeLaIes() << DELIMITADOR;
                archivoResultados << (it->second)->getCodigoSniesDelPrograma() << DELIMITADOR;
                archivoResultados << (it->second)->getProgramaAcademico() << DELIMITADOR;
                archivoResultados << (it->second)->getIdNivelAcademico() << DELIMITADOR;
                archivoResultados << (it->second)->getNivelAcademico() << DELIMITADOR;
                archivoResultados << (it->second)->getIdNivelDeFormacion() << DELIMITADOR;
                archivoResultados << (it->second)->getNivelDeFormacion() << DELIMITADOR;
                archivoResultados << (it->second)->getIdMetodologia() << DELIMITADOR;
                archivoResultados << (it->second)->getMetodologia() << DELIMITADOR;
                archivoResultados << (it->second)->getIdArea() << DELIMITADOR;
                archivoResultados << (it->second)->getAreaDeConocimiento() << DELIMITADOR;
                archivoResultados << (it->second)->getIdNucleo() << DELIMITADOR;
                archivoResultados << (it->second)->getNucleoBasicoDelConocimientoNbc() << DELIMITADOR;
                archivoResultados << (it->second)->getIdCineCampoAmplio() << DELIMITADOR;
                archivoResultados << (it->second)->getDescCineCampoAmplio() << DELIMITADOR;
                archivoResultados << (it->second)->getIdCineCampoEspecifico() << DELIMITADOR;
                archivoResultados << (it->second)->getDescCineCampoEspecifico() << DELIMITADOR;
                archivoResultados << (it->second)->getIdCineCodigoDetallado() << DELIMITADOR;
                archivoResultados << (it->second)->getDescCineCodigoDetallado() << DELIMITADOR;
                archivoResultados << (it->second)->getCodigoDelDepartamentoPrograma() << DELIMITADOR;
                archivoResultados << (it->second)->getDepartamentoDeOfertaDelPrograma() << DELIMITADOR;
                archivoResultados << (it->second)->getCodigoDelMunicipioPrograma() << DELIMITADOR;
                archivoResultados << (it->second)->getMunicipioDeOfertaDelPrograma() << DELIMITADOR;

                // Imprimimos la información del consolidado: (ID SEXO;SEXO;AÑO;SEMESTRE;ADMITIDOS;GRADUADOS;INSCRITOS;MATRICULADOS;NEOS)
                Consolidado *consolidadoActual = (it->second)->getConsolidado(i);
                archivoResultados << consolidadoActual->getIdSexo() << DELIMITADOR;
                archivoResultados << consolidadoActual->getSexo() << DELIMITADOR;
                archivoResultados << consolidadoActual->getAno() << DELIMITADOR;
                archivoResultados << consolidadoActual->getSemestre() << DELIMITADOR;
                archivoResultados << consolidadoActual->getAdmitidos() << DELIMITADOR;
                archivoResultados << consolidadoActual->getGraduados() << DELIMITADOR;
                archivoResultados << consolidadoActual->getInscritos() << DELIMITADOR;
                archivoResultados << consolidadoActual->getMatriculados() << DELIMITADOR;
                archivoResultados << consolidadoActual->getMatriculadosPrimerSemestre();
                // Saltamos de linea para la siguiente fila
                archivoResultados << endl;
            }
        }

        // Cambiamos el valor del booleano si logramos llegar hasta este punto
        estadoCreacion = true;
        // Imprimimos ruta donde quedo el archivo
        cout << "Archivo Creado en: " << rutaCompleta << endl;
    }

    archivoResultados.close();
    return estadoCreacion;
}

bool GestorCsv::crearArchivoBuscados(string &ruta, list<ProgramaAcademico *> &programasBuscados, vector<string> etiquetasColumnas)
{
    // Este bool nos ayudará a saber si se creo exitosamente el archivo
    bool estadoCreacion = false;
    string rutaCompleta = ruta + "buscados.csv";
    ofstream archivoBuscados(rutaCompleta);
    if (archivoBuscados.is_open())
    {

        // Imprimimos en el archivo las etiquetas (Primera fila)
        for (int i = 0; i < etiquetasColumnas.size(); i++)
        {
            archivoBuscados << etiquetasColumnas[i] << DELIMITADOR;
        }
        archivoBuscados << "GRADUADOS;INSCRITOS;MATRICULADOS;NEOS" << endl;

        list<ProgramaAcademico *>::iterator it;
        // Leemos todos los programas de la lista de los programas buscados para imprimirlos
        for (it = programasBuscados.begin(); it != programasBuscados.end(); it++)
        {
            // Imprimimos los 8 consolidados del programa
            for (int i = 0; i < 8; i++)
            {
                // Imprimimos la informacion base del programa
                archivoBuscados << (*it)->getCodigoDeLaInstitucion() << DELIMITADOR;
                archivoBuscados << (*it)->getIesPadre() << DELIMITADOR;
                archivoBuscados << (*it)->getInstitucionDeEducacionSuperiorIes() << DELIMITADOR;
                archivoBuscados << (*it)->getPrincipalOSeccional() << DELIMITADOR;
                archivoBuscados << (*it)->getIdSectorIes() << DELIMITADOR;
                archivoBuscados << (*it)->getSectorIes() << DELIMITADOR;
                archivoBuscados << (*it)->getIdCaracter() << DELIMITADOR;
                archivoBuscados << (*it)->getCaracterIes() << DELIMITADOR;
                archivoBuscados << (*it)->getCodigoDelDepartamentoIes() << DELIMITADOR;
                archivoBuscados << (*it)->getDepartamentoDeDomicilioDeLaIes() << DELIMITADOR;
                archivoBuscados << (*it)->getCodigoDelMunicipioIes() << DELIMITADOR;
                archivoBuscados << (*it)->getMunicipioDeDomicilioDeLaIes() << DELIMITADOR;
                archivoBuscados << (*it)->getCodigoSniesDelPrograma() << DELIMITADOR;
                archivoBuscados << (*it)->getProgramaAcademico() << DELIMITADOR;
                archivoBuscados << (*it)->getIdNivelAcademico() << DELIMITADOR;
                archivoBuscados << (*it)->getNivelAcademico() << DELIMITADOR;
                archivoBuscados << (*it)->getIdNivelDeFormacion() << DELIMITADOR;
                archivoBuscados << (*it)->getNivelDeFormacion() << DELIMITADOR;
                archivoBuscados << (*it)->getIdMetodologia() << DELIMITADOR;
                archivoBuscados << (*it)->getMetodologia() << DELIMITADOR;
                archivoBuscados << (*it)->getIdArea() << DELIMITADOR;
                archivoBuscados << (*it)->getAreaDeConocimiento() << DELIMITADOR;
                archivoBuscados << (*it)->getIdNucleo() << DELIMITADOR;
                archivoBuscados << (*it)->getNucleoBasicoDelConocimientoNbc() << DELIMITADOR;
                archivoBuscados << (*it)->getIdCineCampoAmplio() << DELIMITADOR;
                archivoBuscados << (*it)->getDescCineCampoAmplio() << DELIMITADOR;
                archivoBuscados << (*it)->getIdCineCampoEspecifico() << DELIMITADOR;
                archivoBuscados << (*it)->getDescCineCampoEspecifico() << DELIMITADOR;
                archivoBuscados << (*it)->getIdCineCodigoDetallado() << DELIMITADOR;
                archivoBuscados << (*it)->getDescCineCodigoDetallado() << DELIMITADOR;
                archivoBuscados << (*it)->getCodigoDelDepartamentoPrograma() << DELIMITADOR;
                archivoBuscados << (*it)->getDepartamentoDeOfertaDelPrograma() << DELIMITADOR;
                archivoBuscados << (*it)->getCodigoDelMunicipioPrograma() << DELIMITADOR;
                archivoBuscados << (*it)->getMunicipioDeOfertaDelPrograma() << DELIMITADOR;

                // Imprimimos la información del consolidado: (ID SEXO;SEXO;AÑO;SEMESTRE;ADMITIDOS;GRADUADOS;INSCRITOS;MATRICULADOS;NEOS)
                Consolidado *consolidadoActual = (*it)->getConsolidado(i);
                archivoBuscados << consolidadoActual->getIdSexo() << DELIMITADOR;
                archivoBuscados << consolidadoActual->getSexo() << DELIMITADOR;
                archivoBuscados << consolidadoActual->getAno() << DELIMITADOR;
                archivoBuscados << consolidadoActual->getSemestre() << DELIMITADOR;
                archivoBuscados << consolidadoActual->getAdmitidos() << DELIMITADOR;
                archivoBuscados << consolidadoActual->getGraduados() << DELIMITADOR;
                archivoBuscados << consolidadoActual->getInscritos() << DELIMITADOR;
                archivoBuscados << consolidadoActual->getMatriculados() << DELIMITADOR;
                archivoBuscados << consolidadoActual->getMatriculadosPrimerSemestre();
                // Saltamos de linea para la siguiente fila
                archivoBuscados << endl;
            }
        }

        // Cambiamos el valor del booleano si logramos llegar hasta este punto
        estadoCreacion = true;
        // Imprimimos ruta donde quedo el archivo
        cout << "Archivo Creado en: " << rutaCompleta << endl;
    }

    archivoBuscados.close();
    return estadoCreacion;
}

bool GestorCsv::crearArchivoExtra(string &ruta, vector<vector<string>> datosAImprimir)
{
    // Este bool nos ayudará a saber si se creo el archivo exitosamente
    bool estadoCreacion = false;
    string rutaCompleta = ruta + "extras.csv";
    ofstream archivoExtra(rutaCompleta);
    if (archivoExtra.is_open())
    {
        // Imprimimos la matriz de datos que queremos imprimir
        for (int i = 0; i < datosAImprimir.size(); i++)
        {
            // Imprimimos cada fila
            for (int j = 0; j < datosAImprimir[i].size(); j++)
            {
                // Imprimimos cada dato separado por ';'
                archivoExtra << datosAImprimir[i][j];
                if (j != (datosAImprimir[i].size() - 1))
                {
                    archivoExtra << DELIMITADOR;
                }
            }
            // Saltamos de linea al terminar una fila
            archivoExtra << endl;
        }

        // Cambiamos el valor del booleano si logramos llegar hasta este punto
        estadoCreacion = true;
        // Imprimimos ruta donde quedo el archivo
        cout << "Archivo Creado en: " << rutaCompleta << endl;
    }

    archivoExtra.close();
    return estadoCreacion;
}
