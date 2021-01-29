#include <iostream>
#include <cmath>
#include <string>
#include <vector>
#include "NodeDLL.h"
#include "LList.h"
#include "DLList.h"


using namespace std;

int main() {

    // **(data of each node == index when using DLL/LL::buildList(int i))**


    //creates single linked lists and reverses it
    LList linkedList = LList::buildList(10);
    linkedList.printList();
    linkedList.reverseList();
    linkedList.printList();

    cout << " " << endl;

    //creates single linked lists and prints odds in reverse
    LList linkedList2 = LList::buildList(10);
    linkedList2.printList();
    linkedList2.printListReverseOdd();

    cout << " " << endl;

    //creates single linked lists, deletes nodes using both methods (O of n, and O of 1) and prints the list
    LList linkedList3 = LList::buildList(10);
    linkedList3.printList();
    linkedList3.removeNodeO1((linkedList3.getTail()));
    linkedList3.printList();
    linkedList3.removeNodeO1((linkedList3.getTail()));
    linkedList3.printList();
    linkedList3.removeNodeO1((linkedList3.getHead()));
    linkedList3.printList();
    linkedList3.removeNodeOn((linkedList3.getTail()));
    linkedList3.printList();
    linkedList3.removeNodeOn((linkedList3.getHead()));
    linkedList3.printList();

    cout << " " << endl;

    //creates double linked list and reverses it
    DLList doubleLinkedList = DLList::buildList(10);
    doubleLinkedList.printList();
    doubleLinkedList.reverseDLList();
    doubleLinkedList.printList();

    cout << " " << endl;

    //creates double linked list and reverses it
    DLList doubleLinkedList2 = DLList::buildList(10);
    doubleLinkedList2.printList();
    doubleLinkedList2.printListBackwards();
    return 0;
}










