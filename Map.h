#ifndef UNTITLED_MAP_H
#define UNTITLED_MAP_H

class Map{
    void* DS;
    int size;

public:

    /**
 * constractur for the Map
 * @param name -
 * @param weapon -
  * the size will be zero when we will initial
 */
    Map(void* DS);

    ~Map();

    Map (const Map &map);

    Map &operator=(const Map &map);






};


template <class T>
class Node {
    T key;
    void* value;
    Node* next;
    Node* prev;
};



#endif //UNTITLED_MAP_H
