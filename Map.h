#ifndef UNTITLED_MAP_H
#define UNTITLED_MAP_H

class dictionary{
    void* DS;
    int * size;
};


template <class T>
class Node {
    T key;
    void* value;
    Node* next;
    Node* prev;
};



#endif //UNTITLED_MAP_H
