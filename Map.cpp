
#include <cstring>
#include <iostream>

#include "Map.h"


Map::Map(void* DS): DS(DS),size(0){
}


int Map::MapSize ()const{
    return this->size;
}


#include <iostream>


template <class T>
Node<T> ::Node(T key,  void* value): key(key),value(value),next(NULL),prev(NULL){

}
template <class T>
Node<T> Node<T>:: nodeGetNext(Node node){
    return node.next;
}

template <class T>
Node<T> Node<T>:: nodeGetPrev(Node node){
    return node.prev;
}


template <class T>
void Node<T>:: setKey(Node node,T key){
    node.key=key;
}


template <class T>
void Node<T>::setValue(Node node, void *value) {
    node.value=value;
}

template <class T>
T  Node<T>::getKey(Node node){
    return node.key;
}


template <class T>
void* Node<T>::getValue(Node node){
    return node.value;
}