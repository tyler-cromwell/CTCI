#include <iostream>

#include "slist.h"


using namespace std;
using namespace ctci;


int main(int argc, char *argv[]) {
    SList slist(1);
    slist.add(7);
    slist.add(3);
    slist.add(7);

    SNode *ptr = slist.getHead();

    do {
        cout << ptr->getData() << endl;
        ptr = ptr->getNext();
    }
    while (ptr != NULL);

    cout << "==============" << endl;
    slist.remove(3);
    slist.sort();

    ptr = slist.getHead();

    do {
        cout << ptr->getData() << endl;
        ptr = ptr->getNext();
    }
    while (ptr != NULL);
    return EXIT_SUCCESS;
}
