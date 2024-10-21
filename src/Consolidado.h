#ifndef CONSOLIDADO_H
#define CONSOLIDADO_H

#include <string>
#include <string_view>

// Estructura para agrupar los datos de los estudiantes
struct DatosEstudiantes
{
    int inscritos;
    int admitidos;
    int primeraMatricula;
    int totalMatriculados;
    int graduados;
};

class Consolidado
{
private:
    int idSexo;
    std::string sexo;
    int anio;
    int semestre;
    int inscritos;
    int admitidos;
    int matriculadosPrimerSemestre;
    int matriculados;
    int graduados;

public:
    // Constructores
    Consolidado();
    Consolidado(int idSexo, const std::string& sexo, int anio, int semestre, const DatosEstudiantes &datos);

    // Getters
    int getIdSexo() const noexcept;
    std::string getSexo() const noexcept;
    int getAnio() const noexcept;
    int getSemestre() const noexcept;
    int getInscritos() const noexcept;
    int getAdmitidos() const noexcept;
    int getMatriculados() const noexcept;
    int getMatriculadosPrimerSemestre() const noexcept;
    int getGraduados() const noexcept;

    // Setters
    void setIdSexo(int idSexo);
    void setSexo(std::string_view nuevoSexo);
    void setAnio(int anio);
    void setSemestre(int semestre);
    void setInscritos(int inscritos);
    void setAdmitidos(int admitidos);
    void setMatriculados(int matriculados);
    void setMatriculadosPrimerSemestre(int matriculadosPrimerSemestre);
    void setGraduados(int graduados);

    // Destructor
    ~Consolidado() = default;

    // Validación de datos
    bool esAnioValido(int anioIngresado) const noexcept;
    bool esValorPositivo(int valor) const noexcept;
};

#endif // CONSOLIDADO_H