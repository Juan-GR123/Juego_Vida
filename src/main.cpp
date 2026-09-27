#include <iostream>
#include <fstream>
#include <string>
#include <chrono> // Necesario para medir el tiempo empleado
#include "vector.h"
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

        // Abrir el fichero de texto inicial
        ifstream fichero(nombre_fichero);
        if (!fichero.is_open()) {
            cerr << "Error: No se pudo abrir el fichero " << nombre_fichero << "\n";
            codigo_salida = 1;
        } else {
            // Leer la primera línea (número de filas) y la segunda (número de columnas)
            int filas, columnas;
            if (!(fichero >> filas >> columnas)) {
                cerr << "Error: Formato de fichero incorrecto en las dimensiones.\n";
                codigo_salida = 1;
            } else {
                // se ignora el salto de linea despues de la segunda fila
                fichero.ignore();

                // Cargar las n líneas siguientes utilizando la clase Vector
                //Como la clase Vector es unidimensional, para crear una matriz de dos dimensiones (filas y columnas) 
                //creamos un vector de vectores de tipo char.
                Vector<Vector<char>> tablero(filas);
                bool error_lectura = false;

                for (int i = 0; i < filas && !error_lectura; ++i) {
                    string linea;
                    if (!getline(fichero, linea)) {
                        cerr << "Error: Faltan filas en el fichero respecto a las dimensiones indicadas.\n";
                        codigo_salida = 1;
                        error_lectura = true;
                    } else {
                        // Inicializamos cada fila con el número de columnas
                        tablero[i] = Vector<char>(columnas);

                        // Copiamos los caracteres ('.' o 'X') en el Vector
                        for (int j = 0; j < columnas; ++j) {
                            if (j < linea.size()) {
                                tablero[i][j] = linea[j];
                            } else {
                                tablero[i][j] = '.'; // Si por algún motivo la línea del archivo fuera más corta de lo que indicaba la cabecera, el código pone automáticamente un punto . por seguridad para evitar errores de memoria.
                            }
                        }
                    }
                }

                fichero.close();

                // Si todo ha ido bien hasta aquí, procesamos resultados y salida
                if (codigo_salida == 0) {
                    // Paramos el cronómetro de tiempo
                    auto tiempo_fin = chrono::high_resolution_clock::now();
                    chrono::duration<double> tiempo_transcurrido = tiempo_fin - tiempo_inicio;

                    // Calcular celdas vivas y el rectángulo mínimo
                    int celdas_vivas = 0;
                    int min_fila = filas, max_fila = -1;
                    int min_columna = columnas, max_columna = -1;

                    //min_fila guarda el índice de la primera fila (la más arriba) donde se ha encontrado al menos una celda viva (X).
                    //max_fila guarda el índice de la última fila (la más abajo) donde hay una celda viva.
                    for (int i = 0; i < filas; ++i) {
                        for (int j = 0; j < columnas; ++j) {
                            if (tablero[i][j] == 'X') {
                                celdas_vivas++;
                                if (i < min_fila) min_fila = i;
                                if (i > max_fila) max_fila = i;
                                if (j < min_columna) min_columna = j;
                                if (j > max_columna) max_columna = j;
                            }
                        }
                    }

                    //Si restas max_fila - min_fila, estás calculando la distancia o el salto que hay entre la primera y la última fila con vida.

                    int dim_min_filas = 0;
                    int dim_min_cols = 0;
                    if (celdas_vivas > 0) {
                        dim_min_filas = (max_fila - min_fila) + 1;//se le suma 1 porque los indices empiezan en 0 y no queremos que haya confusion con las longitudes
                        dim_min_cols = (max_columna - min_columna) + 1;
                    }

                    //Mostrar por pantalla los datos
                    cout << num_iteraciones << " iteraciones\n";
                    cout << celdas_vivas << " celdas vivas\n";
                    cout << "Dimensiones: " << dim_min_filas << " x " << dim_min_cols << "\n";
                    cout << tiempo_transcurrido.count() << " segundos\n";

                    //Pedir el nombre del fichero de salida
                    cout << "Fichero de salida: ";
                    string fichero_salida;
                    cin >> fichero_salida;

                    // Si el usuario introduce una cadena no vacía, guardamos el resultado
                    if (!fichero_salida.empty()) {
                        ofstream salida(fichero_salida);
                        if (salida.is_open()) {
                            salida << dim_min_filas << "\n";
                            salida << dim_min_cols << "\n";
                            
                            // Escribir solo el rectángulo mínimo que contiene las celdas vivas
                            for (int i = min_fila; i <= max_fila; ++i) {
                                for (int j = min_columna; j <= max_columna; ++j) {
                                    salida << tablero[i][j];
                                }
                                salida << "\n";
                            }
                            salida.close();
                        }
                    }
                }
            }
        }
    }

    return codigo_salida;
}