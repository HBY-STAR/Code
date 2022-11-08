#ifndef FUNCTIONS_HPP
#define FUNCTIONS_HPP

#include "HuffmanNode.h"
#include "HuffmanTree.h"

priority_queue<HuffmanNode, vector<HuffmanNode>, greater<HuffmanNode>> GetChFreq(const string &file_name);
void FileCompress(const string &file_name, const string &zip_name);
void FileUncompress();
void FolderCompress();
void FolderUncompress();

#endif