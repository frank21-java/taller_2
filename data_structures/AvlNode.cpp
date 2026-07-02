#include "AvlNode.h"
AvlNode::AvlNode(Node* cancion){
    this->cancion=cancion;
    izquierdo=nullptr;
    derecho=nullptr;
    altura=1;
}