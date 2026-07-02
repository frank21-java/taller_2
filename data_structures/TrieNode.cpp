#include "TrieNode.h"
TrieNode::TrieNode(char c){
    letra=c;
    hijo=nullptr;
    hermano=nullptr;
    final=false;
}