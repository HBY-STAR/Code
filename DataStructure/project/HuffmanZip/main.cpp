#include <iostream>
#include <fstream>
#include "HuffmanNode.h"
#include "HuffmanTree.h"
#include "Functions.h"

using namespace std;

int main()
{
    FileCompress("miku.jfif", "miku.hby");
    FileUncompress("miku.hby");
    return 0;
}