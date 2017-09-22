#include <iostream>

#include "slist.h"


using namespace std;
using namespace ctci;


int main(int argc, char *argv[]) {
    SList slist(1);

    SNode *ptr = slist.getHead();

    do {
        cout << ptr->getData() << endl;
        ptr = ptr->getNext();
    }
    while (ptr != NULL);

    return EXIT_SUCCESS;
}
