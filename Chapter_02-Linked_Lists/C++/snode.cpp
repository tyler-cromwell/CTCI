#include "snode.h"


namespace ctci {
    SNode::SNode(int data) {
        this->data = data;
        this->next = NULL;
        this->refcount = 0;
    }


    SNode::SNode(int data, SNode *next) {
        this->data = data;
        this->next = next;
        this->refcount = 0;
    }


    void SNode::incref() {
        this->refcount++;
    }


    void SNode::decref() {
        this->refcount--;
    }


    size_t SNode::getref() {
        return this->refcount;
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
