/*************************************************
 * Part of solution to question 2.1 - Remove Dups
*************************************************/

#ifndef SLIST_H
#define SLIST_H

#include "snode.h"


namespace ctci {
    class SList {
        private:
            int size;
            SNode *head;
            SNode *tail;
        public:
            SList(int data);
            ~SList();
            int getSize();
            SNode *getHead();
            void add(int data);
            void remove(int index);
            void sort();
    };
}

#endif
