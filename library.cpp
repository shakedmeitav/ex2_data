#include "library.h"
#include "Map.h"
#include <stdexcept>
#include <iostream>
#include "Exception.h"

/**
 * the cimplexity is O(1)
 * @return
 */
void *Init(){
    Map* DS= new Map;
    if (DS==NULL){
        return NULL;
    }
    return (void*)DS;
}



/**
 * the cimplexity is O(1)
 * @return
 */
StatusType Add(void *DS, int key, void* value, void** node){
    if(DS==NULL)
        return INVALID_INPUT;
    try {
    ((Map *) DS)->Add(key, value, node);
}
catch (dataStructure::INVALID_INPUT& e) {
    return INVALID_INPUT;
}
catch (dataStructure::ALLOCATION_ERROR& e) {
    return ALLOCATION_ERROR;
}
catch (dataStructure::SUCCESS& e) {
    return SUCCESS;
}
return SUCCESS;

}

