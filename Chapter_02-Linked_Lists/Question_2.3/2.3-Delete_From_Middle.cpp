/*************************************************
 * Solution to question 2.3 - Delete From Middle
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

        void delete_from_middle(SNode *node);
};


SListSub::SListSub(int data) : SList(data) {}

SListSub::~SListSub() {}


void SListSub::delete_from_middle(SNode *node) {
    SNode *current = node;
    SNode *previous = NULL;

    while (current->getNext() != NULL) {
        SNode *next = current->getNext();
        current->setData(next->getData());
        previous = current;
        current = next;
    }

    delete previous->getNext();
    this->size--;
    previous->setNext(NULL);
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
    slist.add(4);   // Target
    slist.add(2);
    slist.add(1);
    slist.add(5);
    size_t index = 1;

    print_slist(cout, slist);
    cout << "==========" << endl;
    cout << "Deleting node at index " << index << endl;
    slist.delete_from_middle(slist.getNode(index));
    cout << "==========" << endl;
    print_slist(cout, slist);
    return EXIT_SUCCESS;
}
