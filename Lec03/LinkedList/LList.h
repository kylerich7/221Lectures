//
// Created by KyleR on 2021-01-29.
//

#ifndef SRC_LLIST_H
#define SRC_LLIST_H
#include "NodeLL.h"

class LList {
private:
    NodeLL* head;
    NodeLL* tail;
    int list_size;
public:
    LList();
    NodeLL* getHead();
    NodeLL* getTail();
    NodeLL* pop();
    NodeLL* peek();
    NodeLL* get(int index);
    int size(bool update=false);
    void addNodeAsTail(NodeLL* new_node);
    void addNodeAsHead(NodeLL* new_node);
    void push(NodeLL* new_node);
    void reverseList();
    void printListReverse();
    void printListReverseOdd();
    void removeNodeOn(NodeLL *target);
    void removeNodeO1(NodeLL *target);
    void printList();
    static LList buildList(int maxIndex);

    ~LList();

private:
    void removeNodeOn(NodeLL *&currNode, NodeLL *target);
    void reverseList(NodeLL *&currNode);
    void printListReverse(NodeLL *currNode);
    void printListReverseOdd(NodeLL *currNode);
};


#endif //SRC_LLIST_H
