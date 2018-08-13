#ifndef SLIST_H
#define SLIST_H

#include "snode.h"


namespace ctci {
    class SList {
        protected:
            size_t size;
            SNode *head;
            SNode *tail;
        public:
            SList(int data);
            ~SList();
            
            size_t getSize();
            SNode *getHead();
            
            void add(int data);
            bool remove(size_t index);
    };
}

#endif
