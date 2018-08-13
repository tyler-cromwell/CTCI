/*************************************************
 * Solution to question 2.2 - Return Kth to Last
 *
 * This solution assumes that the list size
 * is known.
 *
 * Status: COMPLETE
*************************************************/

#include <iostream>

#include "../snode.h"
#include "../slist.h"

using namespace std;
using namespace ctci;


class SListSub : public SList {
    public:
        SListSub(int data);
        ~SListSub();

        SNode * kth_to_last(size_t k);
};


SListSub::SListSub(int data) : SList(data) {}

SListSub::~SListSub() {}


SNode * SListSub::kth_to_last(size_t k) {
    SNode *target = this->head;

    for (size_t i = 0; i < (this->size - k); i++) {
        target = target->getNext();
    }

    return target;
}


void print_slist(ostream &file, SListSub &slist) {
    SNode *ptr = slist.getHead();

    do {
        file << ptr->getData() << endl;
        ptr = ptr->getNext();
    }
    while (ptr != NULL);
}


int main(void) {
    SListSub slist(7);
    slist.add(4);
    slist.add(2);   // Target
    slist.add(1);   // 2nd to last
    slist.add(5);

    size_t k = 3;
    SNode *node = slist.kth_to_last(k);
    cout << "Retrieving k = " << k << " from last node" << endl;
    cout << node->getData() << endl;

    return EXIT_SUCCESS;
}
