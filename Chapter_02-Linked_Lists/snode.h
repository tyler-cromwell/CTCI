/*************************************************
 * Part of solution to question 2.1 - Remove Dups
*************************************************/

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
            SNode *getNext();
            void setNext(SNode *next);
    };
}

#endif
