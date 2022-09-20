//
// Created by huajuan on 2022/9/15.
//

#ifndef DS2022_LAB01_TA_PROBLEM2_H
#define DS2022_LAB01_TA_PROBLEM2_H

#include <string>
#include "PolynomialTerm.h"

class Problem2 {
public:
    PolynomialTerm *addTerm(PolynomialTerm *head, int coefficient, int exponent);

    PolynomialTerm *add(PolynomialTerm *head1, PolynomialTerm *head2);

    std::string toString(PolynomialTerm *head);

    void free(PolynomialTerm *head);
};

#endif //DS2022_LAB01_TA_PROBLEM2_H
