#include "Consolidado.h"
#include <stdexcept>

// Constructor por defecto
Consolidado::Consolidado() = default;

// Constructor con parámetros
Consolidado::Consolidado(int idSexo, const std::string& sexo, int anio, int semestre, const DatosEstudiantes &datos)
    : idSexo(idSexo), sexo(sexo), anio(anio), semestre(semestre),
      inscritos(datos.inscritos), admitidos(datos.admitidos),
      matriculadosPrimerSemestre(datos.primeraMatricula), matriculados(datos.totalMatriculados), graduados(datos.graduados)
{
    if (!esAnioValido(anio)) {
        throw std::invalid_argument("El año ingresado no es válido.");
    }
    if (!esValorPositivo(inscritos) || !esValorPositivo(admitidos) ||
        !esValorPositivo(matriculados) || !esValorPositivo(matriculadosPrimerSemestre) || !esValorPositivo(graduados)) {
        throw std::invalid_argument("Los valores numéricos deben ser positivos.");
        }
}

// Getters
int Consolidado::getIdSexo() const noexcept { return idSexo; }
std::string Consolidado::getSexo() const noexcept { return sexo; }
int Consolidado::getAnio() const noexcept { return anio; }
int Consolidado::getSemestre() const noexcept { return semestre; }
int Consolidado::getInscritos() const noexcept { return inscritos; }
int Consolidado::getAdmitidos() const noexcept { return admitidos; }
int Consolidado::getMatriculados() const noexcept { return matriculados; }
int Consolidado::getMatriculadosPrimerSemestre() const noexcept { return matriculadosPrimerSemestre; }
int Consolidado::getGraduados() const noexcept { return graduados; }

// Setters
void Consolidado::setIdSexo(int nuevoIdSexo) { idSexo = nuevoIdSexo; }
void Consolidado::setSexo(std::string_view nuevoSexo) {
    sexo = nuevoSexo;
}
void Consolidado::setAnio(int nuevoAnio) {
    if (!esAnioValido(nuevoAnio)) {
        throw std::invalid_argument("El año ingresado no es válido.");
    }
    anio = nuevoAnio;
}
void Consolidado::setSemestre(int nuevoSemestre) { semestre = nuevoSemestre; }
void Consolidado::setInscritos(int nuevosInscritos) { inscritos = nuevosInscritos; }
void Consolidado::setAdmitidos(int nuevosAdmitidos) { admitidos = nuevosAdmitidos; }
void Consolidado::setMatriculados(int nuevosMatriculados) { matriculados = nuevosMatriculados; }
void Consolidado::setMatriculadosPrimerSemestre(int nuevosMatriculadosPrimerSemestre) { matriculadosPrimerSemestre = nuevosMatriculadosPrimerSemestre; }
void Consolidado::setGraduados(int nuevosGraduados) { graduados = nuevosGraduados; }

// Validaciones
bool Consolidado::esAnioValido(int anioIngresado) const noexcept {
    return anioIngresado >= 1900 && anioIngresado <= 2100;
}

bool Consolidado::esValorPositivo(int valor) const noexcept {
    return valor >= 0;
}
