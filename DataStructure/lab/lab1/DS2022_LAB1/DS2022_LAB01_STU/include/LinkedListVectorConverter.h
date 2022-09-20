//
// Created by huajuan on 2022/9/14.
//

#ifndef DS2022_LAB01_STU_LINKEDLISTVECTORCONVERTER_H
#define DS2022_LAB01_STU_LINKEDLISTVECTORCONVERTER_H

#include "Node.h"
#include <vector>

class LinkedListVectorConverter {
public:
    std::vector<int> toVector(Node *head);

    Node *toLinkedList(const std::vector<int> &v);
};


#endif //DS2022_LAB01_STU_LINKEDLISTVECTORCONVERTER_H
