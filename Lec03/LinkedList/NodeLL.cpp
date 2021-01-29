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

NodeLL::NodeLL(int d, NodeLL *n) : data(d), next(n) {}

std::string NodeLL::toString() const {
    return to_string(data);
}
