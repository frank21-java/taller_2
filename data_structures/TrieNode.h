#pragma once
#include "Node.h"

struct TrieNode
{
    char letra;
    bool final;
    Node* cancion;
    TrieNode* hijo;
    TrieNode* hermano;
    TrieNode(char c);
};
