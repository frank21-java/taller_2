#include "ArbolAvl.h"
#include <iostream>
ArbolAvl::ArbolAvl(){
    raiz=nullptr;
}
void ArbolAvl::crear(Lista& lista){
    Node* aux=lista.getStart();
    while(aux!=nullptr){
        insertar(aux);
        aux=aux->next;
    }
}
int ArbolAvl::balance(AvlNode* nodo){
    if(nodo == nullptr) return 0;
    return altura(nodo->izquierdo) - altura(nodo->derecho);
}
int ArbolAvl::altura(AvlNode* nodo){
    if(nodo==nullptr) return 0;
    return nodo->altura;
}

AvlNode* ArbolAvl::rotarDer(AvlNode* y){
    AvlNode* x = y->izquierdo;
    AvlNode* T2 = x->derecho;
    x->derecho = y;
    y->izquierdo = T2;
    y->altura = max(altura(y->izquierdo), altura(y->derecho)) + 1;
    x->altura = max(altura(x->izquierdo), altura(x->derecho)) + 1;
    return x;
}
AvlNode* ArbolAvl::rotarIzq(AvlNode* x){
    AvlNode* y = x->derecho;
    AvlNode* T2 = y->izquierdo;
    y->izquierdo = x;
    x->derecho = T2;
    x->altura = max(altura(x->izquierdo), altura(x->derecho)) + 1;
    y->altura = max(altura(y->izquierdo), altura(y->derecho)) + 1;
    return y;
}

AvlNode* ArbolAvl::insertarRecursivo(AvlNode* nodo,Node* cancion){
    if(nodo==nullptr){
        AvlNode* nuevo=new AvlNode(cancion);
        return nuevo;
    }
    if(cancion->id < nodo->cancion->id){
        nodo->izquierdo=insertarRecursivo(nodo->izquierdo,cancion);
    }
    else{
        nodo->derecho=insertarRecursivo(nodo->derecho,cancion);
    }
    nodo->altura=1+max(altura(nodo->izquierdo),altura(nodo->derecho));
    int bal=balance(nodo);

    if(bal>1 && cancion->id<nodo->izquierdo->cancion->id) return rotarDer(nodo);
    if(bal < -1 && cancion->id > nodo->derecho->cancion->id) return rotarIzq(nodo);
    if(bal > 1 && cancion->id > nodo->izquierdo->cancion->id){
        nodo->izquierdo = rotarIzq(nodo->izquierdo);
        return rotarDer(nodo);
    }
    if(bal < -1 && cancion->id < nodo->derecho->cancion->id){
        nodo->derecho = rotarDer(nodo->derecho);
        return rotarIzq(nodo);
    }

    return nodo;
}
void ArbolAvl::insertar(Node* nodo){
    raiz=insertarRecursivo(raiz,nodo);
}

void ArbolAvl::destruir(AvlNode* nodo){
    if(nodo==nullptr) return;
    destruir(nodo->izquierdo);
    destruir(nodo->derecho);
    delete nodo;
}
ArbolAvl::~ArbolAvl(){
    destruir(raiz);
    raiz = nullptr;
}

void ArbolAvl::eliminar(){
    destruir(raiz);
}

void ArbolAvl::mostrarArtistas(){
    mostrarArtistas(raiz);
}
void ArbolAvl::mostrarArtistas(AvlNode* nodo){
    if(nodo==nullptr) return;
    mostrarArtistas(nodo->izquierdo);
    cout<<"- "<<nodo->cancion->artista;
    mostrarArtistas(nodo->derecho);
}
void ArbolAvl::mostrarCanciones(string artista){
    mostrarCanciones(raiz,artista);
}
void ArbolAvl::mostrarCanciones(AvlNode* nodo,string artista){
    if(nodo==nullptr) return;
    mostrarCanciones(nodo->izquierdo,artista);
    if(nodo->cancion->artista==artista){
        cout<<"- "<<nodo->cancion->nombre;
    }
    mostrarCanciones(nodo->derecho,artista);
}