#include <iostream>
#include "OrderedList.h"

using namespace std;
int main() {

    jlr::OrderedList<int> *list_ptr;
    jlr::OrderedList<int> list;
    list_ptr = &list;

    jlr::node<int> *x;
    jlr::node<int> y = 6;
    x = &y;

    list_ptr->insert(x);
//    list->insert(y);
//    list->insert(z);

    cout << "hi" << endl;


    return 0;
}
