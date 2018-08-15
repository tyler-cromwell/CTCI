#ifndef SNODE_H
#define SNODE_H

namespace ctci {
    class SNode {
        private:
            int data;
            SNode *next;
        public:
            SNode(int data, SNode *next);
            int getData();
            void setData(int data);
            SNode *getNext();
            void setNext(SNode *next);
    };
}

#endif
