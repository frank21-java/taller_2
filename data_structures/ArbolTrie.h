#pragma once
#include "TrieNode.h"
#include "Lista.h"
using namespace std;

class ArbolTrie{
    private:
        TrieNode* raiz;
        void insertarRecursivo(TrieNode*& nodo, string titulo,int posicion,Node* cancion);
        void destruir(TrieNode* nodo);
        void mostrar(TrieNode* nodo,string titulo);

    public:
        ArbolTrie();
        ~ArbolTrie();
        void crear(Lista& lista);
        void insertar(Node* cancion);
        void eliminar(int id);
        void buscarPrimero(string s);
        void buscarTiene(Lista& lista, string s);
        void buscarFinal(Lista& lista, string s);
};