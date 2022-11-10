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
    FolderCompress("test", "test1.hby");
    return 0;
}