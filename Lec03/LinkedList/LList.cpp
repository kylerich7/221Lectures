//
// Created by KyleR on 2021-01-29.
//

#include "LList.h"
#include "DLList.h"
#include <iostream>
#include <cmath>
#include <string>
#include <vector>
#include "NodeLL.h"
#include "NodeDLL.h"

using namespace std;

LList::LList() {
    head = nullptr;
    tail = nullptr;
    list_size = 0;
}

NodeLL *LList::getHead() {
    return head;
}

NodeLL *LList::getTail() {
    return tail;
}

int LList::size(bool update) {
    if (!update) {
        return list_size;
    }
    int size = 0;
    NodeLL *temp = head;
    while (temp) {
        size++;
        temp = temp->next;
    }
    list_size = size;
    return list_size;
}

void LList::addNodeAsTail(NodeLL *new_node) {
    new_node->next = nullptr;

    if (head == nullptr) {
        head = new_node;
        tail = head;
        list_size = list_size + 1;
    } else {
        tail->next = new_node;
        tail = new_node;
        list_size = list_size + 1;
    }
}

void LList::addNodeAsHead(NodeLL *new_node) {
    new_node->next = nullptr;

    if (head == nullptr) {
        head = new_node;
        tail = head;
        list_size = list_size + 1;
    } else {
        new_node->next = head;
        head = new_node;
        list_size = list_size + 1;
    }
}

void LList::push(NodeLL *new_node) {
    addNodeAsHead(new_node);
}

NodeLL *LList::pop() {
    NodeLL *temp = head;
    head = head->next;
    list_size = list_size - 1;
    return temp;
}

NodeLL *LList::peek() {
    return head;
}

NodeLL *LList::get(int index) {
    if (index == 0) {
        return head;
    } else if (index == list_size - 1) {
        return tail;
    } else if (index < 0 || index >= list_size) {
        return nullptr;
    } else {
        NodeLL *temp = head;
        int i = 0;
        while (temp) {
            if (i == index) { return temp; }
            i++;
            temp = temp->next;
        }
    }
    return nullptr;
}

void LList::printList() {
    cout << "HEAD: ";
    NodeLL *temp = head;
    while (temp) {
        cout << temp->toString() << " -> ";
        temp = temp->next;
    }
    cout << "\b\b\b\b :TAIL" << endl;
}

void LList::reverseList(NodeLL *&currNode) {
    if (currNode == nullptr || currNode->next == nullptr) {
        return;
    }
    reverseList(currNode->next);
    currNode->next->next = currNode;
    currNode->next = nullptr;
}

void LList::printListReverseOdd(NodeLL *currNode) {
    if (currNode == nullptr || currNode->next == nullptr) return;
    printListReverseOdd(currNode->next->next);
    cout << currNode->next->data;
    cout << " <- X <- ";
}

void LList::printListReverse(NodeLL *currNode) {
    if (currNode == nullptr) {
        cout << " " << endl;
        return;
    }
    printListReverse(currNode->next);
    cout << currNode->data;
    cout << "<-";
}

void LList::removeNodeOn(NodeLL *target) {
    removeNodeOn(head, target);
}

void LList::removeNodeO1(NodeLL *target) {
    // the head and tail parts are not O1. Just ignore them. They are just to keep the head and tail variables accurate
    if (target == tail) {
        tail->next = new NodeLL(0); //sentinel
        tail = get(list_size - 2);
        target->data = target->next->data;
        target->next = target->next->next;
        delete target;
        tail->next = nullptr;
    } else if (target == head) {
        head = head->next;
    } else {//here onwards is the algo we learned in class
        target->data = target->next->data;
        target->next = target->next->next;
        delete target;
    }
    list_size--;
}

LList LList::buildList(int maxIndex) {
    LList ret;
    for (int data = 0; data < maxIndex; data++) {
        ret.addNodeAsTail(new NodeLL(data));
    }
    return ret;
}

void LList::removeNodeOn(NodeLL *&currNode, NodeLL *target) {
    if (target == tail) {
        delete tail;
        get(list_size - 2)->next = nullptr;
        tail = get(list_size - 2)->next;
    } else if (target == head) {
        NodeLL *newHead = head->next;
        delete head;
        head = newHead;
    } else if (currNode != target) {
        NodeLL *temp = currNode;
        while (temp->next != target) { temp = temp->next; }
        temp->next = target->next;
        target->next = nullptr;
    } else {
        currNode = currNode->next;
        target->
                next = nullptr;
    }
    list_size--;
}

void LList::reverseList() {
    NodeLL *headNode = head;
    NodeLL *tailNode = tail;
    reverseList(head);
    tail = headNode;
    head = tailNode;
}

void LList::printListReverse() {
    cout << "TAIL: ";
    printListReverse(head);
    cout << "\b\b\b\b :HEAD" << endl;
}

void LList::printListReverseOdd() {
    cout << "TAIL: ";
    printListReverseOdd(head);
    cout << "\b\b\b\b :HEAD" << endl;
}

LList::~LList() {
    while (head) {
        NodeLL *next = head->next;
        delete head;
        list_size = list_size - 1;
        head = next;
    }
}