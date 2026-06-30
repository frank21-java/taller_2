#pragma once

#include "Lista.h"

class ArbolHeap {
    private:
        Node** datos;
        int cantidad;
        int capacidad;
        void subir(int indice);
        void bajar(int indice);
        void intercambiar(int a, int b);

    public:
        ArbolHeap();
        ~ArbolHeap();
        void crear(Lista& lista);
        void insertar(Node* cancion);
        Node* eliminar();
        void actualizar();
        void mostrarTop();
};