#ifndef SLIST_H
#define SLIST_H

#include "snode.h"


namespace ctci {
    class SList {
        protected:
            int size;
            SNode *head;
            SNode *tail;
        public:
            SList(int data);
            ~SList();
            
            int getSize();
            SNode *getHead();
            
            void add(int data);
            bool remove(int index);
    };
}

#endif
