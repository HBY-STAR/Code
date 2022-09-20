//
// Created by huajuan on 2022/9/15.
//

#include "Problem2.h"
#include "gtest/gtest.h"

class Problem2Test : public ::testing::Test {
protected:
    Problem2 problem2;
};


TEST_F(Problem2Test, normalCase) {
    PolynomialTerm *head1 = nullptr;
    PolynomialTerm *head2 = nullptr;
    head1 = problem2.addTerm(head1, 55, 2);
    head1 = problem2.addTerm(head1, 55, 2);
    head1 = problem2.addTerm(head1, 56, 3);

    head2 = problem2.addTerm(head2, 88, 2);
    head2 = problem2.addTerm(head2, 89, 3);
    head2 = problem2.addTerm(head2, 90, 4);
    head2 = problem2.addTerm(head2, 100, 8);

    auto *head3 = problem2.add(head1, head2);

    ASSERT_EQ("100x^8+90x^4+145x^3+198x^2", problem2.toString(head3));

    auto *head4 = problem2.add(head2, head1);

    ASSERT_EQ("100x^8+90x^4+145x^3+198x^2", problem2.toString(head4));
}

TEST_F(Problem2Test, coefficientZeroCase) {
    PolynomialTerm *head1 = nullptr;
    PolynomialTerm *head2 = nullptr;
    head1 = problem2.addTerm(head1, 1, 1);
    head1 = problem2.addTerm(head1, 2, 2);
    head1 = problem2.addTerm(head1, 3, 3);

    head2 = problem2.addTerm(head2, 1, 1);
    head2 = problem2.addTerm(head2, 2, 2);
    head2 = problem2.addTerm(head2, -3, 3);

    auto * head3=problem2.add(head2,head1);

    ASSERT_EQ("4x^2+2x",problem2.toString(head3));
}

TEST_F(Problem2Test,coefficientOneCase){
    PolynomialTerm *head1 = nullptr;
    PolynomialTerm *head2 = nullptr;
    head1 = problem2.addTerm(head1, 47, 28);
    head1 = problem2.addTerm(head1, 98, 36);
    head1 = problem2.addTerm(head1, 13, 45);

    head2 = problem2.addTerm(head2, 89, 26);
    head2 = problem2.addTerm(head2, 23, 78);
    head2 = problem2.addTerm(head2, -46, 28);

    auto * head3=problem2.add(head2,head1);

    ASSERT_EQ("23x^78+13x^45+98x^36+x^28+89x^26",problem2.toString(head3));
}

TEST_F(Problem2Test,coefficientNegativeOneCase){
    PolynomialTerm *head1 = nullptr;
    PolynomialTerm *head2 = nullptr;
    head1 = problem2.addTerm(head1, -47, 28);
    head1 = problem2.addTerm(head1, 98, 36);
    head1 = problem2.addTerm(head1, 13, 45);

    head2 = problem2.addTerm(head2, 89, 26);
    head2 = problem2.addTerm(head2, 23, 78);
    head2 = problem2.addTerm(head2, 46, 28);

    auto * head3=problem2.add(head2,head1);

    ASSERT_EQ("23x^78+13x^45+98x^36-x^28+89x^26",problem2.toString(head3));
}

TEST_F(Problem2Test,exponentZeroCase){
    PolynomialTerm *head1 = nullptr;
    PolynomialTerm *head2 = nullptr;
    head1 = problem2.addTerm(head1, -47, 28);
    head1 = problem2.addTerm(head1, 98, 36);
    head1 = problem2.addTerm(head1, 13, 45);
    head1 = problem2.addTerm(head1, 100, 0);

    head2 = problem2.addTerm(head2, 89, 26);
    head2 = problem2.addTerm(head2, 23, 78);
    head2 = problem2.addTerm(head2, 46, 28);
    head1 = problem2.addTerm(head1, 200, -1);

    auto * head3=problem2.add(head2,head1);

    ASSERT_EQ("23x^78+13x^45+98x^36-x^28+89x^26+100+200x^-1",problem2.toString(head3));
}

TEST_F(Problem2Test,exponentOneCase){
    PolynomialTerm *head1 = nullptr;
    PolynomialTerm *head2 = nullptr;
    head1 = problem2.addTerm(head1, -47, 1);
    head1 = problem2.addTerm(head1, 98, 36);
    head1 = problem2.addTerm(head1, 13, 45);

    head2 = problem2.addTerm(head2, 89, 26);
    head2 = problem2.addTerm(head2, 23, 78);
    head2 = problem2.addTerm(head2, 46, 28);

    auto * head3=problem2.add(head2,head1);

    ASSERT_EQ("23x^78+13x^45+98x^36+46x^28+89x^26-47x",problem2.toString(head3));
}