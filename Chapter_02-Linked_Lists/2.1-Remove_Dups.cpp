#include <iostream>

#include "slist.h"

using namespace std;
using namespace ctci;


void print_slist(ostream &file, SList &slist) {
    SNode *ptr = slist.getHead();

    do {
        file << ptr->getData() << endl;
        ptr = ptr->getNext();
    }
    while (ptr != NULL);
}


int main(int argc, char *argv[]) {
    // Initialize a Singly Linked List
    SList slist(7);
    slist.add(4);
    slist.add(2);
    slist.add(4);
    slist.add(5);
    slist.add(5);

    // Sort nodes
    slist.sort();
    print_slist(cout, slist);

    return EXIT_SUCCESS;
}
