#include <iostream>
#include "Map.h"
#include "library.h"
#include "Exception.h"



int main() {

//Map map;
   void* new_DS = Init();
   void* p;
   void* s;
   //Map::Node<int>* node1 = new Map::Node<int>(1,2);

   StatusType status = Add(new_DS ,1, (void *) 2, &p);
   StatusType status2 = Add(new_DS, 3, (void *) 4, &p);
   StatusType status3=Find(new_DS, 3, &s);

    return 0;
}
