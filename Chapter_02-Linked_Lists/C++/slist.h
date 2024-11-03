#ifndef SLIST_H
#define SLIST_H

#include <iostream>

#include "snode.h"

using namespace std;


namespace ctci {
    class SList {
        private:
            SNode * _reverse(SNode *previous);
        protected:
            size_t size;
            SNode *head;
            SNode *tail;
        public:
            SList();
            SList(int data);
            SList(SNode *node);
            ~SList();

            void print(ostream &file);
            SList clone();
            void reverse();
            void add(int data);
            void add(SNode *node);
            bool remove(size_t index);
            size_t getSize();
            SNode *getHead();
            SNode *getNode(size_t index);
    };
}

#endif
