#include <iostream>
#include <fstream>
#include <filesystem>
#include <wchar.h>
#include <string>
#include <cstdlib>
#include "HuffmanNode.h"
#include "HuffmanTree.h"
#include "Functions.h"

namespace fs = std::filesystem;
using namespace std;

int main(int argc, char **argv)
{
    string opt;

    switch (argc)
    {
    case 2:
    {
        opt = argv[1];
        if (opt == "--h")
        {
            HelpPage();
        }
    }
    break;
    case 3:
    {
        opt = argv[1];
        fs::path zip_path = argv[2];
        if (opt == "unzip_hby")
        {
            fs::path folder_path = zip_path.root_directory();
            Uncompress(zip_path, folder_path);
        }
        else if (opt == "prev_hby")
        {
            string preview_graph = "";
            zipPreview(zip_path, preview_graph);
            cout << preview_graph;
        }
        else
        {
            cout << "Invalid inputs, please check your command." << endl;
            exit(1);
        }
    }
    break;
    case 4:
    {
        opt = argv[1];
        fs::path zip_path = argv[2];
        fs::path file_path = argv[3];
        if (opt == "zip_hby")
        {
            fs::directory_entry file_entry(file_path);
            if (file_entry.is_directory())
            {
                FolderCompress(file_path, zip_path);
            }
            else
            {
                FileCompress(file_path, zip_path);
            }
        }
        else
        {
            cout << "Invalid inputs, please check your command." << endl;
            exit(1);
        }
    }
    break;
    default:
    {
        cout << "Invalid inputs, please check your command." << endl;
        exit(1);
    }
    break;
    }

    // FileCompress(file_path, zip_path1);
    // FileUncompress(zip_path1, folder_path1);
    // FolderCompress(folder_path, zip_path);
    // FolderUncompress(zip_path, folder_path2);
    return 0;
}