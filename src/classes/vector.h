#ifndef GL_Vector_h
#define GL_Vector_h
#include <cassert>

template <typename T>
class Vector {
    private:
        T* elem;
        int tamanio;

        using iterator = T*;
        using const_iterator = const T*;

        void Redim(int nuevo_tam) {
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

    public:
        Vector() : elem(nullptr), tamanio(0) {}
        
        Vector(int num_els) : elem(nullptr), tamanio(0) {
            assert(num_els >= 0);
            Redim(num_els);
        }
        
        ~Vector() {
            delete[] elem;
            elem = nullptr;
            tamanio = 0;
        }
        
        Vector(const Vector& copia) : elem(nullptr), tamanio(0) {
            Redim(copia.getTamanio());
            for (int i = 0; i < tamanio; ++i) {
                elem[i] = copia[i];
            }
        }
        
        Vector& operator=(const Vector& copia) {
            if (this != &copia) {
                Redim(copia.getTamanio());
                for (int i = 0; i < tamanio; ++i) {
                    elem[i] = copia[i];
                }
            }
            return *this;
        }

        T& operator[](int indice) { return elem[indice]; }
        const T& operator[](int indice) const { return elem[indice]; }
        
        T& operator[](T* indice) { return *indice; }
        const T& operator[](T* indice) const { return *indice; }

        int getTamanio() const { return tamanio; }
        
        iterator begin() { return elem; }
        iterator end() { return (elem + tamanio); }
        const_iterator const_begin() const { return elem; }
        const_iterator const_end() const { return (elem + tamanio); }
        
        Vector& operator+=(const T& nuevo_el) {
            Redim(tamanio + 1);
            elem[tamanio - 1] = nuevo_el;
            return *this;
        }
        
        Vector& operator+=(const Vector& otro) {
            int tam_old = tamanio;
            Redim(tamanio + otro.getTamanio());
            
            for (int i = 0; i < otro.getTamanio(); ++i) {
                elem[tam_old + i] = otro[i];
            }
            return *this;
        }
};

#endif