#pragma once
#include "AvlNode.h"
using namespace std;

class ArbolAvl{
    private:
        AvlNode* raiz;
        AvlNode* insertarRecursivo(AvlNode* nodo, string artista);
        AvlNode* eliminarRecursivo(AvlNode* nodo, string artista);
        AvlNode* buscarRecursivo(AvlNode* nodo, string artista);
        int altura(AvlNode* nodo);
        int balance(AvlNode* nodo);
        AvlNode* rotarIzq(AvlNode* nodo);
        AvlNode* rotarDer(AvlNode* nodo);
        void destruir(AvlNode* nodo);

    public:
        ArbolAvl();
        ~ArbolAvl();
        void crear(Lista& lista);
        void insertar(AvlNode* cancion);
        void eliminar(AvlNode* cancion);
        void mostrarArtistas();
        void mostrarCanciones(string artista);
};