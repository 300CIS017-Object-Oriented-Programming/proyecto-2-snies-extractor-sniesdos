#include "Consolidado.h"
#include <string_view>

Consolidado::Consolidado() = default;

Consolidado::Consolidado(int idSexo, std::string_view sexo, int ano, int semestre, const DatosEstudiantes &datos)
    : idSexo(idSexo), sexo(sexo), ano(ano), semestre(semestre),
      inscritos(datos.inscritos), admitidos(datos.admitidos),
      matriculados(datos.primeraMatricula), matriculadosPrimerSemestre(datos.totalMatriculados), graduados(datos.graduados) {}

int Consolidado::getIdSexo() const
{
    return idSexo;
}

void Consolidado::setIdSexo(int nuevoIdSexo)
{
    this->idSexo = nuevoIdSexo;
}

std::string Consolidado::getSexo() const
{
    return std::string(sexo);
}

void Consolidado::setSexo(std::string_view nuevoSexo)
{
    this->sexo = nuevoSexo;
}

int Consolidado::getAno() const
{
    return ano;
}

void Consolidado::setAno(int nuevoAno)
{
    this->ano = nuevoAno;
}

int Consolidado::getSemestre() const
{
    return semestre;
}

void Consolidado::setSemestre(int nuevoSemestre)
{
    this->semestre = nuevoSemestre;
}

int Consolidado::getInscritos() const
{
    return inscritos;
}

void Consolidado::setInscritos(int nuevosInscritos)
{
    this->inscritos = nuevosInscritos;
}

int Consolidado::getAdmitidos() const
{
    return admitidos;
}

void Consolidado::setAdmitidos(int nuevosAdmitidos)
{
    this->admitidos = nuevosAdmitidos;
}

int Consolidado::getMatriculados() const
{
    return matriculados;
}

void Consolidado::setMatriculados(int nuevosMatriculados)
{
    this->matriculados = nuevosMatriculados;
}

int Consolidado::getMatriculadosPrimerSemestre() const
{
    return matriculadosPrimerSemestre;
}

void Consolidado::setMatriculadosPrimerSemestre(int nuevosMatriculadosPrimerSemestre)
{
    this->matriculadosPrimerSemestre = nuevosMatriculadosPrimerSemestre;
}

int Consolidado::getGraduados() const
{
    return graduados;
}

void Consolidado::setGraduados(int nuevosGraduados)
{
    this->graduados = nuevosGraduados;
}
