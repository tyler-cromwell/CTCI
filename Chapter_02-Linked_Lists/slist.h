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

            // Should only be called in sort()
            void _sort(SNode **headptr);
            void _split(SNode *source, SNode *front, SNode *back);
            SNode *_merge(SNode *a, SNode *b);
        public:
            SList(int data);
            ~SList();
            
            int getSize();
            SNode *getHead();
            
            void add(int data);
            bool remove(int index);
            void sort();
    };
}

#endif
