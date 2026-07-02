#include "AvlNode.h"
AvlNode::AvlNode(string artista){
    this->artista=artista;
    izquierdo=nullptr;
    derecho=nullptr;
    altura=1;
}