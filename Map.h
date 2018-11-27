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

    ~Map()= default;

    Map (const Map &map)= default;

    Map &operator=(const Map &map)= default;


    /**
     * the function returns the number of elements in the map
     * @param DS - the first pointer to the list of the map
     * @return the size of the map
     * the complexity is O(1)
     */
    int MapSize() const;

template <class T>
class Node {
    T key;
    void* value;
    Node* next;
    Node* prev;

public:
/**
 * constructor of Node  O(1)
 * @tparam T
 * @param key
 * @param value
 */
    Node(T key,  void* value);
/**
 * destructor 0(1)
 */
    ~Node()= default;
/**
 * copy constructor 0(1)
 * @param node
 */
    Node (const Node &node)= default;
/**
 * operator = ,0(1)
 * @param node
 * @return
 */
    Node &operator=(const Node &node)= default;

/**
 * return the next node of the input node
 * @param node
 * @return
 */
    Node* nodeGetNext();
    /**
     * return the prev node of the input node
     * @param node
     * @return
     */
    Node* nodeGetPrev();
    /**
     * set the next node to be the input node
     * @param node
     * @return
     */
    void* nodesetNext(Node* node);
    /**
     * set the prev node to be the input node
     * @param node
     * @return
     */
    void* nodesetprev(Node* node);

    /**
     * get a node and a key and set the key of the node to be the key of the
     * input node
     * @param node
     * @param key
     */
    void setKey(T key);
    /**
     * get a node and a value and set the value of the node to be the value
     * of the input node
     * @param node
     * @param value
     */
    void setValue(void* value);
    /**
     * get a node and return his key
     * @return
     */
    T getKey();
    /**
     * get a node and return his value
     * @return
     */
    void* getValue();

};
    };


#endif //UNTITLED_MAP_H
