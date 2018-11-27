#include "library.h"
#include "Map.h"
#include <stdexcept>
#include <iostream>
#include "Exception.h"


void *Init(){
    Map* DS= new Map;
    if (DS==NULL){

    }
    return (void*)DS;
}