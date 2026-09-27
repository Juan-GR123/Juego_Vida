#include <iostream>
#include <string>
#include <chrono>
#include "JuegoVida.h"

using namespace std;

//argc: Es un número entero (int) que representa el número total de argumentos que se le han pasado al programa al ejecutarlo.
// si ponemos ./juego_vida(1) exploder.txt(2) 100(3), el valor de argc será 3 debido a que se han pasdo 3 argumentos en terminal

//argv:Es un array de punteros a caracteres (char* argv[]), que en la práctica funciona como un array de
//cadenas de texto (strings) donde se almacenan los argumentos que se pasaron por la consola. 
/*
En el ejemplo de antas:

argv[0] = ./juego_vida
argv[1] = exploder.txt
argv[2] = 100
*/

int main(int argc, char* argv[]) {

    // Empezamos a medir el tiempo al iniciar el programa
    //auto: deduccion de tipos
    //alternativamente se puede poner: chrono::time_point<chrono::high_resolution_clock> tiempo_inicio
    auto tiempo_inicio = chrono::high_resolution_clock::now();

    int codigo_salida = 0;

    //Comprobar que se pasan los argumentos correctos por línea de comandos
    if (argc != 3) {
        cerr << "Uso: " << argv[0] << " <fichero_patron.txt> <num_iteraciones>\n";
        codigo_salida = 1;
    } else {
        string nombre_fichero = argv[1];
        int num_iteraciones = stoi(argv[2]);

        JuegoVida juego;

        if (!juego.CargarPatron(nombre_fichero)) {
            cerr << "Error: No se pudo abrir o leer correctamente el fichero " << nombre_fichero << "\n";
            codigo_salida = 1;
        } else {
            juego.Evolucionar(num_iteraciones);

            auto tiempo_fin = chrono::high_resolution_clock::now();
            chrono::duration<double> tiempo_transcurrido = tiempo_fin - tiempo_inicio;

            int celdas_vivas = juego.ObtenerCeldasVivas();
            int min_f, max_f, min_c, max_c, dim_f, dim_c;
            juego.ObtenerDimensionesMinimas(min_f, max_f, min_c, max_c, dim_f, dim_c);

            // Mostrar por pantalla
            cout << num_iteraciones << " iteraciones\n";
            cout << celdas_vivas << " celdas vivas\n";
            cout << "Dimensiones: " << dim_f << " x " << dim_c << "\n";
            cout << tiempo_transcurrido.count() << " segundos\n";

            // Pedir el fichero de salida
            cout << "Fichero de salida: ";
            string fichero_salida;
            cin >> fichero_salida;

            juego.GuardarResultado(fichero_salida);
        }
    }

    return codigo_salida;
}

/*
para ejecutar
g++ main.cpp JuegoVida.cpp -o juego_vida
./juego_vida exploder.txt 100
*/