#include <iostream>
#include "Pair.h"

Pair::Pair(int node, char edge, int n_son){
    this -> node = node;
    this -> edge = edge;
    this -> n_son = n_son;
}

int Pair::getNode(){
    return this -> node;
}

int Pair::getN_son(){
    return this -> n_son;
}

char Pair:: getEdge(){
    return this -> edge;
}

void Pair:: setNode(int node)
{
    this -> node = node;
}

void Pair:: setEdge(char edge)
{
    this -> edge = edge;
} 
