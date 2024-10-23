#include "GestorJSON.h"
bool GestorJson::crearArchivo(
    string &ruta, map<int, ProgramaAcademico *> &mapaProgramaAcademico,
    vector<vector<string>> &matrizEtiquetas) {
    string rutaCompleta = ruta + "resultados.csv";
    ofstream archivoResultados(rutaCompleta);

    if (!archivoResultados.is_open()) return false;

    archivoResultados << "{\n";
    archivoResultados << "\"resultados\": [\n";

    map<int, ProgramaAcademico *>::iterator it;
    Consolidado *consolidadoActual;

    for (it = mapaProgramaAcademico.begin(); it != mapaProgramaAcademico.end();
         it++) {
        for (int i = 0; i < 8; i++) {
            archivoResultados << "{\n";
            archivoResultados << "\"codigoDeLaInstitucion\": "
                              << (it->second)->getCodigoDeLaInstitucion()
                              << ",\n";
            archivoResultados << "\"iesPadre\": \""
                              << (it->second)->getIesPadre() << "\",\n";
            archivoResultados
                << "\"institucionDeEducacionSuperiorIes\": \""
                << (it->second)->getInstitucionDeEducacionSuperiorIes()
                << "\",\n";
            archivoResultados << "\"principalOSeccional\": \""
                              << (it->second)->getPrincipalOSeccional()
                              << "\",\n";
            archivoResultados
                << "\"idSectorIes\": " << (it->second)->getIdSectorIes()
                << ",\n";
            archivoResultados << "\"sectorIes\": \""
                              << (it->second)->getSectorIes() << "\",\n";
            archivoResultados
                << "\"idCaracter\": " << (it->second)->getIdCaracter() << ",\n";
            archivoResultados << "\"caracterIes\": \""
                              << (it->second)->getCaracterIes() << "\",\n";
            archivoResultados << "\"codigoDelDepartamentoIes\": "
                              << (it->second)->getCodigoDelDepartamentoIes()
                              << ",\n";
            archivoResultados
                << "\"departamentoDeDomicilioDeLaIes\": \""
                << (it->second)->getDepartamentoDeDomicilioDeLaIes() << "\",\n";
            archivoResultados << "\"codigoDelMunicipioIes\": "
                              << (it->second)->getCodigoDelMunicipioIes()
                              << ",\n";
            archivoResultados << "\"municipioDeDomicilioDeLaIes\": \""
                              << (it->second)->getMunicipioDeDomicilioDeLaIes()
                              << "\",\n";
            archivoResultados << "\"codigoSniesDelPrograma\": "
                              << (it->second)->getCodigoSniesDelPrograma()
                              << ",\n";
            archivoResultados << "\"programaAcademico\": \""
                              << (it->second)->getProgramaAcademico()
                              << "\",\n";
            archivoResultados << "\"idNivelAcademico\": "
                              << (it->second)->getIdNivelAcademico() << ",\n";
            archivoResultados << "\"nivelAcademico\": \""
                              << (it->second)->getNivelAcademico() << "\",\n";
            archivoResultados << "\"idNivelDeFormacion\": "
                              << (it->second)->getIdNivelDeFormacion() << ",\n";
            archivoResultados << "\"nivelDeFormacion\": \""
                              << (it->second)->getNivelDeFormacion() << "\",\n";
            archivoResultados
                << "\"idMetodologia\": " << (it->second)->getIdMetodologia()
                << ",\n";
            archivoResultados << "\"metodologia\": \""
                              << (it->second)->getMetodologia() << "\",\n";
            archivoResultados << "\"idArea\": " << (it->second)->getIdArea()
                              << ",\n";
            archivoResultados << "\"areaDeConocimiento\": \""
                              << (it->second)->getAreaDeConocimiento()
                              << "\",\n";
            archivoResultados << "\"idNucleo\": " << (it->second)->getIdNucleo()
                              << ",\n";
            archivoResultados
                << "\"nucleoBasicoDelConocimientoNbc\": \""
                << (it->second)->getNucleoBasicoDelConocimientoNbc() << "\",\n";
            archivoResultados << "\"idCineCampoAmplio\": "
                              << (it->second)->getIdCineCampoAmplio() << ",\n";
            archivoResultados << "\"descCineCampoAmplio\": \""
                              << (it->second)->getDescCineCampoAmplio()
                              << "\",\n";
            archivoResultados << "\"idCineCampoEspecifico\": "
                              << (it->second)->getIdCineCampoEspecifico()
                              << ",\n";
            archivoResultados << "\"descCineCampoEspecifico\": \""
                              << (it->second)->getDescCineCampoEspecifico()
                              << "\",\n";
            archivoResultados << "\"idCineCodigoDetallado\": "
                              << (it->second)->getIdCineCodigoDetallado()
                              << ",\n";
            archivoResultados << "\"descCineCodigoDetallado\": \""
                              << (it->second)->getDescCineCodigoDetallado()
                              << "\",\n";
            archivoResultados
                << "\"codigoDelDepartamentoPrograma\": "
                << (it->second)->getCodigoDelDepartamentoPrograma() << ",\n";
            archivoResultados
                << "\"departamentoDeOfertaDelPrograma\": \""
                << (it->second)->getDepartamentoDeOfertaDelPrograma()
                << "\",\n";
            archivoResultados << "\"codigoDelMunicipioPrograma\": "
                              << (it->second)->getCodigoDelMunicipioPrograma()
                              << ",\n";
            archivoResultados << "\"municipioDeOfertaDelPrograma\": \""
                              << (it->second)->getMunicipioDeOfertaDelPrograma()
                              << "\"\n";

            consolidadoActual = (it->second)->getConsolidado(i);

            archivoResultados
                << "\"idSexo\": " << consolidadoActual->getIdSexo() << ",\n";
            archivoResultados << "\"sexo\": \"" << consolidadoActual->getSexo()
                              << "\",\n";
            archivoResultados << "\"ano\": " << consolidadoActual->getAno()
                              << ",\n";
            archivoResultados
                << "\"semestre\": " << consolidadoActual->getSemestre()
                << ",\n";
            archivoResultados
                << "\"admitidos\": " << consolidadoActual->getAdmitidos()
                << ",\n";
            archivoResultados
                << "\"graduados\": " << consolidadoActual->getGraduados()
                << ",\n";
            archivoResultados
                << "\"inscritos\": " << consolidadoActual->getInscritos()
                << ",\n";
            archivoResultados
                << "\"matriculados\": " << consolidadoActual->getMatriculados()
                << ",\n";
            archivoResultados
                << "\"neos\": "
                << consolidadoActual->getMatriculadosPrimerSemestre() << "\n";

            archivoResultados << "},\n";
        }
    }

    archivoResultados << "]\n";
    archivoResultados << "}\n";

    return true;
}

bool GestorJson::crearArchivoBuscados(
    string &ruta, list<ProgramaAcademico *> &programaBuscados,
    vector<vector<string>> &matrizEtiquetas) {}