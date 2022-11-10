#include <iostream>
#include <fstream>
#include <filesystem>
#include "HuffmanNode.h"
#include "HuffmanTree.h"
#include "Functions.h"

namespace fs = std::filesystem;
using namespace std;

int main()
{
    fs::path folder_path = "C:\\Users\\21714\\Desktop\\Code\\DataStructure\\project\\HuffmanZip\\test1";
    fs::path zip_path = "C:\\Users\\21714\\Desktop\\Code\\DataStructure\\project\\HuffmanZip\\test1.hby";
    fs::path file_path = "C:\\Users\\21714\\Desktop\\Code\\DataStructure\\project\\HuffmanZip\\miku.jfif";
    fs::path folder_path1 = "C:\\Users\\21714\\Desktop\\Code\\DataStructure\\project\\HuffmanZip";
    fs::path zip_path1 = "C:\\Users\\21714\\Desktop\\Code\\DataStructure\\project\\HuffmanZip\\miku.hby";
    // FileCompress(file_path, zip_path1);
    // FileUncompress(zip_path1, folder_path1);
    FolderCompress(folder_path, zip_path);
    return 0;
}