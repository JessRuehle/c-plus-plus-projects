// FILE: OrderedList.h

#ifndef PROJECT5_ORDEREDLIST_H
#define PROJECT5_ORDEREDLIST_H

#include <iostream>
#include "node.h"

using namespace std;

namespace jlr
{
template<class T>
    class OrderedList {

    public:

        // CONSTRUCTOR
        OrderedList<T>() {size = 0;}

        // DESTRUCTOR
        ~OrderedList() {delete [];}

        // PostCondition: The element is removed from the list
        void remove(node<T>*);

        // PostCondition: A new list containing the k largest elements is returned
        OrderedList kLargest(int);

        // PostCondition: Returns a copy of the kth item in the list
        node<T>& get(int);

        // PreCondition: > operator is defined
        // PostCondition: the node is inserted into the list
        void insert(node<T>);

        // PreCondition: > operator is defined
        // PostCondition: the two lists are added together
        OrderedList operator+ (OrderedList*);

        // PostCondition: list is copied
        OrderedList& operator= (OrderedList*);

        // PostCondition: list is printed to console
        friend ostream& operator<< (ostream &out, const OrderedList &list)
        {

            // start at the head node
            node<T> *current;
            *current = list->head;

            // print the data at each node out
            for (int i = 0; i < list->size; i++) out << current->getdata();

            return out;
        }


    private:
        node<T> *head; // first item in the list
        node<T> *tail; // last item in the list
        int size; // number of elements in the list
    };
}

#endif
