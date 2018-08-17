#include <cstdlib>
#include <iostream>

#include "slist.h"


namespace ctci {
    SList::SList() {
        this->head = NULL;
        this->tail = this->head;
        this->size = 0;
    }


    SList::SList(int data) {
        this->head = new SNode(data, NULL);
        this->tail = this->head;
        this->size = 1;
    }


    SList::~SList() {
        SNode *current = this->head;

        for (size_t i = 0; i < this->size; i++) {
            SNode *next = current->getNext();
            delete current;
            current = next;
        }
    }


    void SList::print(ostream &file) {
        SNode *node = this->head;

        do {
            file << node->getData() << endl;
            node = node->getNext();
        }
        while (node != NULL);
    }


    SList SList::clone() {
        SList cloned = SList();
        SNode *node = this->head;

        for (size_t i = 0; i < this->size; i++) {
            cloned.add(node->getData());
            node = node->getNext();
        }

        return cloned;
    }


    void SList::reverse() {
        this->tail = _reverse(this->head);
        this->tail->setNext(NULL);
    }


    SNode * SList::_reverse(SNode *node) {
        SNode *next = node->getNext();
        SNode *ret = NULL;

        if (next) {
            ret = _reverse(next);
        } else {
            this->head = node;
            return this->head;
        }

        ret->setNext(node);
        return ret->getNext();
    }


    void SList::add(int data) {
        if (this->head == NULL) {
            this->head = new SNode(data, NULL);
            this->tail = this->head;
        } else {
            this->tail->setNext(new SNode(data, NULL));
            this->tail = this->tail->getNext();
        }
        this->size++;
    }


    bool SList::remove(size_t index) {
        if (index >= this->size) {
            return false;
        }

        SNode *target = this->head;

        switch (index) {
            case 0: {
                this->head = target->getNext();
                break;
            }
            case 1: {
                target = this->head->getNext();
                this->head->setNext(target->getNext());
                break;
            }
            default: {
                SNode *current = this->head;

                for (size_t i = 0; i < index-1; i++) {
                    current = current->getNext();
                }

                target = current->getNext();
                current->setNext(target->getNext());
            }
        }

        delete target;
        this->size--;
        return true;
    }


    size_t SList::getSize() {
        return this->size;
    }


    SNode *SList::getHead() {
        return this->head;
    }


    SNode *SList::getNode(size_t index) {
        SNode *node = this->head;

        for (size_t i = 0; i < index; i++) {
            node = node->getNext();
        }

        return node;
    }
}
