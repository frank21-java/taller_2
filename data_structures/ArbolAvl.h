#pragma once
#include "AvlNode.h"
using namespace std;

class ArbolAvl{
    private:
        AvlNode* raiz;
        /**
         * inserta al arbol
         * @param nodo raiz o nodo actual
         * @param cancion se quiere agregar
         * @return nueva raiz
         */
        AvlNode* insertarRecursivo(AvlNode* nodo, Node* cancion);
        /**
         * revisa altura de un nodo
         * @param nodo se revisa su altura
         * @return altura del nodo
         */
        int altura(AvlNode* nodo);
        /**
         * revisa que este balanceado el arbol
         * @param nodo revisar
         * @return valor del balance
         */
        int balance(AvlNode* nodo);
        /**
         * rota izquierda si desbalance
         * @param nodo desbalanceado
         * @return nodo
         */
        AvlNode* rotarIzq(AvlNode* nodo);
        /**
         * rota derecha si desbalance
         * @param nodo desbalanceado
         * @return nodo
         */
        AvlNode* rotarDer(AvlNode* nodo);
        /**
         * destruye el arbol en postorden
         * @param nodo nodo que se esta borrando
         */
        void destruir(AvlNode* nodo);
        /**
         * muestra todos los artistas en inorder
         * @param nodo actual
         */
        void mostrarArtistas(AvlNode* nodo);
        /**
         * muestra las canciones de x artista en inorden
         * @param nodo actual
         * @param artista se busca
         */
        void mostrarCanciones(AvlNode* nodo, string artista);

    public:
        ArbolAvl();
        ~ArbolAvl();
        /**
         * crea el arbol
         * @param lista lista de las canciones
         */
        void crear(Lista& lista);
        /**
         * inserta una cancion en el arbol
         * @param cancion se inserta
         */
        void insertar(Node* cancion);
        /**
         * llama a la funcion privada pq esta no tiene para raiz
         */
        void mostrarArtistas();
        /**
         * llama al recursivo
         * @param artista se busca sus canciones
         */
        void mostrarCanciones(string artista);

        /**
         * lo mismo que con el arbol trie
         * 1. eliminar de la lista
         * 2. llamar esto
         * 3. volver a crear
         */
        void eliminar();

};