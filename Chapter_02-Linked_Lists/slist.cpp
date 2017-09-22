/*************************************************
 * Part of solution to question 2.1 - Remove Dups
*************************************************/

#include <cstdlib>

#include "slist.h"


namespace ctci {
    SList::SList(int data) {
        this->head = new SNode(data, NULL);
        this->size = 1;
    }


    SList::~SList() {
        SNode *current = this->head;

        for (int i = 0; i < this->size; i++) {
            SNode *next = current->getNext();
            delete current;
            current = next;
        }
    }


    int SList::getSize() {
        return this->size;
    }


    SNode *SList::getHead() {
        return this->head;
    }


    void SList::sort() {
        /* Will use Merge Sort */
    }
}
