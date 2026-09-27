# Doxygen
*    @brief	|   Descripción corta (una línea) del elemento
*    @details |  Descripción detallada/larga
*    @param[in] /@param[out] /@param[in,out] | Documenta un parámetro (indica dirección)
*    @return	| Describe el valor de retorno
*    @retval	| Describe un valor de retorno específico
*    @pre	| Condición pre (precondición)
*    @post	| Condición post (postcondición)
*    @author	| Autor del código
*    @date	| Fecha de creación
*    @file	| Documenta el archivo completo
*    @see	| Referencias cruzadas a otros elementos
*    @note	| Nota informativa destacada
*    @warning    | Advertencia destacada
*    @todo	| Tarea pendiente
*    @deprecated	| Indica que el elemento está obsoleto
*    @class	| Documenta una clase
*    @struct	| Documenta una estructura
*    @enum	| Documenta un tipo enumerado
*    @fn	    | Documenta una función (si no es auto-detectada)
*    @var	| Documenta una variable
*    @mainpage	| Crea la página principal de la documentación
*    @page	| Crea una página flotante adicional
*    @section	| Crea una sección dentro de una página
*    @subsection	| Crea una subsección
*    @verbatim / @endverbatim | Inserta texto literal (ej. ejemplos de código)
*    @code / @endcode | Inserta un fragmento de código
*    @image html | Inserta una imagen
*    @ref    | Crea un enlace a otro elemento documentado
*    @anchor | Crea un ancla para enlazar
*    @ingroup | Agrupa el elemento en un grupo
*    @defgroup | Define un grupo de elementos


# Clase Vector

La clase vector sirve para probar templates. Métodos utilizables:
* Operador []: Te devuelve el dato de la posición dada del vector. Puedes pasarle tanto el índice numérico como la dirección de memoria del dato apuntado. Está blindado frente a datos const, garantizando que las variantes const no permitan ni modificar los datos const ni recibir valores no-const.
* getTamanio(): Devuelve el tamaño del vector.
* begin(): Devuelve la dirección de memoria del primer elemento del vector para datos no-const.
* end(): Devuelve la dirección de memoria del último elemento del vector  para datos no-const.
* const_begin: Devuelve la dirección de memoria del primer elemento del vector para datos const, sin permitir modificar.
* const_end: Devuelve la dirección de memoria del último elemento del vector para datos const, sin permitir modificar.
* Operador +=: Te permite añadir un nuevo elemento al vector del mismo tipo de dato de los elementos ya existentes, o concatenar otro vector del mismo tipo de dato.


Se puede probar que la clase Vector funciona corriendo estos tests (tests_vector.cpp fue generado por Gemini):
```
cd src
g++ -std=c++11 tests_vector.cpp -o tests
```