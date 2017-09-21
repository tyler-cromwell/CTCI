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
        public:
            SList(SNode *head);
            int getSize();
            SNode *getHead();
            void sort();
    };
}

#endif
