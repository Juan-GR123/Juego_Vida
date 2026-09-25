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
