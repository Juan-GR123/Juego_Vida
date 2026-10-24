#ifndef JUEGO_VIDA_H
#define JUEGO_VIDA_H

#include <string>
#include <vector>

using namespace std;
//añadir despues doxygen

template <typename T>

class JuegoVida {
    private:
        vector<vector<T>> tablero;
        int filas;
        int columnas;


        /**
         * @brief Cuenta las células vivas vecinas de una posición.
         * @param f Fila de la celda.
         * @param c Columna de la celda.
         * @return Número de vecinos vivos, entre 0 y 8.
         */
        int ContarVecinosVivos(int f, int c) const;

    public:

        /**
         * @brief Constructor por defecto.
         * @post El tablero está vacío y sus dimensiones son cero.
         */
        JuegoVida();

        /**
         * @brief Carga el patrón inicial desde un fichero.
         * @param nombre_fichero Nombre del fichero de entrada.
         * @return true si la carga tiene éxito; false en caso de error.
         */
        bool CargarPatron(const string& nombre_fichero);
 
        /**
         * @brief Amplía el tablero si hay células vivas en los bordes.
         * @post Se actualizan el tablero y sus dimensiones si hay ampliación.
         */
        void AjustarDimensiones();

        /**
         * @brief Simula el juego durante un número de generaciones.
         * @param n Número de iteraciones.
         */
        void Evolucionar(int n);

        /**
         * @brief Cuenta las celdas vivas del tablero.
         * @return Número total de celdas vivas.
         */
        int ObtenerCeldasVivas() const;

        /**
         * @brief Calcula los límites y dimensiones del patrón vivo mínimo.
         * @param min_f Primera fila con células vivas.
         * @param max_f Última fila con células vivas.
         * @param min_c Primera columna con células vivas.
         * @param max_c Última columna con células vivas.
         * @param dim_f Número de filas del rectángulo mínimo.
         * @param dim_c Número de columnas del rectángulo mínimo.
         */
        void ObtenerDimensionesMinimas(int& min_f, int& max_f, int& min_c, int& max_c, int& dim_f, int& dim_c) const;
        
        /**
         * @brief Guarda el patrón final en un fichero.
         * @param fichero_salida Nombre del fichero de salida.
         */
        void GuardarResultado(const string& fichero_salida) const;
};

#include "JuegoVida.tpp"

#endif