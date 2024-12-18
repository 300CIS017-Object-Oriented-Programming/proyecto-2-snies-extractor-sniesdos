#include "SNIESController.h"

#include <string>

SNIESController::SNIESController() {
    
    gestorCsvObj = new GestorCsv();
    gestorJsonObj = new GestorJson();
    gestorTxtObj = new GestorTxt();

    rutaProgramasCSV = Settings::PROGRAMAS_FILTRAR_FILE_PATH;
    rutaAdmitidos = Settings::ADMITIDOS_FILE_PATH;
    rutaGraduados = Settings::GRADUADOS_FILE_PATH;
    rutaInscritos = Settings::INSCRITOS_FILE_PATH;
    rutaMatriculados = Settings::MATRICULADOS_FILE_PATH;
    rutaMatriculadosPrimerSemestre = Settings::MATRICULADOS_PRIMERSEMESTRE_FILE_PATH;
    rutaOutput = Settings::OUT_PATH;
}


SNIESController::~SNIESController()
{
    for (auto &pair : programasAcademicos)
    {
        ((pair).second)->~ProgramaAcademico();
        delete pair.second;
    }
}


void SNIESController::setProgramasAcademicos(vector<vector<string>> &programasAcademicosVector, string &ruta, string &ano, vector<int> &codigosSnies, int offset) {
    programasAcademicosVector = gestorCsvObj->leerArchivo(ruta, ano, codigosSnies);
	for (int k = 0; k < programasAcademicosVector.size(); k += Settings::DATOS_ACADEMICOS)
	{
		map<long, ProgramaAcademico *>::iterator it = programasAcademicos.find(stoi(programasAcademicosVector[k][0]));
        	if (it != programasAcademicos.end())
		{
			ProgramaAcademico *programa = it->second;
			for (int m = 0; m < Settings::DATOS_ACADEMICOS; ++m)
			{
                Consolidado *consolidado = programa->getConsolidado(m + offset);
                if(ruta == rutaGraduados)
                {
                    consolidado->setGraduados(stoi(programasAcademicosVector[k + m][1]));
                }
                else if(ruta == rutaInscritos)
                {
                    consolidado->setInscritos(stoi(programasAcademicosVector[k + m][1]));
                }
                else if(ruta == rutaMatriculados)
                {
                    consolidado->setMatriculados(stoi(programasAcademicosVector[k + m][1]));
                }
                else if(ruta == rutaMatriculadosPrimerSemestre) {
                    consolidado->setMatriculadosPrimerSemestre(stoi(programasAcademicosVector[k + m][1]));
                }
			}
		}
	}
}



void SNIESController::procesarDatos(string &ano1, string &ano2)
{
    vector<int> codigosSnies;
    vector<vector<string>> programasAcademicosVector;
    int columna;
    codigosSnies = gestorCsvObj->leerProgramasCsv(rutaProgramasCSV);
    programasAcademicosVector = gestorCsvObj->leerArchivo(rutaAdmitidos, ano1, codigosSnies);
    etiquetasColumnas = programasAcademicosVector[0];


    for (int i = 1; i < programasAcademicosVector.size(); i += Settings::DATOS_ACADEMICOS)
    {
        ProgramaAcademico *programaAcademico = new ProgramaAcademico();
        programaAcademico->setCodigoDeLaInstitucion(stoi(programasAcademicosVector[i][0]));          // CÓDIGO DE LA INSTITUCIÓN
        programaAcademico->setIesPadre(stoi(programasAcademicosVector[i][1]));                       // IES_PADRE
        programaAcademico->setInstitucionDeEducacionSuperiorIes(programasAcademicosVector[i][2]);    // INSTITUCIÓN DE EDUCACIÓN SUPERIOR (IES)
        programaAcademico->setPrincipalOSeccional(programasAcademicosVector[i][3]);                  // PRINCIPAL O SECCIONAL
        programaAcademico->setIdSectorIes(stoi(programasAcademicosVector[i][4]));                    // ID SECTOR IES
        programaAcademico->setSectorIes(programasAcademicosVector[i][5]);                            // SECTOR IES
        programaAcademico->setIdCaracter(stoi(programasAcademicosVector[i][6]));                     // ID CARÁCTER
        programaAcademico->setCaracterIes(programasAcademicosVector[i][7]);                          // CARACTER IES
        programaAcademico->setCodigoDelDepartamentoIes(stoi(programasAcademicosVector[i][8]));       // CÓDIGO DEL DEPARTAMENTO (IES)
        programaAcademico->setDepartamentoDeDomicilioDeLaIes(programasAcademicosVector[i][9]);       // DEPARTAMENTO DE DOMICILIO DE LA IES
        programaAcademico->setCodigoDelMunicipioIes(stoi(programasAcademicosVector[i][10]));         // CÓDIGO DEL MUNICIPIO IES
        programaAcademico->setMunicipioDeDomicilioDeLaIes(programasAcademicosVector[i][11]);         // MUNICIPIO DE DOMICILIO DE LA IES
        programaAcademico->setCodigoSniesDelPrograma(stoi(programasAcademicosVector[i][12]));        // CÓDIGO SNIES DEL PROGRAMA
        programaAcademico->setProgramaAcademico(programasAcademicosVector[i][13]);                   // PROGRAMA ACADÉMICO
        programaAcademico->setIdNivelAcademico(stoi(programasAcademicosVector[i][14]));              // ID NIVEL ACADÉMICO
        programaAcademico->setNivelAcademico(programasAcademicosVector[i][15]);                      // NIVEL ACADÉMICO
        programaAcademico->setIdNivelDeFormacion(stoi(programasAcademicosVector[i][16]));            // ID NIVEL DE FORMACIÓN
        programaAcademico->setNivelDeFormacion(programasAcademicosVector[i][17]);                    // NIVEL DE FORMACIÓN
        programaAcademico->setIdMetodologia(stoi(programasAcademicosVector[i][18]));                 // ID METODOLOGÍA
        programaAcademico->setMetodologia(programasAcademicosVector[i][19]);                         // METODOLOGÍA
        programaAcademico->setIdArea(stoi(programasAcademicosVector[i][20]));                        // ID ÁREA
        programaAcademico->setAreaDeConocimiento(programasAcademicosVector[i][21]);                  // ÁREA DE CONOCIMIENTO
        programaAcademico->setIdNucleo(stoi(programasAcademicosVector[i][22]));                      // ID NÚCLEO
        programaAcademico->setNucleoBasicoDelConocimientoNbc(programasAcademicosVector[i][23]);      // NÚCLEO BÁSICO DEL CONOCIMIENTO (NBC)
        programaAcademico->setIdCineCampoAmplio(stoi(programasAcademicosVector[i][24]));             // ID CINE CAMPO AMPLIO
        programaAcademico->setDescCineCampoAmplio(programasAcademicosVector[i][25]);                 // DESC CINE CAMPO AMPLIO
        programaAcademico->setIdCineCampoEspecifico(stoi(programasAcademicosVector[i][26]));         // ID CINE CAMPO ESPECÍFICO
        programaAcademico->setDescCineCampoEspecifico(programasAcademicosVector[i][27]);             // DESC CINE CAMPO ESPECÍFICO
        programaAcademico->setIdCineCodigoDetallado(stoi(programasAcademicosVector[i][28]));         // ID CINE CÓDIGO DETALLADO
        programaAcademico->setDescCineCodigoDetallado(programasAcademicosVector[i][29]);             // DESC CINE CÓDIGO DETALLADO
        programaAcademico->setCodigoDelDepartamentoPrograma(stoi(programasAcademicosVector[i][30])); // CÓDIGO DEL DEPARTAMENTO (PROGRAMA)
        programaAcademico->setDepartamentoDeOfertaDelPrograma(programasAcademicosVector[i][31]);     // DEPARTAMENTO DE OFERTA DEL PROGRAMA
        programaAcademico->setCodigoDelMunicipioPrograma(stoi(programasAcademicosVector[i][32]));    // CÓDIGO DEL MUNICIPIO (PROGRAMA)
        programaAcademico->setMunicipioDeOfertaDelPrograma(programasAcademicosVector[i][33]);        // MUNICIPIO DE OFERTA DEL PROGRAMA

        vector<Consolidado*> consolidado(Settings::DATOS_ACADEMICOS);


        for (int m = 0; m < consolidado.size(); ++m)
        {

            consolidado[m] = new Consolidado();
            consolidado[m]->setIdSexo(stoi(programasAcademicosVector[i + m][34]));
            consolidado[m]->setSexo(programasAcademicosVector[i + m][35]);
            consolidado[m]->setAno(stoi(programasAcademicosVector[i + m][36]));
            consolidado[m]->setSemestre(stoi(programasAcademicosVector[i + m][37]));
            consolidado[m]->setAdmitidos(stoi(programasAcademicosVector[i + m][38]));
            programaAcademico->setConsolidado(consolidado[m], m);
        }
        programasAcademicos.emplace(programaAcademico->getCodigoSniesDelPrograma(), programaAcademico);
    }
    // cout << "despues crear programas academicos" << endl;
    programasAcademicosVector = gestorCsvObj->leerArchivo(rutaAdmitidos, ano2, codigosSnies);
    // cout << "despues leer archivos segunda" << endl;

    for (int j = 0; j < programasAcademicosVector.size(); j += Settings::DATOS_ACADEMICOS)
    {
        map<long, ProgramaAcademico *>::iterator it = programasAcademicos.find(stoi(programasAcademicosVector[j][0]));
        if (it != programasAcademicos.end())
        {
            ProgramaAcademico *programa = it->second;

            Consolidado *consolidado[Settings::DATOS_ACADEMICOS];
            for (int m = 0; m < Settings::DATOS_ACADEMICOS; ++m)
            {
                consolidado[m] = new Consolidado();
                consolidado[m]->setIdSexo(stoi(programasAcademicosVector[j + m][1]));
                consolidado[m]->setSexo(programasAcademicosVector[j + m][2]);
                consolidado[m]->setAno(stoi(programasAcademicosVector[j + m][3]));
                consolidado[m]->setSemestre(stoi(programasAcademicosVector[j + m][4]));
                consolidado[m]->setAdmitidos(stoi(programasAcademicosVector[j + m][5]));
                programa->setConsolidado(consolidado[m], m + 4);
            }
        }
    }

     //cout << "despues crear todos los consolidados" << endl;

    setProgramasAcademicos(programasAcademicosVector, rutaGraduados, ano1, codigosSnies, 0);
    setProgramasAcademicos(programasAcademicosVector, rutaGraduados, ano2, codigosSnies, 4);
    
    /*columna = (ano2 == "2022") ? 12 : 13;*/
    setProgramasAcademicos(programasAcademicosVector, rutaInscritos, ano1, codigosSnies, 0);
    setProgramasAcademicos(programasAcademicosVector, rutaInscritos, ano2, codigosSnies, 4);

    setProgramasAcademicos(programasAcademicosVector, rutaMatriculados, ano1, codigosSnies, 0);
    setProgramasAcademicos(programasAcademicosVector, rutaMatriculados, ano2, codigosSnies, 4);

    setProgramasAcademicos(programasAcademicosVector, rutaMatriculadosPrimerSemestre, ano1, codigosSnies, 0);
    setProgramasAcademicos(programasAcademicosVector, rutaMatriculadosPrimerSemestre, ano2, codigosSnies, 14);
    
  
}

void SNIESController::buscarProgramas(bool flag, string &palabraClave, int idComparacion)
{
    list<ProgramaAcademico *> listaProgramas;
    for (map<long, ProgramaAcademico *>::iterator it = programasAcademicos.begin(); it != programasAcademicos.end(); ++it)
    {
        ProgramaAcademico *programa = it->second;
        string nombre = programa->getProgramaAcademico();
        int id = programa->getIdNivelDeFormacion();
        if (nombre.find(palabraClave) != string::npos && id == idComparacion)
        {
            listaProgramas.push_back(programa);
            // codigo SNIES, nombre del programa, codigo de la institucion, nombre de la institucion y metodología
            cout << programa->getCodigoSniesDelPrograma() << ";" << programa->getProgramaAcademico() << ";" << programa->getCodigoDeLaInstitucion() << ";" << programa->getInstitucionDeEducacionSuperiorIes() << ";" << programa->getMetodologia() << endl;
        }
    }

    if (flag)
    {
        int op;
        cout<< "-----------------------------------"<<endl;
        cout << "Que tipo de archivo desea generar" << endl;
        cout << "1. CSV" << endl;
        cout << "2. TXT" << endl;
        cout << "3. JSON" << endl;
        cout<< "-----------------------------------"<<endl;
        cout << "Seleccione la opcion que desea:";
        cin >> op;
        cout<< "-----------------------------------"<<endl;

        try {
            if (op == 1) {
                GestorCsv *gestorObjAux = new GestorCsv();
                gestorObjAux->crearArchivoBuscado(rutaOutput, listaProgramas, etiquetasColumnas);
            } else if (op == 2) {
                GestorTxt *gestorObjAux = new GestorTxt();
                gestorObjAux->crearArchivoBuscado(rutaOutput, listaProgramas, etiquetasColumnas);
            } else {
                GestorJson *gestorObjAux = new GestorJson();
                gestorObjAux->crearArchivoBuscado(rutaOutput,listaProgramas, etiquetasColumnas);
            }
        } catch (std::out_of_range &e) {
            std::cerr << "Error al crear el archivo: " << e.what() << std::endl;
        }
    }
}


void SNIESController::calcularDatosExtra(bool flag)
{
    vector<vector<string>> matrizFinal;
    vector<vector<string>> matrizEtiquetas1;
    vector<vector<string>> matrizEtiquetas2;
    vector<vector<string>> matrizEtiquetas3;
    vector<string> etiquetas1 = {"Suma Estudiantes Matriculados de Programas Seleccionados (Presencial o Virtual) Primer año", "Suma Estudiantes Matriculados de Programas Seleccionados (Presencial o Virtual)"};
    matrizEtiquetas1.push_back(etiquetas1);
    vector<string> etiquetas2 = {"Codigo Snies", "Nombre del Programa", "Nombre del Institucion", "Diferencial porcentual anual de NEOS"};
    matrizEtiquetas2.push_back(etiquetas2);
    vector<string> etiquetas3 = {"Codigo Snies", " Nombre del Programa sin NEOS en los ultimos 3 semestres"};
    matrizEtiquetas3.push_back(etiquetas3);
    vector<string> datosEtiquetas1;
    vector<string> datosEtiquetas2;
    int sumaPrimerAno = 0;
    int sumaSegundoAno = 0;

    for (map<long, ProgramaAcademico *>::iterator it = programasAcademicos.begin(); it != programasAcademicos.end(); ++it)
    {
        int neosPrimerAno = 0;
        int neosSegundoAno = 0;
        int diferenciaNeos = 0;
        ProgramaAcademico *programa = it->second;
        int idMetodologiaBuscada = programa->getIdMetodologia();
        if (idMetodologiaBuscada == 1 || idMetodologiaBuscada == 3)
        {
            for (int i = 0; i < Settings::DATOS_ACADEMICOS; ++i)
            {
                Consolidado *consolidado = programa->getConsolidado(i);
                int matriculados = consolidado->getMatriculados();
                sumaPrimerAno += matriculados;
            }

            for (int i = 0; i < Settings::DATOS_ACADEMICOS; ++i)
            {
                Consolidado *consolidado = programa->getConsolidado(i + 4);
                int matriculados = consolidado->getMatriculados();
                sumaSegundoAno += matriculados;
            }
        }
        for (int i = 0; i < Settings::DATOS_ACADEMICOS; ++i)
        {
            Consolidado *consolidado = programa->getConsolidado(i);
            int numNeos = consolidado->getMatriculadosPrimerSemestre();
            neosPrimerAno += numNeos;
        }

        for (int i = 0; i < Settings::DATOS_ACADEMICOS; ++i)
        {
            Consolidado *consolidado = programa->getConsolidado(i + 4);
            int numNeos = consolidado->getMatriculadosPrimerSemestre();
            neosSegundoAno += numNeos;
        }

        if (neosPrimerAno != 0)
        {
            diferenciaNeos = ((neosSegundoAno - neosPrimerAno) * 100) / neosPrimerAno;
        }
        else
        {
            diferenciaNeos = 0;
        }
        datosEtiquetas2 = {to_string(programa->getCodigoSniesDelPrograma()), programa->getProgramaAcademico(), programa->getInstitucionDeEducacionSuperiorIes(), to_string(diferenciaNeos)};
        matrizEtiquetas2.push_back(datosEtiquetas2);
        int SumaNeosPrimerSemestre;
        int SumaNeosSegundoSemestre;
        int SumaNeosTercerSemestre;
        int SumaNeosCuartoSemestre;
        for (int i = 0; i < 4; ++i)
        {
            Consolidado *consolidados[8];
            if (i == 0)
            {
                consolidados[0] = programa->getConsolidado(i);
                consolidados[1] = programa->getConsolidado(i + 2);
                int neosHombres = consolidados[0]->getMatriculadosPrimerSemestre();
                int neosMujeres = consolidados[1]->getMatriculadosPrimerSemestre();
                SumaNeosPrimerSemestre = neosHombres + neosMujeres;
            }
            else if (i == 1)
            {
                consolidados[2] = programa->getConsolidado(i);
                consolidados[3] = programa->getConsolidado(i + 2);
                int neosHombres = consolidados[2]->getMatriculadosPrimerSemestre();
                int neosMujeres = consolidados[3]->getMatriculadosPrimerSemestre();
                SumaNeosSegundoSemestre = neosHombres + neosMujeres;
            }
            else if (i == 2)
            {
                consolidados[4] = programa->getConsolidado(i + 2);
                consolidados[5] = programa->getConsolidado(i + 4);
                int neosHombres = consolidados[4]->getMatriculadosPrimerSemestre();
                int neosMujeres = consolidados[5]->getMatriculadosPrimerSemestre();
                SumaNeosTercerSemestre = neosHombres + neosMujeres;
            }
            else if (i == 3)
            {
                consolidados[6] = programa->getConsolidado(i + 2);
                consolidados[7] = programa->getConsolidado(i + 4);
                int neosHombres = consolidados[6]->getMatriculadosPrimerSemestre();
                int neosMujeres = consolidados[7]->getMatriculadosPrimerSemestre();
                SumaNeosCuartoSemestre = neosHombres + neosMujeres;
            }
        }

        if ((SumaNeosPrimerSemestre == 0 && SumaNeosSegundoSemestre == 0 && SumaNeosTercerSemestre == 0) || (SumaNeosSegundoSemestre == 0 && SumaNeosTercerSemestre == 0 && SumaNeosCuartoSemestre == 0))
        {
            etiquetas3 = {to_string(programa->getCodigoSniesDelPrograma()),
                          programa->getProgramaAcademico()};
        }
    }
    etiquetas1 = {to_string(sumaPrimerAno), to_string(sumaSegundoAno)};
    matrizEtiquetas1.push_back(etiquetas1);
    matrizFinal.insert(matrizFinal.end(), matrizEtiquetas1.begin(), matrizEtiquetas1.end());
    matrizFinal.insert(matrizFinal.end(), matrizEtiquetas2.begin(), matrizEtiquetas2.end());
    matrizFinal.insert(matrizFinal.end(), matrizEtiquetas3.begin(), matrizEtiquetas3.end());

    for (const auto &fila : matrizFinal)
    {
        for (size_t i = 0; i < fila.size(); ++i)
        {
            cout << fila[i];
            if (i < fila.size() - 1)
            {
                cout << ";";
            }
        }
        cout << endl;
    }

    if (flag)
    {
        int op;
        cout<< "-----------------------------------"<<endl;
        cout << "Que tipo de archivo desea generar" << endl;
        cout << "1. CSV" << endl;
        cout << "2. TXT" << endl;
        cout << "3. JSON" << endl;
        cout<< "-----------------------------------"<<endl;
        cout << "Seleccione la opcion que desea:";
        cin >> op;
        cout<< "-----------------------------------"<<endl;

        try {
            if (op == 1) {
                GestorCsv *gestorObjAux = new GestorCsv();
                gestorObjAux->crearArchivoExtra(rutaOutput, matrizFinal);
            } else if (op == 2) {
                GestorTxt *gestorObjAux = new GestorTxt();
                gestorObjAux->crearArchivoExtra(rutaOutput, matrizFinal);
            } else {
                GestorJson *gestorObjAux = new GestorJson();
                gestorObjAux->crearArchivoExtra(rutaOutput, matrizFinal);
            }
        } catch (std::out_of_range &e) {
            std::cerr << "Error al crear el archivo: " << e.what() << std::endl;
        }
    }
}