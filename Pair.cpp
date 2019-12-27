#include <iostream>
#include "Pair.h"

Pair::Pair(int node, char edge){
    this -> node = node;
    this -> edge = edge;
}

int Pair::getNode(){
    return this -> node;
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



