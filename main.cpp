#include <iostream>
#include "Map.h"
#include "library1.h"
#include "Exception.h"



int main() {

    void* new_DS = Init();
    void* p;
    void* s;

    //int n;

    StatusType status = Add(new_DS ,1, (void *) 2, &p);
    StatusType status2 = Add(new_DS, 3, (void *) 4, &p);
    // StatusType status4 = Add(new_DS, 5, (void *) 6, &p);
     StatusType status3=Find(new_DS, 1, &s);
    //StatusType status5=Delete(new_DS,1);
    //StatusType status7= Size(new_DS, &n);
    std::cout << status << status2<<status3  << "shaked" << std::endl;
    Quit(&new_DS);
    return 0;
}