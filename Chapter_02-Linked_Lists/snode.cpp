#include "snode.h"


namespace ctci {
    SNode::SNode(int data, SNode *next) {
        this->data = data;
        this-> next = next;
    }


    int SNode::getData() {
        return this->data;
    }


    void SNode::setData(int data) {
        this->data = data;
    }


    SNode *SNode::getNext() {
        return this->next;
    }


    void SNode::setNext(SNode *next) {
        this->next = next;
    }
}
