//
// Created by KyleR on 2021-01-28.
//

#include <iostream>
#include <cmath>
#include <string>
#include <vector>
#include "NodeLL.h"
#include "NodeDLL.h"

using namespace std;

NodeDLL::NodeDLL(int d, NodeDLL *p, NodeDLL *n) : data(d), prev(p), next(n) {}

std::string NodeDLL::toString() {
    return to_string(data);
}
