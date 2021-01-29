//
// Created by KyleR on 2021-01-29.
//

#ifndef SRC_DLLIST_H
#define SRC_DLLIST_H
#include "NodeDLL.h"

class DLList {
private:
    NodeDLL* head;
    NodeDLL* tail;
    int list_size;
public:
    DLList();
    NodeDLL* getHead();
    NodeDLL* getTail();
    int size(bool update=false);
    void addNodeAsTail(NodeDLL* new_node);
    void addNodeAsHead(NodeDLL* new_node);
    void push(NodeDLL* new_node);
    NodeDLL* pop();
    NodeDLL* peek();
    NodeDLL* get(int index);
    void reverseDLList();
    void printList();
    void printListBackwards();
    static void printNode(NodeDLL *node);
    static DLList buildList(int maxIndex);
    ~DLList();
private:
    void reverseDLList(NodeDLL* currNode);
};


#endif //SRC_DLLIST_H
