#include "gtest/gtest.h"
#include "SpecialMatrixOps.h"
#include <vector>
#include <fstream>

using namespace std;

class SpecialMatrixOpsTest : public ::testing::Test {
public:
    static vector<vector<int>> read_inputs() {
        vector<vector<int>> inputs;
        std::ifstream inputs_file("../resources/restore_symmetric_matrix_input.txt");
        int case_cnt;
        inputs_file >> case_cnt;
        for (int i = 0; i < case_cnt; i++) {
            vector<int> v;
            int matrix_sz;
            inputs_file >> matrix_sz;
            int len = matrix_sz * (matrix_sz + 1) / 2;
            for (int j = 0; j < len; j++) {
                int num;
                inputs_file >> num;
                v.push_back(num);
            }
            inputs.push_back(v);
        }
        return inputs;
    }

    static vector<vector<vector<int>>> read_outputs() {
        vector<vector<vector<int>>> outputs;
        ifstream outputs_file("../resources/restore_symmetric_matrix_output.txt");
        int case_cnt;
        outputs_file >> case_cnt;
        for (int _ = 0; _ < case_cnt; _++) {
            int matrix_sz;
            outputs_file >> matrix_sz;
            vector<vector<int>> matrix(matrix_sz, vector<int>(matrix_sz, 0));
            for (int i = 0; i < matrix_sz; i++) {
                for (int j = 0; j < matrix_sz; ++j) {
                    int num;
                    outputs_file >> num;
                    matrix[i][j] = num;
                }
            }
            outputs.push_back(matrix);
        }
        return outputs;
    }
};

TEST_F(SpecialMatrixOpsTest, testRecoverSymmetricMatrix) {
    auto inputs = SpecialMatrixOpsTest::read_inputs();
    auto outputs = SpecialMatrixOpsTest::read_outputs();

    ASSERT_GT(inputs.size(), 0) << "Read test cases failed";
    ASSERT_EQ(inputs.size(), outputs.size()) << "Read test cases failed";

    int case_cnt = outputs.size();
    for (int i = 0; i < case_cnt; i++) {
        auto compressed_matrix = inputs[i];
        auto original_matrix = outputs[i];
        auto original_matrix_recovered = SpecialMatrixOps::recoverSymmetricMatrix(compressed_matrix);
        ASSERT_EQ(original_matrix, original_matrix_recovered);
    }
}

