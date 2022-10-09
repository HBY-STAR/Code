#include "gtest/gtest.h"
#include "KMP.h"
#include <string>
#include <fstream>

using namespace std;

class KMPTest : public ::testing::Test {

    struct KMPTestCase {
        string haystack;
        string needle;
        int first_occur;
    };

public:
    static vector<KMPTestCase> read_cases(bool found) {
        vector<KMPTestCase> found_cases;
        std::ifstream inputs_file;
        if (found) {
            inputs_file.open("../resources/kmp_found_input_output.txt");
        } else {
            inputs_file.open("../resources/kmp_not_found_input_output.txt");
        }
        int case_cnt;
        inputs_file >> case_cnt;
        for (int i = 0; i < case_cnt; i++) {
            KMPTestCase kCase;
            inputs_file >> kCase.haystack;
            inputs_file >> kCase.needle;
            inputs_file >> kCase.first_occur;
            found_cases.push_back(kCase);
        }
        return found_cases;
    }

};

TEST_F(KMPTest, testKMPNotFound) {
    auto cases = KMPTest::read_cases(false);

    for (const auto &kCase: cases) {
        //run test case one by one
        int first_occur_actual = KMP::strStr(kCase.haystack, kCase.needle);
        int first_occur_expected = kCase.first_occur;
        string case_info = "haystack= " + kCase.haystack + " needle= " + kCase.needle;
        ASSERT_EQ(first_occur_actual, first_occur_expected) << case_info;
    }
}

TEST_F(KMPTest, testKMPFound) {
    auto cases = KMPTest::read_cases(true);

    //record start time
    auto start = std::chrono::high_resolution_clock::now();

    for (const auto &kCase: cases) {
        //run test case one by one
        int first_occur_actual = KMP::strStr(kCase.haystack, kCase.needle);
        int first_occur_expected = kCase.first_occur;
        string case_info = "haystack= " + kCase.haystack + " needle= " + kCase.needle;
        ASSERT_EQ(first_occur_actual, first_occur_expected) << case_info;
    }

    //record end time
    auto elapsed = std::chrono::high_resolution_clock::now() - start;
    long long microseconds = std::chrono::duration_cast<std::chrono::milliseconds>(
            elapsed).count();

    // there is a extremely nasty test case 、-`д´-
    // I only give you 2 seconds, but brute force will take about half a minute (•͈⌔•͈⑅)
    // if you use brute force to search needle in haystack, you will fail here! ╰(○'◡'○)╮
    ASSERT_LE(microseconds, 2000) << "Your implementation is not efficient enough!"
                                  << endl
                                  << "Time Elapsed: "
                                  << microseconds
                                  << " ms";
}


