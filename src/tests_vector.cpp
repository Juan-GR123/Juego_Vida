#include <iostream>
#include <cassert>
#include <string>
#include "classes/vector.h" // Asegúrate de que tu archivo de cabecera se llame así

// Función de ayuda para imprimir mensajes de éxito
void test_passed(const std::string& test_name) {
    std::cout << "[OK] " << test_name << " superado." << std::endl;
}

void test_constructores_y_tamanio() {
    Vector<int> v_vacio;
    assert(v_vacio.getTamanio() == 0);

    Vector<int> v_tam(5);
    assert(v_tam.getTamanio() == 5);

    test_passed("Constructores y getTamanio");
}

void test_acceso_elementos() {
    Vector<int> v(3);
    v[0] = 10;
    v[1] = 20;
    v[2] = 30;

    assert(v[0] == 10);
    assert(v[1] == 20);
    assert(v[2] == 30);

    // Prueba de acceso constante
    const Vector<int>& v_const = v;
    assert(v_const[1] == 20);

    test_passed("Acceso a elementos (operator[])");
}

void test_iteradores() {
    Vector<int> v(3);
    v[0] = 1; v[1] = 2; v[2] = 3;

    int suma = 0;
    for (auto it = v.begin(); it != v.end(); ++it) {
        suma += *it;
    }
    assert(suma == 6);

    // Prueba de iteradores constantes
    const Vector<int>& v_const = v;
    int suma_const = 0;
    for (auto it = v_const.const_begin(); it != v_const.const_end(); ++it) {
        suma_const += *it;
    }
    assert(suma_const == 6);

    // Prueba de tu operador de acceso por puntero (poco convencional, pero implementado en tu clase)
    int* ptr = v.begin();
    assert(v[ptr] == 1); 

    test_passed("Iteradores y bucles");
}

void test_copia_y_asignacion() {
    Vector<int> v_original(2);
    v_original[0] = 100;
    v_original[1] = 200;

    // Probar constructor de copia (Copia profunda)
    Vector<int> v_copia(v_original);
    assert(v_copia.getTamanio() == 2);
    assert(v_copia[0] == 100);
    
    // Modificar copia para asegurar que no afecta al original
    v_copia[0] = 999;
    assert(v_original[0] == 100); 

    // Probar operador de asignación
    Vector<int> v_asignado;
    v_asignado = v_original;
    assert(v_asignado.getTamanio() == 2);
    assert(v_asignado[1] == 200);

    // Modificar asignado para asegurar independencia
    v_asignado[1] = 888;
    assert(v_original[1] == 200);

    test_passed("Constructor de copia y Asignacion profunda");
}

void test_operadores_suma() {
    Vector<int> v1(2);
    v1[0] = 1; v1[1] = 2;

    // Probar += (elemento)
    v1 += 3;
    assert(v1.getTamanio() == 3);
    assert(v1[2] == 3);

    // Probar += (Vector)
    Vector<int> v2(2);
    v2[0] = 4; v2[1] = 5;

    v1 += v2;
    assert(v1.getTamanio() == 5);
    assert(v1[3] == 4);
    assert(v1[4] == 5);

    test_passed("Operadores += (elemento y vector)");
}

void test_tipos_complejos() {
    // Probar que el template funciona bien con clases, no solo con tipos primitivos
    Vector<std::string> v_str;
    v_str += std::string("Hola");
    v_str += std::string("Mundo");

    assert(v_str.getTamanio() == 2);
    assert(v_str[0] == "Hola");
    assert(v_str[1] == "Mundo");

    test_passed("Templates con tipos complejos (std::string)");
}

int main() {
    std::cout << "--- Iniciando Tests del Vector ---" << std::endl;

    test_constructores_y_tamanio();
    test_acceso_elementos();
    test_iteradores();
    test_copia_y_asignacion();
    test_operadores_suma();
    test_tipos_complejos();

    std::cout << "----------------------------------" << std::endl;
    std::cout << "¡Todos los tests pasaron exitosamente! Tu Vector es seguro." << std::endl;

    return 0;
}