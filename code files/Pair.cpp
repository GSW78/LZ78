#include <iostream>
#include "Pair.h"

//constructor
Pair::Pair(int node, char edge, int n_son){
    this -> node = node;
    this -> edge = edge;
    this -> n_son = n_son;
}
//function to get node
int Pair::getNode(){
    return this -> node;
}
//function to get node son
int Pair::getN_son(){
    return this -> n_son;
}
//function to get edge
char Pair:: getEdge(){
    return this -> edge;
}
//function to set node
void Pair:: setNode(int node)
{
    this -> node = node;
}
//function to set edge
void Pair:: setEdge(char edge)
{
    this -> edge = edge;
} 