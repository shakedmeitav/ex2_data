
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
Node<T> Node<T>:: nodeGetNext(){
    return this->next;
}

template <class T>
Node<T> Node<T>:: nodeGetPrev(){
    return this->prev;
}

template <class T>
void* Node<T>::nodesetNext(Node node){
    node.next=node;
}


template <class T>
void* Node<T>::nodesetprev(Node node){
    node.prev=node;
}

template <class T>
void Node<T>:: setKey(T key){
    this->key=key;
}


template <class T>
void Node<T>::setValue( void *value) {
    this->value=value;
}

template <class T>
T  Node<T>::getKey(){
    return this->key;
}


template <class T>
void* Node<T>::getValue(){
    return this->value;
}