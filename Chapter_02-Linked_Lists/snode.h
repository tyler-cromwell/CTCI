#ifndef SNODE_H
#define SNODE_H

#include <cstdlib>

namespace ctci {
    class SNode {
        private:
            SNode *next;
            size_t refcount;
            int data;
        public:
            SNode(int data);
            SNode(int data, SNode *next);

            void incref();
            void decref();
            size_t getref();

            int getData();
            SNode *getNext();
            void setData(int data);
            void setNext(SNode *next);
    };
}

#endif
