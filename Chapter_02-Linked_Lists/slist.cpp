/*************************************************
 * Part of solution to question 2.1 - Remove Dups
*************************************************/

#include <cstdlib>

#include "slist.h"


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
        this->_sort(&this->head);
    }


    void SList::_sort(SNode **headptr) {
        SNode *head = *headptr;
        SNode *a, *b;

        // Length 0 or 1 (base case)
        if ((head == NULL) || (head->getNext() == NULL)) {
            return;
        }

        // Split head into 'a' and 'b' sublists
        this->_split(head, &a, &b);

        // Recursively sort the sublists
        this->_sort(&a);
        this->_sort(&b);

        // answer = merge the two sorted lists together
        *headptr = this->_merge(a, b);
    }


    void SList::_split(SNode *source, SNode **front, SNode **back) {
        SNode *fast, *slow;

        // Length 0 or 1
        if (source == NULL || source->getNext() == NULL) {
            *front = source;
            *back = NULL;
        }
        else {
            slow = source;
            fast = source->getNext();

            while (fast != NULL) {
                fast = fast->getNext();

                if (fast != NULL) {
                    slow = slow->getNext();
                    fast = fast->getNext();
                }
            }

            // 'slow' is before the midpoint in the list, so split at that point
            *front = source;
            *back = slow->getNext();
            slow->setNext(NULL);
        }
    }


    SNode *SList::_merge(SNode *a, SNode *b) {
        SNode *result = NULL;

        /* Base cases */
        if (a == NULL) {
            return b;
        } else if (b == NULL) {
            return a;
        }

        if (a->getData() <= b->getData()) {
            result = a;
            result->setNext(this->_merge(a->getNext(), b));
        } else {
            result = b;
            result->setNext(this->_merge(a, b->getNext()));
        }

        return result;
    }
}
