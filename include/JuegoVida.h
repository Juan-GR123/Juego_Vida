#ifndef JUEGO_VIDA_H
#define JUEGO_VIDA_H

#include <string>
#include "vector.h"

using namespace std;

//añadir despues doxygen
class JuegoVida {
private:
    Vector<Vector<char>> tablero;
    int filas;
    int columnas;

    // Función auxiliar privada
    int ContarVecinosVivos(int f, int c) const;

public:
    JuegoVida();

    //CargarPatron: Lee el fichero de texto inicial, extrayendo las dimensiones n (filas) y m(columnas) 
    //junto con la matriz de celdas.   
    bool CargarPatron(const string& nombre_fichero);

    //AjustarDimensiones(): Amplía dinámicamente la matriz de forma rectangular cuando las celdas vivas alcanzan 
    //los bordes del tablero.   
    void AjustarDimensiones();

    //Evolucionar(int n): Simula de forma iterativa n pasos aplicando las reglas de vecindad de Conway 
    //(una celda muerta nace con 3 vecinas vivas; una viva sobrevive con 2 o 3 vecinas). 
    void Evolucionar(int n);

    //ObtenerCeldasVivas() const: Devuelve el recuento total de celdas vivas en el patrón final
    int ObtenerCeldasVivas() const;

    //ObtenerDimensionesMinimas(): Calcula las dimensiones del rectángulo mínimo que contiene estrictamente a todas las 
    //celdas vivas.
    void ObtenerDimensionesMinimas(int& min_f, int& max_f, int& min_c, int& max_c, int& dim_f, int& dim_c) const;
    
    //GuardarResultado: Exporta el patrón final al fichero especificado si la cadena introducida no está vacía.
    void GuardarResultado(const string& fichero_salida) const;
};

#endif