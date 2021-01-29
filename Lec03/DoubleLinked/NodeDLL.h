//
// Created by KyleR on 2021-01-28.
//

#ifndef LEC03_2_NODEDLL_H
#define LEC03_2_NODEDLL_H
#include <string>

class NodeDLL {
public:
    int data;
    NodeDLL *next;
    NodeDLL *prev;

    explicit NodeDLL(int d, NodeDLL *p = nullptr, NodeDLL *n = nullptr);
    std::string toString();


};


#endif //LEC03_2_NODEDLL_H
