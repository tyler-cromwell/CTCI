/*************************************************
 * Solution to question 2.7 - Intersection
 *
 * Status: COMPLETE
*************************************************/

#include <iostream>

#include "../snode.h"
#include "../slist.h"

using namespace std;
using namespace ctci;


SNode * intersection(SList &list1, SList &list2) {
    SNode *n1 = list1.getHead();
    SNode *n2 = list2.getHead();
    size_t l1 = list1.getSize();
    size_t l2 = list2.getSize();
    size_t iters = 0;
    size_t diff = 0;

    if (l1 >= l2) {
        diff = l1 - l2;
        iters = l1 - diff;

        for (size_t i = 0; i < diff; i++) {
            n1 = n1->getNext();
        }
    } else {
        diff = l2 - l1;
        iters = l2 - diff;

        for (size_t i = 0; i < diff; i++) {
            n2 = n2->getNext();
        }
    }

    for (size_t i = 0; i < iters; i++) {
        if (n1 == n2) {
            return n1;
        } else {
            n1 = n1->getNext();
            n2 = n2->getNext();
        }
    }

    return NULL;
}


int main(void) {
    SList list1(7);
    list1.add(4);
    list1.add(9);
    list1.add(2);
    list1.add(5);  // 4
    list1.add(1);
    list1.add(3);
    list1.add(6);
    list1.print(cout);
    cout << "==========" << endl;

    SList list2(8);
    list2.add(2);
    list2.add(list1.getNode(4));
    list2.print(cout);
    cout << "==========" << endl;

    SNode *common = intersection(list1, list2);

    if (common) {
        printf("Intersection: 0x%x -> %d\n", common, common->getData());
    } else {
        cout << "No Intersection" << endl;
    }
    return EXIT_SUCCESS;
}
