/*************************************************
 * Solution to question 2.6 - Palindrome
 *
 * Status: COMPLETE
*************************************************/

#include <iostream>

#include "../snode.h"
#include "../slist.h"

using namespace std;
using namespace ctci;


bool palindrome(SList &list1) {
    SList list2 = list1.clone();
    list2.reverse();

    SNode *node1 = list1.getHead();
    SNode *node2 = list2.getHead();

    for (size_t i = 0; i < list1.getSize(); i++) {
        if (node1->getData() != node2->getData()) {
            return false;
        }

        node1 = node1->getNext();
        node2 = node2->getNext();
    }

    return true;
}


int main(void) {
    SList slist1(2);
    slist1.add(0);
    slist1.add(3);
    slist1.print(cout);
    cout << "Palindrome: " << ((palindrome(slist1)) ? "true" : "false") << endl;
    cout << "==========" << endl;
    SList slist2(5);
    slist2.add(8);
    slist2.add(5);
    slist2.print(cout);
    cout << "Palindrome: " << ((palindrome(slist2)) ? "true" : "false") << endl;
    return EXIT_SUCCESS;
}
