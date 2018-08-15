/*************************************************
 * Solution to question 2.1 - Remove Duplicates
 *
 * Status: COMPLETE
*************************************************/

#include <iostream>

#include "../snode.h"
#include "../slist.h"

using namespace std;
using namespace ctci;


class SListSub : public SList {
    private:
        // Should only be called in sort()
        void _sort(SNode **headptr);
        void _split(SNode *source, SNode **front, SNode **back);
        SNode * _merge(SNode *a, SNode *b);

    public:
        SListSub(int data);
        ~SListSub();

        void condense();
        void sort();
};


SListSub::SListSub(int data) : SList(data) {}

SListSub::~SListSub() {}


void SListSub::condense() {
	SNode *current = this->head;
	SNode *next = this->head->getNext();

	while (next != NULL) {
		if (next->getData() == current->getData()) {
			// Relink and delete next
			current->setNext(next->getNext());
			this->size--;
			delete next;
		} else {
			// Move on
			current = next;
		}

		next = current->getNext();
	}
}


void SListSub::sort() {
	this->_sort(&this->head);
}


// Do not call outside of SListSub::sort
void SListSub::_sort(SNode **headptr) {
	SNode *head = *headptr;
	SNode *a, *b;

	// Length 0 or 1 (base case)
	if ((head == NULL) || (head->getNext() == NULL)) {
		return;
	}

	// Split head into 'a' and 'b' sublists
	this->_split(head, &a, &b);

	// Recursively sort the sublists
	this->_sort(&a);
	this->_sort(&b);

	// answer = merge the two sorted lists together
	*headptr = this->_merge(a, b);
}


// Do not call outside of SListSub::sort
void SListSub::_split(SNode *source, SNode **front, SNode **back) {
	SNode *fast, *slow;

	// Length 0 or 1
	if (source == NULL || source->getNext() == NULL) {
		*front = source;
		*back = NULL;
	}
	else {
		slow = source;
		fast = source->getNext();

		while (fast != NULL) {
			fast = fast->getNext();

			if (fast != NULL) {
				slow = slow->getNext();
				fast = fast->getNext();
			}
		}

		// 'slow' is before the midpoint in the list, so split at that point
		*front = source;
		*back = slow->getNext();
		slow->setNext(NULL);
	}
}


// Do not call outside of SListSub::sort
SNode *SListSub::_merge(SNode *a, SNode *b) {
	SNode *result = NULL;

	/* Base cases */
	if (a == NULL) {
		return b;
	} else if (b == NULL) {
		return a;
	}

	if (a->getData() <= b->getData()) {
		result = a;
		result->setNext(this->_merge(a->getNext(), b));
	} else {
		result = b;
		result->setNext(this->_merge(a, b->getNext()));
	}

	return result;
}


int main(void) {
    // Initialize a Singly Linked List
    SListSub slist(7);
    slist.add(4);
    slist.add(2);
    slist.add(4);
    slist.add(1);
    slist.add(5);

    // Remove duplicates
    slist.sort();
    slist.condense();
    slist.print(cout);
    return EXIT_SUCCESS;
}
