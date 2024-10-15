#include "GestorCsv.h"


GestorCsv::GestorCsv() {
    this->DELIMITADOR = Settings::DELIMITADOR;
}
// FIXME: LA LECTURA DE ARCHIVOS CON GETLINE FUNCIONA HORRIBLEMENTE, NO TENEMOS IDEA DE POR QUÉ
vector<int> GestorCsv::leerProgramasCsv(string &ruta){
    vector<int> codigosSniesRetorno;
    ifstream archivoProgramasCsv(ruta);
    if (!(archivoProgramasCsv.is_open()))
    {
        cout << "Archivo " << ruta << " no se pudo abrir correctamente" << endl;
    }
    else
    {
        string linea;
        string dato;
        // Mantenimiento (Revisión): Se puede mejorar la lectura de archivos con getline y
        // No debería saltarse la primera linea para así determinar qué está leyendo.
        // Saltarse la primera linea
        getline(archivoProgramasCsv, linea);
        // Leer los programas
        while (getline(archivoProgramasCsv, linea))
        {
            stringstream streamLinea(linea);
            getline(streamLinea, dato, ';');
            // Manteniemiento: Se puede mejorar la forma de leer los datos de la línea y
            // los nombres de los métodos y variables.
            codigosSniesRetorno.push_back(stoi(dato));
        }
    }
    archivoProgramasCsv.close();
    return codigosSniesRetorno;
}

// Complejidad: Este metodo tiene una alta complejidad ciclomática y computacional, reducir en metodos más pequeños
// Estructuras de control anidadas profundamente.
vector<vector<string>> GestorCsv::leerArchivoPrimera(string &rutaBase, string &ano, vector<int> &codigosSnies)
{
    // Estructura: La estructura es confusa.
    // Mantenimiento: Se pueden mejorar los nombres de las variables.
    vector<vector<string>> matrizResultado;
    string rutaCompleta = rutaBase + ano + ".csv";
    ifstream archivoPrimero(rutaCompleta);
    if (!(archivoPrimero.is_open()))
    {
        cout << "Archivo " << rutaCompleta << " no se pudo abrir correctamente" << endl;
    }
    else
    {
        string fila;
        string dato;
        vector<string> vectorFila;
        stringstream streamFila;
        int columna;
        vector<int>::iterator it;

        // Primera iteracion del ciclo para guardar las etiquetas
        getline(archivoPrimero, fila);
        vectorFila = vector<string>(39);
        streamFila = stringstream(fila);
        columna = 0;
        while ((getline(streamFila, dato, ';')))
        {
            vectorFila[columna] = dato;
            columna++;
        }
        matrizResultado.push_back(vectorFila);

        // Leer el resto del archivo
        while (getline(archivoPrimero, fila))
        {
            streamFila = stringstream(fila);
            columna = 0;
            while ((getline(streamFila, dato, ';')) && (columna < 13))
            {
                vectorFila[columna] = dato;
                columna++;
            }

            // Verificamos que la fila no sea una fila de error
            if (vectorFila[12] != "Sin programa especifico")
            {
                it = find(codigosSnies.begin(), codigosSnies.end(), stoi(vectorFila[12]));
            }
            else
            {
                it = codigosSnies.end();
            }

            // Verificar si hace parte de los programas que me interesan
            if (it != codigosSnies.end()) // Caso donde si estaba dentro de los programas que me interesan
            {
                // Termino de leer y guardar primera fila
                vectorFila[columna] = dato; // Guardamos el dato que habiamos geteado justo antes de hacer la verificacion
                columna++;
                while ((getline(streamFila, dato, ';')))
                {
                    vectorFila[columna] = dato;
                    columna++;
                }
                matrizResultado.push_back(vectorFila);

                // Leo y guardo filas restantes
                for (int j = 0; j < 3; j++)
                {
                    getline(archivoPrimero, fila);
                    streamFila = stringstream(fila);
                    columna = 0;
                    while ((getline(streamFila, dato, ';')))
                    {
                        vectorFila[columna] = dato;
                        columna++;
                    }
                    matrizResultado.push_back(vectorFila);
                }
            }
            // Si es de los programas que no me interesan, sigo a la siguiente fila, sin guardar la fila en la matriz de resultados
        }
    }

    archivoPrimero.close();

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
