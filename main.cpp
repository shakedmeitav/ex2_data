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
    int n;
   StatusType status = Add(new_DS ,1, (void *) 2, &p);
   StatusType status2 = Add(new_DS, 3, (void *) 4, &p);
   // StatusType status4 = Add(new_DS, 5, (void *) 6, &p);
  //  StatusType status3=Find(new_DS, 9, &s);
   StatusType status5=Delete(new_DS,1);
    StatusType status7= Size(new_DS, &n);

    return 0;
}
