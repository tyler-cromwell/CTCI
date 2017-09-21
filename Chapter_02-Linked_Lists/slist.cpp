/*************************************************
 * Part of solution to question 2.1 - Remove Dups
*************************************************/

#include "slist.h"


namespace ctci {
    SList::SList(SNode *head) {
        this->head = head;
        this->size = 1;
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
