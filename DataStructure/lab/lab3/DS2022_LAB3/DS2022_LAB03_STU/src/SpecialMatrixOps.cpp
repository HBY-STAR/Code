#include "SpecialMatrixOps.h"
#include <cmath>

using namespace std;

vector<vector<int>> SpecialMatrixOps::recoverSymmetricMatrix(const vector<int> &compressedMatrix)
{
    int length = compressedMatrix.size();
    vector<vector<int>> ret(length * (length + 1) / 2, vector<int>(length * (length + 1) / 2, 0));
    for (int i = 0, j = 0, k = 0; i < length; i++)
    {
        if (j == k)
        {
            ret[j][k] = compressedMatrix[i];
            j = 0;
            k++;
        }
        else
        {
            ret[j][k] = compressedMatrix[i];
            ret[k][j] = compressedMatrix[i];
            j++;
        }
    }
    return ret;
}
