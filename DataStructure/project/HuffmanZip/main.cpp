#include <iostream>
#include <fstream>
#include "HuffmanNode.h"
#include "HuffmanTree.h"
#include "Functions.h"

using namespace std;

int main()
{
    FileCompress("test.txt", "test.hby");
    FileUncompress("test.hby");
    return 0;
}