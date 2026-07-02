#include "ArbolTrie.h"
#include <iostream>
ArbolTrie::ArbolTrie(){
    raiz=nullptr;
}
ArbolTrie::~ArbolTrie(){
    destruir(raiz);
}
void ArbolTrie::mostrarDesde(TrieNode* nodo){
    if(nodo==nullptr) return;
    if(nodo->final==true) cout<<nodo->cancion<<" - "<<nodo->cancion->nombre<<endl;
    mostrarDesde(nodo->hijo);
    mostrarDesde(nodo->hermano);
}
void ArbolTrie::buscarPrimero(string s){
    if(raiz==nullptr) return;
    TrieNode* actual=raiz;
    for(int i=0;i<s.length();i++){
        while(actual!=nullptr&&actual->letra!=s[i]){
            actual=actual->hermano;
        }
        if(actual==nullptr){
            cout<<"no hay canciones que empiezen asi"<<endl;
            return;
        }
        if(i!=s.length()){
            actual=actual->hijo;
        }
        mostrarDesde(actual);
    }
}
void ArbolTrie::buscarTiene(Lista& lista, string s){
    Node* aux=lista.getStart();
    bool existe=false;
    while(aux!=nullptr){
        if(aux->nombre.find(s)==string::npos){
            existe=true;
            cout<<aux->id<<" - "<< aux->nombre<<" - "<<aux->artista<<endl;
        }
        aux=aux->next;
    }
    if(existe==false) cout<<"no hay canciones con ese texto"<<endl;
}
void ArbolTrie::buscarFinal(Lista& lista, string s){
    Node* aux=lista.getStart();
    while(aux!=nullptr){
        bool final=true;
        if(s.length()>=aux->nombre.length()){
            final=false;
        }
        else{
            int tamano=aux->nombre.length()-s.length();
            for(int i=0;i<s.length();i++){
                if(aux->nombre[tamano + i] != s[i]){
                    final=false;
                    break;
                }
            }
        }
        if(final==true){
            cout<<aux->id<<" - "<< aux->nombre<<" - "<<aux->artista<<endl;
        }
        aux=aux->next;
    }
}
void ArbolTrie::destruir(TrieNode* nodo){
    if(nodo==nullptr) return;
    destruir(nodo->hijo);
    destruir(nodo->hermano);
    delete nodo;
}
void ArbolTrie::insertar(TrieNode*& nodo,int posicion,Node* cancion){
    if(nodo==nullptr){
        nodo=new TrieNode(cancion->nombre[posicion]);
    }
    if(nodo->letra==cancion->nombre[posicion]){
        if(posicion==cancion->nombre.length()-1){
            nodo->final=true;
            nodo->cancion=cancion;
            return;
        }
        insertar(nodo->hijo,posicion+1,cancion);
    }
    else{
        insertar(nodo->hermano,posicion+1,cancion);
    }
}
void ArbolTrie::crear(Lista& lista){
    Node* aux=lista.getStart();
    while(aux!=nullptr){
        insertar(raiz,0,aux);
        aux=aux->next;
    }
}
void ArbolTrie::eliminar(){
    destruir(raiz);
}