#pragma once
#include "Lista.h"
using namespace std;

struct AvlNode
{
    string artista;
    Lista canciones;
    int altura;
    AvlNode* izquierdo;
    AvlNode* derecho;
    AvlNode(string artista);
};
