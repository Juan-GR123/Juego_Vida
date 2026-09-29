#ifndef GL_Vector_cpp
#define GL_Vector_cpp

#include "vector.h"

template <typename T>
void Vector<T>::Redim(int nuevo_tam) {
    assert(nuevo_tam >= 0);
    
    if (nuevo_tam == 0) {
        delete[] elem;
        elem = nullptr;
        tamanio = 0;
        return;
    }

    T* aux_elem = new T[nuevo_tam];
    
    if (elem != nullptr) {
        int elementos_a_copiar = (nuevo_tam < tamanio) ? nuevo_tam : tamanio;
        for (int i = 0; i < elementos_a_copiar; ++i) {
            aux_elem[i] = elem[i];
        }
        delete[] elem;
    }
    
    elem = aux_elem;
    tamanio = nuevo_tam;
}

template <typename T>
Vector<T>::Vector() : elem(nullptr), tamanio(0) {}

template <typename T>
Vector<T>::Vector(int num_els) : elem(nullptr), tamanio(0) {
    assert(num_els >= 0);
    Redim(num_els);
}

template <typename T>
Vector<T>::~Vector() {
    delete[] elem;
    elem = nullptr;
    tamanio = 0;
}

template <typename T>
Vector<T>::Vector(const Vector& copia) : elem(nullptr), tamanio(0) {
    Redim(copia.getTamanio());
    for (int i = 0; i < tamanio; ++i) {
        elem[i] = copia[i];
    }
}

template <typename T>
Vector<T>& Vector<T>::operator=(const Vector& copia) {
    if (this != &copia) {
        Redim(copia.getTamanio());
        for (int i = 0; i < tamanio; ++i) {
            elem[i] = copia[i];
        }
    }
    return *this;
}

template <typename T>
T& Vector<T>::operator[](int indice) { 
    return elem[indice]; 
}

template <typename T>
const T& Vector<T>::operator[](int indice) const { 
    return elem[indice]; 
}

template <typename T>
T& Vector<T>::operator[](T* indice) { 
    return *indice; 
}

template <typename T>
const T& Vector<T>::operator[](T* indice) const { 
    return *indice; 
}

template <typename T>
int Vector<T>::getTamanio() const { 
    return tamanio; 
}

template <typename T>
typename Vector<T>::iterator Vector<T>::begin() { 
    return elem; 
}

template <typename T>
typename Vector<T>::iterator Vector<T>::end() { 
    return (elem + tamanio); 
}

template <typename T>
typename Vector<T>::const_iterator Vector<T>::const_begin() const { 
    return elem; 
}

template <typename T>
typename Vector<T>::const_iterator Vector<T>::const_end() const { 
    return (elem + tamanio); 
}

template <typename T>
Vector<T>& Vector<T>::operator+=(const T& nuevo_el) {
    Redim(tamanio + 1);
    elem[tamanio - 1] = nuevo_el;
    return *this;
}

template <typename T>
Vector<T>& Vector<T>::operator+=(const Vector& otro) {
    int tam_old = tamanio;
    Redim(tamanio + otro.getTamanio());
    
    for (int i = 0; i < otro.getTamanio(); ++i) {
        elem[tam_old + i] = otro[i];
    }
    return *this;
}

#endif