#pragma once
#include "TrieNode.h"
#include "Lista.h"
using namespace std;

class ArbolTrie{
    private:
        TrieNode* raiz;
        /**
         * destruye todos los nodos del arbol
         * @param nodo nodo actual del recorrido
         */
        void destruir(TrieNode* nodo);
        /**
         * recorre el arbol y muestra las canciones
         * @param nodo nodo en que empieza o se encuentra el recorrido
         */
        void mostrarDesde(TrieNode* nodo);

    public:
        /**
         * constructor
         */
        ArbolTrie();
        /**
         * destructor
         */
        ~ArbolTrie();
        /**
         * crea el arbol
         * @param lista lista de las canciones que se guardaran en el arbol
         */
        void crear(Lista& lista);
        /**
         * inserta una cancion en el arbol
         * @param nodo nodo actual del arbol
         * @param posicion posicion de la letra en el titulo
         * @param cancion cancion a insertar
         */
        void insertar(TrieNode*& nodo,int posicion,Node* cancion);
        /**
         * busca las canciones que empiezan por el string
         * @param s string con el que deben empezar las canciones
         */
        void buscarPrimero(string s);
        /**
         * busca las canciones que contienen el texto
         * @param lista lista con las canciones
         * @param s texto que deben tener las canciones
         */
        void buscarTiene(Lista& lista, string s);
        /**
         * busca canciones que terminen con el texto
         * @param lista contiene las canciones
         * @param s texto con el que deben terminar
         */
        void buscarFinal(Lista& lista, string s);



        /**
         * no llames esto, para eliminar has lo siguiente en el sistema
         *lista.eliminar(id); 
         *ArbolTrie.eliminar();
         *ArbolTrie.crear(lista);
         *reemplaza ArbolTrie con el que hayas creado en el sistema
         */
        void eliminar();
};