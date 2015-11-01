#include <iostream>
#include "DynamicList.h"

using namespace std;

int main()
{
    DynamicList<int>* myIntList = new DynamicList<int>(2);
    int a = 12;
    //even though I have created my list with size 2, I am inserting 12 4 times.
    //Hence my list is increasing dynamically
    myIntList->add(a);
    myIntList->add(a);
    myIntList->add(a);
    myIntList->add(a);
    myIntList->print();
    delete myIntList;
    return 0;
}
