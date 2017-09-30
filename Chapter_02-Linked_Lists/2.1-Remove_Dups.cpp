/*************************************************
 * Solution to question 2.1 - Remove Duplicates
 *
 * Status: COMPLETE
*************************************************/

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
    slist.add(1);
    slist.add(5);

    // Remove duplicates
    slist.sort();
    slist.condense();
    print_slist(cout, slist);

    return EXIT_SUCCESS;
}
