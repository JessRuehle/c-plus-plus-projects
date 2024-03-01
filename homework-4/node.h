// FILE: node.h
#ifndef PROJECT5_NODE_H
#define PROJECT5_NODE_H

#include <cstddef>

namespace jlr {

    template<class T>
    class node {
    public:
        typedef T itemtype;

        node(itemtype item = itemtype(), node *p = NULL) {
            this->item = item;
            link = p;
        }

        void setdata(itemtype item) {
            this->item = item;
        }

        void setlink(node *p) {
            link = p;
        }

        itemtype getdata() const {
            return item;
        }

        const node *getlink() const {
            return link;
        }

        node *getlink() {
            return link;
        }

    private:
        itemtype item;
        node *link;
    };
}

#endif //PROJECT5_NODE_H
