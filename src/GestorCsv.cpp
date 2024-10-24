#include "GestorCsv.h"
GestorCsv::GestorCsv() { this->DELIMITADOR = Settings::DELIMITADOR; }
// FIXME: LA LECTURA DE ARCHIVOS CON GETLINE FUNCIONA HORRIBLEMENTE, NO TENEMOS
// IDEA DE POR QUÉ

// borré el leerArchivoPrimera y leerArchivoSegunda (Isabella Erazo)

bool GestorCsv::crearArchivo(string &ruta, map<int, ProgramaAcademico *> &mapadeProgramasAcademicos,vector<string> etiquetasColumnas) {
    string rutaCompleta = ruta + "resultados.csv";
    ofstream archivoResultados(rutaCompleta);

    if (!archivoResultados.is_open()) return false;

    // Imprimimos en el archivo las etiquetas (Primera fila)
    for (int i = 0; i < etiquetasColumnas.size(); i++) {
        archivoResultados << etiquetasColumnas[i] << DELIMITADOR;
    }
    archivoResultados << "GRADUADOS;INSCRITOS;MATRICULADOS;NEOS" << endl;

    map<int, ProgramaAcademico *>::iterator it;
    // Leemos todos los programas del mapa para imprimirlos en el archivo
    for (it = mapadeProgramasAcademicos.begin();
         it != mapadeProgramasAcademicos.end(); it++) {
        // Imprimimos cada uno de los 8 consolidados por programa
        for (int i = 0; i < 8; i++) {
            // Imprimimos toda la información base del programa academico
            archivoResultados << (it->second)->getCodigoDeLaInstitucion()
                              << DELIMITADOR;
            archivoResultados << (it->second)->getIesPadre() << DELIMITADOR;
            archivoResultados
                << (it->second)->getInstitucionDeEducacionSuperiorIes()
                << DELIMITADOR;
            archivoResultados << (it->second)->getPrincipalOSeccional()
                              << DELIMITADOR;
            archivoResultados << (it->second)->getIdSectorIes() << DELIMITADOR;
            archivoResultados << (it->second)->getSectorIes() << DELIMITADOR;
            archivoResultados << (it->second)->getIdCaracter() << DELIMITADOR;
            archivoResultados << (it->second)->getCaracterIes() << DELIMITADOR;
            archivoResultados << (it->second)->getCodigoDelDepartamentoIes()
                              << DELIMITADOR;
            archivoResultados
                << (it->second)->getDepartamentoDeDomicilioDeLaIes()
                << DELIMITADOR;
            archivoResultados << (it->second)->getCodigoDelMunicipioIes()
                              << DELIMITADOR;
            archivoResultados << (it->second)->getMunicipioDeDomicilioDeLaIes()
                              << DELIMITADOR;
            archivoResultados << (it->second)->getCodigoSniesDelPrograma()
                              << DELIMITADOR;
            archivoResultados << (it->second)->getProgramaAcademico()
                              << DELIMITADOR;
            archivoResultados << (it->second)->getIdNivelAcademico()
                              << DELIMITADOR;
            archivoResultados << (it->second)->getNivelAcademico()
                              << DELIMITADOR;
            archivoResultados << (it->second)->getIdNivelDeFormacion()
                              << DELIMITADOR;
            archivoResultados << (it->second)->getNivelDeFormacion()
                              << DELIMITADOR;
            archivoResultados << (it->second)->getIdMetodologia()
                              << DELIMITADOR;
            archivoResultados << (it->second)->getMetodologia() << DELIMITADOR;
            archivoResultados << (it->second)->getIdArea() << DELIMITADOR;
            archivoResultados << (it->second)->getAreaDeConocimiento()
                              << DELIMITADOR;
            archivoResultados << (it->second)->getIdNucleo() << DELIMITADOR;
            archivoResultados
                << (it->second)->getNucleoBasicoDelConocimientoNbc()
                << DELIMITADOR;
            archivoResultados << (it->second)->getIdCineCampoAmplio()
                              << DELIMITADOR;
            archivoResultados << (it->second)->getDescCineCampoAmplio()
                              << DELIMITADOR;
            archivoResultados << (it->second)->getIdCineCampoEspecifico()
                              << DELIMITADOR;
            archivoResultados << (it->second)->getDescCineCampoEspecifico()
                              << DELIMITADOR;
            archivoResultados << (it->second)->getIdCineCodigoDetallado()
                              << DELIMITADOR;
            archivoResultados << (it->second)->getDescCineCodigoDetallado()
                              << DELIMITADOR;
            archivoResultados
                << (it->second)->getCodigoDelDepartamentoPrograma()
                << DELIMITADOR;
            archivoResultados
                << (it->second)->getDepartamentoDeOfertaDelPrograma()
                << DELIMITADOR;
            archivoResultados << (it->second)->getCodigoDelMunicipioPrograma()
                              << DELIMITADOR;
            archivoResultados << (it->second)->getMunicipioDeOfertaDelPrograma()
                              << DELIMITADOR;

            // Imprimimos la información del consolidado: (ID
            // SEXO;SEXO;AÑO;SEMESTRE;ADMITIDOS;GRADUADOS;INSCRITOS;MATRICULADOS;NEOS)
            Consolidado *consolidadoActual = (it->second)->getConsolidado(i);
            archivoResultados << consolidadoActual->getIdSexo() << DELIMITADOR;
            archivoResultados << consolidadoActual->getSexo() << DELIMITADOR;
            archivoResultados << consolidadoActual->getAno() << DELIMITADOR;
            archivoResultados << consolidadoActual->getSemestre()
                              << DELIMITADOR;
            archivoResultados << consolidadoActual->getAdmitidos()
                              << DELIMITADOR;
            archivoResultados << consolidadoActual->getGraduados()
                              << DELIMITADOR;
            archivoResultados << consolidadoActual->getInscritos()
                              << DELIMITADOR;
            archivoResultados << consolidadoActual->getMatriculados()
                              << DELIMITADOR;
            archivoResultados
                << consolidadoActual->getMatriculadosPrimerSemestre();
            // Saltamos de linea para la siguiente fila
            archivoResultados << endl;
        }
    }
    // Imprimimos ruta donde quedo el archivo
    cout << "Archivo Creado en: " << rutaCompleta << endl;
    archivoResultados.close();

    return true;
}

bool GestorCsv::crearArchivoBuscados(string &ruta, list<ProgramaAcademico *> &programasBuscados,vector<string> etiquetasColumnas) {
    // Este bool nos ayudará a saber si se creo exitosamente el archivo
    string rutaCompleta = ruta + "buscados.csv";
    ofstream archivoBuscados(rutaCompleta);

    if (!archivoBuscados.is_open()) return false;

    // Imprimimos en el archivo las etiquetas (Primera fila)
    for (int i = 0; i < etiquetasColumnas.size(); i++) {
        archivoBuscados << etiquetasColumnas[i] << DELIMITADOR;
    }
    archivoBuscados << "GRADUADOS;INSCRITOS;MATRICULADOS;NEOS" << endl;

    list<ProgramaAcademico *>::iterator it;
    // Leemos todos los programas de la lista de los programas buscados para
    // imprimirlos
    for (it = programasBuscados.begin(); it != programasBuscados.end(); it++) {
        // Imprimimos los 8 consolidados del programa
        for (int i = 0; i < 8; i++) {
            // Imprimimos la informacion base del programa
            archivoBuscados << (*it)->getCodigoDeLaInstitucion() << DELIMITADOR;
            archivoBuscados << (*it)->getIesPadre() << DELIMITADOR;
            archivoBuscados << (*it)->getInstitucionDeEducacionSuperiorIes()
                            << DELIMITADOR;
            archivoBuscados << (*it)->getPrincipalOSeccional() << DELIMITADOR;
            archivoBuscados << (*it)->getIdSectorIes() << DELIMITADOR;
            archivoBuscados << (*it)->getSectorIes() << DELIMITADOR;
            archivoBuscados << (*it)->getIdCaracter() << DELIMITADOR;
            archivoBuscados << (*it)->getCaracterIes() << DELIMITADOR;
            archivoBuscados << (*it)->getCodigoDelDepartamentoIes()
                            << DELIMITADOR;
            archivoBuscados << (*it)->getDepartamentoDeDomicilioDeLaIes()
                            << DELIMITADOR;
            archivoBuscados << (*it)->getCodigoDelMunicipioIes() << DELIMITADOR;
            archivoBuscados << (*it)->getMunicipioDeDomicilioDeLaIes()
                            << DELIMITADOR;
            archivoBuscados << (*it)->getCodigoSniesDelPrograma()
                            << DELIMITADOR;
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
            archivoBuscados << (*it)->getNucleoBasicoDelConocimientoNbc()
                            << DELIMITADOR;
            archivoBuscados << (*it)->getIdCineCampoAmplio() << DELIMITADOR;
            archivoBuscados << (*it)->getDescCineCampoAmplio() << DELIMITADOR;
            archivoBuscados << (*it)->getIdCineCampoEspecifico() << DELIMITADOR;
            archivoBuscados << (*it)->getDescCineCampoEspecifico()
                            << DELIMITADOR;
            archivoBuscados << (*it)->getIdCineCodigoDetallado() << DELIMITADOR;
            archivoBuscados << (*it)->getDescCineCodigoDetallado()
                            << DELIMITADOR;
            archivoBuscados << (*it)->getCodigoDelDepartamentoPrograma()
                            << DELIMITADOR;
            archivoBuscados << (*it)->getDepartamentoDeOfertaDelPrograma()
                            << DELIMITADOR;
            archivoBuscados << (*it)->getCodigoDelMunicipioPrograma()
                            << DELIMITADOR;
            archivoBuscados << (*it)->getMunicipioDeOfertaDelPrograma()
                            << DELIMITADOR;

            // Imprimimos la información del consolidado: (ID
            // SEXO;SEXO;AÑO;SEMESTRE;ADMITIDOS;GRADUADOS;INSCRITOS;MATRICULADOS;NEOS)
            Consolidado *consolidadoActual = (*it)->getConsolidado(i);
            archivoBuscados << consolidadoActual->getIdSexo() << DELIMITADOR;
            archivoBuscados << consolidadoActual->getSexo() << DELIMITADOR;
            archivoBuscados << consolidadoActual->getAno() << DELIMITADOR;
            archivoBuscados << consolidadoActual->getSemestre() << DELIMITADOR;
            archivoBuscados << consolidadoActual->getAdmitidos() << DELIMITADOR;
            archivoBuscados << consolidadoActual->getGraduados() << DELIMITADOR;
            archivoBuscados << consolidadoActual->getInscritos() << DELIMITADOR;
            archivoBuscados << consolidadoActual->getMatriculados()
                            << DELIMITADOR;
            archivoBuscados
                << consolidadoActual->getMatriculadosPrimerSemestre();
            // Saltamos de linea para la siguiente fila
            archivoBuscados << endl;
        }
    }

    // Cambiamos el valor del booleano si logramos llegar hasta este punto
    // Imprimimos ruta donde quedo el archivo
    cout << "Archivo Creado en: " << rutaCompleta << endl;
    archivoBuscados.close();

    return true;
}

bool GestorCsv::crearArchivoExtra(string &ruta){
    
    return true;
}