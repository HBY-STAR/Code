//
// Created by huajuan on 2022/9/15.
//
#include "PolynomialTerm.h"

PolynomialTerm::PolynomialTerm(int coefficient, int exponent) {
    this->coefficient = coefficient;
    this->exponent = exponent;
    this->next = nullptr;
}