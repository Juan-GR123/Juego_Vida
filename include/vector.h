#ifndef GL_Vector_h
#define GL_Vector_h

#include <cassert>

<<<<<<< HEAD
=======
// Como es una clase template, se incluye el archivo .cpp para que el compilador 
// pueda generar las instancias correctamente.
#include "vector.cpp"

>>>>>>> 010b994d05657cdb35cb6915760220b2e734a8bc
/**
 * @brief Clase Vector genérica dinámica basada en plantillas.
 * @tparam T Tipo de dato almacenado en el vector.
 */

//template <typename T>: Declara la variable de tipo (T) para que el compilador la reconozca.
//Vector<T>::: Indica el ámbito (namespace o clase) al que pertenece la función, especificando que se trata de la versión de la clase Vector parametrizada con ese tipo T.

template <typename T>
class Vector {
    private:
        T* elem;           /**< Puntero a los elementos del vector. */
        int tamanio;       /**< Tamaño actual del vector. */

        using iterator = T*;
        using const_iterator = const T*;

        /**
         * @brief Redimensiona el vector al nuevo tamaño especificado.
         * @param nuevo_tam Nuevo tamaño que tendrá el vector.
         */
        void Redim(int nuevo_tam);

    public:
        /**
         * @brief Constructor por defecto. Crea un vector vacío.
         */
        Vector();
        
        /**
         * @brief Constructor con tamaño inicial.
         * @param num_els Número de elementos iniciales.
         */
        Vector(int num_els);
        
        /**
         * @brief Destructor. Libera la memoria dinámica asignada.
         */
        ~Vector();
        
        /**
         * @brief Constructor de copia.
         * @param copia Vector que se desea copiar.
         */
        Vector(const Vector& copia);
        
        /**
         * @brief Operador de asignación.
         * @param copia Vector que se desea asignar.
         * @return Referencia al vector actual modificado.
         */
        Vector& operator=(const Vector& copia);

        /**
         * @brief Operador de acceso por índice (lectura y escritura).
         * @param indice Posición del elemento.
         * @return Referencia al elemento en esa posición.
         */
        T& operator[](int indice);
        
        /**
         * @brief Operador de acceso por índice constante (solo lectura).
         * @param indice Posición del elemento.
         * @return Referencia constante al elemento en esa posición.
         */
        const T& operator[](int indice) const;
        
        /**
         * @brief Operador de acceso mediante puntero (lectura y escritura).
         * @param indice Puntero al elemento.
         * @return Referencia al elemento apuntado.
         */
        T& operator[](T* indice);
        
        /**
         * @brief Operador de acceso mediante puntero constante (solo lectura).
         * @param indice Puntero al elemento.
         * @return Referencia constante al elemento apuntado.
         */
        const T& operator[](T* indice) const;

        /**
         * @brief Obtiene el tamaño actual del vector.
         * @return Número de elementos en el vector.
         */
        int getTamanio() const;
        
        /**
         * @brief Devuelve un iterador al principio del vector.
         */
        iterator begin();
        
        /**
         * @brief Devuelve un iterador al final del vector.
         */
        iterator end();
        
        /**
         * @brief Devuelve un iterador constante al principio del vector.
         */
        const_iterator const_begin() const;
        
        /**
         * @brief Devuelve un iterador constante al final del vector.
         */
        const_iterator const_end() const;
        
        /**
         * @brief Operador para añadir un nuevo elemento al final.
         * @param nuevo_el Elemento a añadir.
         * @return Referencia al vector modificado.
         */
        Vector& operator+=(const T& nuevo_el);
        
        /**
         * @brief Operador para concatenar otro vector al final.
         * @param otro Vector que se desea añadir.
         * @return Referencia al vector modificado.
         */
        Vector& operator+=(const Vector& otro);
};

<<<<<<< HEAD
// Como es una clase template, se incluye el archivo .cpp para que el compilador 
// pueda generar las instancias correctamente.
#include "vector.tpp"

=======
>>>>>>> 010b994d05657cdb35cb6915760220b2e734a8bc
#endif