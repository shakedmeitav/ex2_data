
#include <cstring>
#include <iostream>
#include "library.h"
#include "Map.h"
#include <iostream>

Map::Map():size(0) {
    this->head =NULL;
}

int Map::MapSize ()const{
    return this->size;
}


void* Map::returnHead (){
    return this->head;
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


//the complexity is O(1)
void Map::Add(void *DS, int key, void* value, void** node){
    if (DS==NULL || node == NULL)
        throw dataStructure::INVALID_INPUT();
    int copy_key=key;
    void* copy_value=value;
    Node<int>* new_node = new Node<int>(copy_key,copy_value);
    if (new_node==NULL)
        throw dataStructure::ALLOCATION_ERROR();
    new_node->nodesetNext(this->head);
    new_node->nodesetprev(NULL);
    this->head->nodesetprev(new_node);
    new_node->setKey(key);
    new_node->setValue(value);
    this->head=new_node;
    this->size++;
    throw dataStructure::SUCCESS();
}


void Map::DeleteByPointer(void *DS, void* p){
        if(DS==NULL || p==NULL)
            throw dataStructure::INVALID_INPUT();
        Node<int>* convert_p=(Node<int>*)p;
        if(convert_p->nodeGetPrev()==NULL) { //p is the first Node
            this->head=convert_p->nodeGetNext();
            (convert_p->nodeGetNext())->nodesetprev(NULL);
            delete convert_p;
            size--;
            throw dataStructure::SUCCESS();
        }
        if(convert_p->nodeGetNext()==NULL){                  //p is the last Node
            convert_p->nodeGetPrev()->nodesetNext(NULL);
            delete convert_p;
            size--;
            throw SUCCESS;
        }
        convert_p->nodeGetPrev()->nodesetNext(convert_p->nodeGetNext());
        convert_p->nodeGetNext()->nodesetprev(convert_p->nodeGetPrev());
        delete convert_p;
        size--;
        throw SUCCESS;
}



void Map::Find(void *DS, int key, void** value) {
    if (DS == NULL || *value == NULL)
        throw INVALID_INPUT;
    Node<int>* itr=(Node<int>*)this->head;
    while (itr != NULL) {
        if (itr->getKey() == key) {
            *value = itr->getValue();
            throw SUCCESS;
        }
        itr = itr->nodeGetNext();
    }
    throw FAILURE;             // if we here the system didnt fint the right key
}



void  Map::Delete(void *DS, int key) {
    if (DS == NULL)
        throw INVALID_INPUT;
    Node<int> *itr = (Node<int>*) DS;
    void *value;
    if (itr->getKey() == key) {         //first node
        this->head = itr->nodeGetNext();
        this->head->nodesetprev(NULL);
        delete itr;
        size--;
        throw SUCCESS;
    } else              //finish eith the case of the first node
        itr = itr->nodeGetNext();
    while (itr->nodeGetNext() != NULL){
        if (itr->getKey() == key) {
            if (itr->nodeGetNext() != NULL) {  //not the last node
                itr->nodeGetNext()->nodesetprev(itr->nodeGetPrev());
                itr->nodeGetPrev()->nodesetNext(itr->nodeGetNext());
            } else                            //we are in the last node
                itr->nodeGetPrev()->nodesetNext(NULL);
            delete itr;
            size--;
            throw SUCCESS;
        }
        itr = itr->nodeGetNext();
    }
    throw FAILURE;
}



void Map::Size(void *DS, int *n){
    if(this->head==NULL || n==NULL)
        throw INVALID_INPUT;

    *n=this->size;
    throw SUCCESS;
}

void Map::Quit(void **DS){
    Node<int>* save_itr=this->head;
    Node<int>* itr=this->head;
    while (itr!=NULL) {
        save_itr=itr->nodeGetNext();
        delete itr;
        Node<int>* itr=save_itr;
    }
//delete this->head;
//delete this->size;
    delete DS;
    DS=NULL;
}


