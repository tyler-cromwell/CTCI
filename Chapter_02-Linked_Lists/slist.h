#ifndef SLIST_H
#define SLIST_H

#include <iostream>

#include "snode.h"

using namespace std;


namespace ctci {
    class SList {
        protected:
            size_t size;
            SNode *head;
            SNode *tail;
        public:
            SList();
            SList(int data);
            ~SList();

            void print(ostream &file);
            void add(int data);
            bool remove(size_t index);
            size_t getSize();
            SNode *getHead();
            SNode *getNode(size_t index);
    };
}

#endif
