//
// Created by huajuan on 2022/9/15.
//

#ifndef DS2022_LAB01_TA_POLYNOMIALTERM_H
#define DS2022_LAB01_TA_POLYNOMIALTERM_H

class PolynomialTerm {
public:
    int coefficient{};
    int exponent{};
    PolynomialTerm *next{};

    PolynomialTerm(int coefficient, int exponent);
};

#endif //DS2022_LAB01_TA_POLYNOMIALTERM_H
