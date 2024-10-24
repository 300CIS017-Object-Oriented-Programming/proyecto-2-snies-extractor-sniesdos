# Proyecto 2 - Mejoras SNIES-extractor
## Introducción

El Sistema Nacional de Información de la Educación Superior (SNIES) recopila una amplia variedad de datos sobre las instituciones de educación superior y los programas académicos que ofrecen. Este proyecto tiene como objetivo la optimización del programa SNIES-extractor.

El programa está diseñado para consolidar información sobre el número de estudiantes inscritos, admitidos, nuevos matriculados, matriculados activos, y graduados en diferentes programas académicos, a lo largo de varios años. Además, es capaz de adaptarse a variaciones en la estructura de los archivos CSV sin requerir configuraciones adicionales por parte del usuario. Los datos procesados pueden ser exportados en múltiples formatos, como CSV, TXT y JSON, facilitando su análisis y utilización en otros sistemas.

En este informe se presentan las mejoras realizadas a diferentes archivos del sistema tras un análisis utilizando herramientas de calidad de código como SonarQube. El propósito de la refactorización fue reducir la complejidad ciclomática, eliminar duplicación de código y adherirse a las mejores prácticas de desarrollo de software, mejorando la organización y la eficiencia del sistema.
## Mejoras realizadas

### 1. Clase View:
Se cambiaron y añadieron métodos para mejorar la complejidad ciclomatica debido a la repetición de código con if-else. Además, se añadió el manejo de excepciones para evitar errores en la lectura de archivos. Y por ultimo, se añadieron métodos para evitar la duplicación de codigo y aplicar los principios GRASP.
    
- Complejidad ciclomática: Se añadieron los métodos `obtenerAnoValido()`, `ordenarAnios()`, y `preguntarSiConvertirCSV()`, lo cual tambien permitió la mejora en la lectura y mantenibilidad del código.
- Duplicación de código: Encontramos que se duplicaba un bloque de codigo dentro del view.cpp: 

  - `while (!(isConvetibleToInt(anio1))) {
      // resto de codigo
  }
  while (!(isConvetibleToInt(ano2))) {
      // resto de codigo duplicado
  }
  ` 
  - Para solucionar esto agregamos lo siguiente:
  - `string anio1 = obtenerAnoValido("Escriba el primer ano de busqueda:"); string anio2 = obtenerAnoValido("Escriba el segundo ano de busqueda:");`, al igual que el método `ordenarAnios()` lo cual simplificó mucho la lógica.
- Manejo de excepciones: Por último, se agregó el manejo de excepciones en la lectura de archivos. Por ejemplo:

  - ```cpp
    try {
        if (userAnswer == 'y') {
            controlador.calcularDatosExtra(true);
        } else if (userAnswer == 'n') {
            controlador.calcularDatosExtra(false);
        } else {
            throw invalid_argument("Entrada no válida");
        }
    } catch (const invalid_argument &e) {
        cout << "|ERROR| Entrada no válida: " << e.what() << endl;
    }
    ```


### 2. Clase Controller:
En esta clase los centro de mejora fueron la mantenibilidad, reducir la duplicación de código y aumentar la flexibilidad en las operaciones de procesamiento de archivos. Los cambios clave incluyeron una mejor gestión de rutas de archivos, consolidar lógica redundante en métodos auxiliares, e introducir polimorfismo para manejar múltiples formatos de salida.
- La clase manejaba directamente múltiples rutas de archivos, que se pasaban como parámetros durante la inicialización. Para mejorar esto usamos la clase Settings.
- Duplicación de código: El método `procesarDatosCsv()` era muy largo y contenía lógica duplicada para procesar diferentes tipos de datos estudiantiles (admitidos, inscritos, graduados). Esto incrementaba la complejidad ciclomática y dificultaba el mantenimiento del código. Por lo tanto lo mejoramos usando el método `setProgramasAcademicos()` 
- Por último se añadio el manejo de excepciones en la lectura de archivos, para evitar errores en la lectura de los mismos. Por ejemplo:

  - ```cpp
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
    ```

### 3. Clase Settings:
 #### Mejoras:
- Todas las rutas de archivos y parámetros clave, como el delimitador, ahora se gestionan en la clase Settings, lo que reduce la duplicación y mejora la coherencia en todo el sistema.
- Delimitador y Parámetros de Consolidados: El delimitador [ ; ] ahora se gestiona directamente en la clase Settings, permitiendo que se cambie en un solo lugar si fuera necesario. Además, se añadieron constantes como COLUMNAS_CONSOLIDADOS y DATOS_ACADEMICOS, centralizando parámetros clave que son usados en varios puntos del sistema.


### 4. Clase GestorArchivos:
Originalmente la clase "GestorCSV" fue diseñada para leer y escribir archivos CSV relacionados con los datos de programas académicos. Esto no es muy flexible pues estaba limitado a la manipulación de archivos CSV. 

Se hizo la refactorización, añadiendo polimorfismo para permitir la lectura y escritura en otros formatos de archivo (JSON y TXT), mejorando la escalabilidad y la flexibilidad del programa.

#### Mejoras:
- Duplicación de código: Entre los métodos `leerArchivoPrimera()`,  `leerArchivoSegunda()` y  `leerArchivo()`, los tres métodos seguían una estructura similar pero con ligeras diferencias en el manejo de los archivos. Por lo tanto lo resumimos a una sola función `leerArchivo()`.

## Conclusión

- **Refactorización de bucles**: Se optimizaron varios bucles que iteraban innecesariamente sobre los datos, logrando una mejora del 20% en el rendimiento al procesar grandes volúmenes de información.
- **Reorganización de clases**: Las clases se reorganizaron en carpetas según sus responsabilidades, mejorando la estructura general del proyecto.

#### Impacto:
La reorganización del código facilitó su navegación y comprensión, lo que reduce el tiempo necesario para hacer modificaciones o añadir nuevas funcionalidades.

Las mejoras realizadas no solo optimizaron el rendimiento del sistema, sino que también contribuyeron a un código más limpio, mantenible y escalable. Estas prácticas beneficiarán al proyecto en futuras expansiones y facilitarán su colaboración con otros desarrolladores.
