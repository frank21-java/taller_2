#pragma once
#include "Lista.h"
using namespace std;

struct AvlNode
{
    Node* cancion;
    int altura;
    AvlNode* izquierdo;
    AvlNode* derecho;
    AvlNode(Node* cancion);
};
