
#include <cstring>
#include <iostream>
#include "library.h"
#include "Map.h"
#include <iostream>

Map::Map():size(0) {
    Map::Node<int>* new_Ds = new Node<int>();
    this->DS = new_Ds;
}

int Map::MapSize ()const{
    return this->size;
}


void* Map::returnDS (){
    return this->DS;
}


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




//the complexity is O(1)
void *Init(){
    Map new_map;
}


//the complexity is O(n)
StatusType Add(void *DS, int key, void* value, void** node){
    if (DS==NULL || node == NULL)
        throw dataStructure::INVALID_INPUT();
    StatusType status= Find(DS, key, & value);
    if (status == SUCCESS)
        throw dataStructure::FAILURE();
    if (status == ERROR_ALLOCATION)
        return ERROR_ALLOCATION;



    if(status== INVALID_INPUT)
        return INVALID_INPUT;

    Node* new_node = new Node;
    if (new_node==NULL)
        throw dataStructure::ERROR_ALLOCATION();

    new_node->nodesetNext((Node*)DS);
    new_node->nodesetprev(NULL);

    //(Node*)DS->nodes
    DS->prev=new_node;

    new_node->setKey(key);
    new_node->setValue(value);
    DS=new_node;

    DS->size=DS->size+1;
    return SUCCESS;
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