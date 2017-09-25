/*************************************************
 * Part of solution to question 2.1 - Remove Dups
*************************************************/
#include <iostream>
#include <cstdlib>

#include "slist.h"
using namespace std;

namespace ctci {
    SList::SList(int data) {
        this->head = new SNode(data, NULL);
        this->tail = this->head;
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


    void SList::add(int data) {
        this->tail->setNext(new SNode(data, NULL));
        this->tail = this->tail->getNext();
        this->size++;
    }


    bool SList::remove(int index) {
        if (index < 0 || index >= this->size) {
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

                for (int i = 0; i < index-1; i++) {
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


    void SList::sort() {
        /* Will use Merge Sort */
    }
}