
#include <cstring>
#include <iostream>
#include "library.h"
#include "Map.h"


Map::Map(void* DS): DS(DS),size(0){
}


int Map::MapSize ()const{
    return this->size;
}


#include <iostream>


template <class T>
Map::Node<T> ::Node(T key,  void* value): key(key),value(value),next(NULL),prev(NULL){

}
template <class T>
Map::Node<T>* Map::Node<T>:: nodeGetNext(){
    return this->next;
}

template <class T>
Map::Node<T>* Map::Node<T>:: nodeGetPrev(){
    return this->prev;
}

template <class T>
void* Map::Node<T>::nodesetNext(Node* node){
    node->next=node;
}


template <class T>
void* Map::Node<T>::nodesetprev(Node* node){
    node->prev=node;
}

template <class T>
void Map::Node<T>:: setKey(T key){
    this->key=key;
}


template <class T>
void Map::Node<T>::setValue( void *value) {
    this->value=value;
}

template <class T>
T  Map::Node<T>::getKey(){
    return this->key;
}


template <class T>
void* Map::Node<T>::getValue(){
    return this->value;
}

StatusType Find(void *DS, int key, void* value) {
    if (DS == NULL || value == NULL)
        throw INVALID_INPUT;
    Map::Node<int>* itr=( Map::Node<int>*)DS;
    while (itr != NULL) {
        if (itr->getKey() == key) {
            value = itr->getValue();
            throw SUCCESS;
        }
        itr = itr->nodeGetNext();
    }
    throw FAILURE;             // if we here the system didnt fint the right key
}


/*StatusType Delete(void *DS, int key){
    if(DS==NULL)
        throw INVALID_INPUT;
    Node<int>* itr=( Node<int>*)DS;
    if(itr->getKey()==key)         //first node


}


*/