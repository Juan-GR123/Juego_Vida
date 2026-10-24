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

# ¿Cómo probar que el main funciona?:
```
g++ -std=c++11 -Iinclude src/main.cpp -o main
./main
```