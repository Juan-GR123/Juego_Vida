#include "JuegoVida.h"
#include <fstream>

// Constructor por defecto
JuegoVida::JuegoVida() : filas(0), columnas(0) {}

// Función auxiliar para contar vecinos vivos
int JuegoVida::ContarVecinosVivos(int f, int c) const {
    int vecinos = 0;
    for (int df = -1; df <= 1; ++df) { //comprueban de -1 a +1 es decir las celdas de alrededor
        for (int dc = -1; dc <= 1; ++dc) {
            // Evaluamos solo si NO estamos en la celda central (0, 0)
            if (!(df == 0 && dc == 0)) {
                int nf = f + df;
                int nc = c + dc;
                if (nf >= 0 && nf < filas && nc >= 0 && nc < columnas) {
                    if (tablero[nf][nc] == 'X') {
                        vecinos++;
                    }
                }
            }
        }
    }
    return vecinos;
}

// Cargar el patrón inicial desde el fichero
bool JuegoVida::CargarPatron(const string& nombre_fichero) {
    bool exito = true;
    ifstream fichero(nombre_fichero);
    
    if (!fichero.is_open()) {
        exito = false;
    } else {
        if (!(fichero >> filas >> columnas)) {
            exito = false;
        } else {
            fichero.ignore();

            tablero = Vector<Vector<char>>(filas);
            bool error_lectura = false;

            for (int i = 0; i < filas && !error_lectura; ++i) {
                string linea;
                if (!getline(fichero, linea)) {
                    error_lectura = true;
                } else {
                    tablero[i] = Vector<char>(columnas);
                    for (int j = 0; j < columnas; ++j) {
                        if (j < linea.size()) {
                            tablero[i][j] = linea[j];
                        } else {
                            tablero[i][j] = '.';
                        }
                    }
                }
            }

            if (error_lectura) {
                exito = false;
            }
        }
        fichero.close();
    }

    return exito;
}

// Ajustar dimensiones si las celdas llegan a los bordes
void JuegoVida::AjustarDimensiones() {
    bool fila_arriba_viva = false;
    for (int j = 0; j < columnas; ++j) {
        if (tablero[0][j] == 'X') fila_arriba_viva = true;
    }

    bool fila_abajo_viva = false;
    for (int j = 0; j < columnas; ++j) {
        if (tablero[filas - 1][j] == 'X') fila_abajo_viva = true;
    }

    bool col_izq_viva = false;
    for (int i = 0; i < filas; ++i) {
        if (tablero[i][0] == 'X') col_izq_viva = true;
    }

    bool col_der_viva = false;
    for (int i = 0; i < filas; ++i) {
        if (tablero[i][columnas - 1] == 'X') col_der_viva = true;
    }

    if (fila_arriba_viva || fila_abajo_viva || col_izq_viva || col_der_viva) {
        int nuevo_filas = filas + (fila_arriba_viva ? 2 : 0) + (fila_abajo_viva ? 2 : 0);
        int nuevo_cols = columnas + (col_izq_viva ? 2 : 0) + (col_der_viva ? 2 : 0);
        
        int offset_f = fila_arriba_viva ? 1 : 0;
        int offset_c = col_izq_viva ? 1 : 0;

        Vector<Vector<char>> nuevo_tablero(nuevo_filas);
        for (int i = 0; i < nuevo_filas; ++i) {
            nuevo_tablero[i] = Vector<char>(nuevo_cols);
            for (int j = 0; j < nuevo_cols; ++j) {
                nuevo_tablero[i][j] = '.';
            }
        }

        for (int i = 0; i < filas; ++i) {
            for (int j = 0; j < columnas; ++j) {
                nuevo_tablero[i + offset_f][j + offset_c] = tablero[i][j];
            }
        }

        tablero = nuevo_tablero;
        filas = nuevo_filas;
        columnas = nuevo_cols;
    }
}

// Simular n iteraciones
void JuegoVida::Evolucionar(int n) {
    for (int paso = 0; paso < n; ++paso) {
        AjustarDimensiones();
        Vector<Vector<char>> siguiente = tablero;

        for (int i = 0; i < filas; ++i) {
            for (int j = 0; j < columnas; ++j) {
                int vecinos = ContarVecinosVivos(i, j);
                if (tablero[i][j] == 'X') {
                    if (vecinos != 2 && vecinos != 3) {
                        siguiente[i][j] = '.';
                    }
                } else {
                    if (vecinos == 3) {
                        siguiente[i][j] = 'X';
                    }
                }
            }
        }
        tablero = siguiente;
    }
}

// Obtener recuento de celdas vivas
int JuegoVida::ObtenerCeldasVivas() const {
    int celdas = 0;
    for (int i = 0; i < filas; ++i) {
        for (int j = 0; j < columnas; ++j) {
            if (tablero[i][j] == 'X') {
                celdas++;
            }
        }
    }
    return celdas;
}

// Calcular rectángulo mínimo
void JuegoVida::ObtenerDimensionesMinimas(int& min_f, int& max_f, int& min_c, int& max_c, int& dim_f, int& dim_c) const {
    min_f = filas; max_f = -1;
    min_c = columnas; max_c = -1;

    for (int i = 0; i < filas; ++i) {
        for (int j = 0; j < columnas; ++j) {
            if (tablero[i][j] == 'X') {
                if (i < min_f) min_f = i;
                if (i > max_f) max_f = i;
                if (j < min_c) min_c = j;
                if (j > max_c) max_c = j;
            }
        }
    }

    if (ObtenerCeldasVivas() > 0) {
        dim_f = (max_f - min_f) + 1;
        dim_c = (max_c - min_c) + 1;
    } else {
        dim_f = 0;
        dim_c = 0;
    }
}

// Guardar resultado en fichero
void JuegoVida::GuardarResultado(const string& fichero_salida) const {
    if (fichero_salida.empty()) return;

    ofstream salida(fichero_salida);
    if (salida.is_open()) {
        int min_f, max_f, min_c, max_c, dim_f, dim_c;
        ObtenerDimensionesMinimas(min_f, max_f, min_c, max_c, dim_f, dim_c);

        salida << dim_f << "\n";
        salida << dim_c << "\n";

        for (int i = min_f; i <= max_f; ++i) {
            for (int j = min_c; j <= max_c; ++j) {
                salida << tablero[i][j];
            }
            salida << "\n";
        }
        salida.close();
    }
}