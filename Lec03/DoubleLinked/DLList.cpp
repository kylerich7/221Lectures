//
// Created by KyleR on 2021-01-29.
//

#include "DLList.h"
#include <iostream>
#include <cmath>
#include <string>
#include <vector>
#include "NodeLL.h"
#include "NodeDLL.h"
using namespace std;

DLList::DLList() {
    head = nullptr;
    tail = nullptr;
    list_size = 0;
}

NodeDLL *DLList::getHead() {
    return head;
}

NodeDLL *DLList::getTail() {
    return tail;
}

int DLList::size(bool update) {
    if (!update) {
        return list_size;
    }
    int size = 0;
    NodeDLL *temp = head;
    while (temp) {
        size++;
        temp = temp->next;
    }
    list_size = size;
    return list_size;
}

void DLList::addNodeAsTail(NodeDLL *new_node) {
    new_node->next = nullptr;
    new_node->prev = nullptr;

    if (head == NULL) {
        head = new_node;
        tail = head;
        list_size = list_size + 1;
    } else {
        tail->next = new_node;
        new_node->prev = tail;
        tail = new_node;
        list_size = list_size + 1;
    }
}

void DLList::addNodeAsHead(NodeDLL *new_node) {
    new_node->next = nullptr;
    new_node->prev = nullptr;

    if (head == NULL) {
        head = new_node;
        tail = head;
        list_size = list_size + 1;
    } else {
        head->prev = new_node;
        new_node->next = head;
        head = new_node;
        list_size = list_size + 1;
    }
}

void DLList::push(NodeDLL *new_node) {
    addNodeAsHead(new_node);
}

NodeDLL *DLList::pop() {
    NodeDLL *temp = head;
    head = head->next;
    head->prev = nullptr;
    list_size = list_size - 1;
    return temp;
}

NodeDLL *DLList::peek() {
    return head;
}

NodeDLL *DLList::get(int index) {
    if (index == 0) {
        return head;
    } else if (index == list_size - 1) {
        return tail;
    } else if (index < 0 || index >= list_size) {
        return nullptr;
    }
    if (index < list_size / 2) {
        NodeDLL *temp = head;
        int i = 0;
        while (temp) {
            if (i == index) { return temp; }
            i++;
            temp = temp->next;
        }
    } else {
        NodeDLL *temp = tail;
        int i = list_size - 1;
        while (temp) {
            if (i == index) { return temp; }
            i--;
            temp = temp->prev;
        }
    }
    return nullptr;
}

void DLList::printList() {
    cout << "HEAD: ";
    NodeDLL *temp = head;
    while (temp) {
        cout << temp->toString() << " <-> ";
        temp = temp->next;
    }
    cout << "\b\b\b\b :TAIL" << endl;
}

void DLList::printListBackwards() {
    cout << "TAIL: ";
    NodeDLL *temp = tail;
    while (temp) {
        cout << temp->toString() << " <-> ";
        temp = temp->prev;
    }
    cout << "\b\b\b\b :HEAD" << endl;
}

void DLList::reverseDLList() {
    NodeDLL *headNode = head;
    NodeDLL *tailNode = tail;
    reverseDLList(head);
    tail = headNode;
    head = tailNode;
}

void DLList::reverseDLList(NodeDLL* currNode) {
    if (currNode == nullptr) return;
    reverseDLList(currNode->next);
    NodeDLL *temp = currNode->next;
    currNode->next = currNode->prev;
    currNode->prev = temp;
    if (currNode->next == nullptr) return;
}

void DLList::printNode(NodeDLL *node) {
    cout << "prev: ";
    if (node->prev != nullptr) {
        cout << node->prev->data;
    } else {
        cout << "N";
    }
    cout << " curr: ";
    cout << node->data;
    cout << " next: ";
    if (node->next != nullptr) {
        cout << node->next->data << endl;
    } else {
        cout << "N" << endl;
    }
}

DLList DLList::buildList(int maxIndex) {
    DLList ret;
    for (int data = 0; data < maxIndex; data++) {
        ret.addNodeAsTail(new NodeDLL(data));
    }
    return ret;
}

DLList::~DLList() {
    while (head) {
        NodeDLL *next = head->next;
        delete head;
        list_size = list_size - 1;
        head = next;
    }
}


