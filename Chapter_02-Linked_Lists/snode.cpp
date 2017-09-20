/*************************************************
 * Part of solution to question 2.1 - Remove Dups
*************************************************/

#include "snode.h"


namespace ctci {
    SNode::SNode(int data, SNode *next) {
        this->data = data;
        this-> next = next;
    }


    int SNode::getData() {
        return this->data;
    }


    SNode *SNode::getNext() {
        return this->next;
    }


    void SNode::setNext(SNode *next) {
        this->next = next;
    }
}
