/*************************************************
 * Solution to question 2.5 - Sum Lists
 *
 * Status: COMPLETE
*************************************************/

#include <iostream>

#include "../snode.h"
#include "../slist.h"

using namespace std;
using namespace ctci;


SList sum_lists(SList &list1, SList &list2) {
    size_t l1 = list1.getSize();
    size_t l2 = list1.getSize();
    size_t n = 0, sum = 0, carry = 0;

    if (l1 >= l2) {
        n = l1;
    } else {
        n = l2;
    }

    SList sumlist = SList();
    SNode *node1 = list1.getHead();
    SNode *node2 = list2.getHead();

    for (size_t i = 0; i < n; i++) {
        if (i < l1) {
            sum += node1->getData();
            node1 = node1->getNext();
        }
        if (i < l2) {
            sum += node2->getData();
            node2 = node2->getNext();
        }

        sum += carry;

        if (sum > 10) {
            sumlist.add(sum - 10);
            carry = 1;
        } else {
            sumlist.add(sum);
            carry = 0;
        }

        sum = 0;
    }

    return sumlist;
}


int main(void) {
    SList slist1(7);
    slist1.add(1);
    slist1.add(6);
    slist1.print(cout);
    cout << "==========" << endl;

    SList slist2(5);
    slist2.add(9);
    slist2.add(2);
    slist2.print(cout);
    cout << "==========" << endl;

    SList sum = sum_lists(slist1, slist2);
    sum.print(cout);
    return EXIT_SUCCESS;
}
