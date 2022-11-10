#ifndef FUNCTIONS_HPP
#define FUNCTIONS_HPP

#include <filesystem>
#include "HuffmanNode.h"
#include "HuffmanTree.h"

namespace fs = std::filesystem;

priority_queue<HuffmanNode, vector<HuffmanNode>, greater<HuffmanNode>>
GetChFreq(const fs::path &file_path, long *file_size);
void FileCompress(const fs::path&file_path, const fs::path &zip_path);
void FileUncompress(const fs::path &zip_path,const fs::path&folder_path);
void FolderCompress(const fs::path &folder_path, const fs::path &zip_path);
void FolderUncompress();

#endif