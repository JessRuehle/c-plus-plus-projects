// FILE: OrderedList.cpp

#include "OrderedList.h"

namespace jlr
{

    template<typename T>
    void OrderedList<T>::remove(node<T> *element)
    {
        // set the current pointer node to point to the head
        node<T> *previous = NULL;
        node<T> *current = head;

        // if the element is the head, set the head pointer variable to now point to
        // the second item in the list and decrement the size member variable
        if (head->getdata() == element->getdata())
        {
            head = head->getlink();
            size--;
            return;
        }

        // iterate through the list
        for (int i = 0; i < size - 1; current = current->getlink(), i++)
        {
            // if the current node is equal to the element parameter, set the previous
            // node's link to the current node's next link, decrement the size member
            // variable, and break out of the function
            if (current->getdata() == element->getdata())
            {
                previous->setlink(current->getlink());
                size--;
                return;
            }
        }

        // move the previous pointer to the current pointer's node, so that when the
        // current one moves forward, something is still pointing to the previous one.
        previous->getlink(current);
    }

    template<typename T>
    OrderedList<T> OrderedList<T>::kLargest(int k)
    {
        OrderedList<T> new_list; // new list of elements
        node<T> *current = head; // point a current node to a null pointer
        int x = 0;

        // iterate through the list until x is less than k. at that point, the
        // remaining indices are the k largest and can be added to the new list
        for (int i = 0; i < k; current = current->getlink(), i++)
        {
            x = size - i;
            if (x < k) new_list.insert(current);
        }

        return new_list;
    }

    template<typename T>
    node<T>& OrderedList<T>::get(int n)
    {
        // set a new node to point to the head of the list
        node<T> *current = &head;

        // iterate through the list until the nth element of the list is found
        for (int i = 0; i <= n; current = current->getlink(), i++)
        {
            if (i == n)
            { // return a pointer to the nth element
                return current;
            }
        }
        // if the node is not found, return a node pointed to a null pointer
        return (new node<T> = NULL);
    }

    template<typename T>
    void OrderedList<T>::insert(node<T> new_element)
    {
        node<T> *current = NULL; // pointer to the current node
        node<T> *previous = head; // pointer to the previous node

        // if the ordered list is empty,
        if (size == 0)
        {
            head = &new_element; // setting head to the address of new_element
            size = 1; // setting the size to one
            return;
        }

        // if the head is greater than the new element, set the new_element to point to
        // the head node and set the head pointer variable to point to the new_elemenet
        if (head->getdata() > new_element.getdata())
        {
            new_element.setlink(head);
            head->setlink(new_element);
            return;
        }

        // start at the head, and while the current node is not pointing to a NULL
        // pointer, point the current node to the next one
        for (current = head; current != NULL; current = current->getLink())
        {
            // if the current node is greater than the new one, insert the new node
            // into that position in the list
            if ((current->getData()) > (new_element->getData()))
            {
                new_element->setLink(current);
                previous->setlink(new_element);
                return;
            }

            // move ahead the pointer to the previous node last
            previous = previous->getlink();
        }

        size++; // update size of list
    }

    template<typename T>
    OrderedList<T>& OrderedList<T>::operator= (OrderedList<T> *list)
    {
        node<T> *this_current = head; // this list's current node
        node<T> *list_current = list->head; // parameter list's current node
        head->setlink(list->head); // point this list's head to parameter list's head

        // while not at the end of the provided list,
        while (list_current != NULL)
        {
            // set this list's current node link to the link of the parameter list's link
            // then advance the parameter list's link forward
            this_current->setlink(list_current->getlink());
            list_current = list_current->getlink();
        }

        return *this;
    }

    // INCOMPELTE
//    template<typename T>
//    OrderedList<T> OrderedList<T>::operator+ (OrderedList<T> *list)
//    {
//        OrderedList<T> new_list;
//        node<T> *current = head;
//        for ()
//    }

}