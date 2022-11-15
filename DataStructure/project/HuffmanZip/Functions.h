#ifndef FUNCTIONS_HPP
#define FUNCTIONS_HPP

#include <filesystem>
#include <graphics.h>
#include <wchar.h>
#include <ege/sys_edit.h>
#include "HuffmanNode.h"
#include "HuffmanTree.h"

namespace fs = std::filesystem;

priority_queue<HuffmanNode, vector<HuffmanNode>, greater<HuffmanNode>>
GetChFreq(const fs::path &file_path, long *file_size);
void FileCompress(const fs::path &file_path, const fs::path &zip_path);
void FileUncompress(const fs::path &zip_path, const fs::path &folder_path);
void inFolderCompressTravelDir(const fs::path &folder_path, ofstream &output);
void inFolderCompressFile(const fs::path &folder_path, ofstream &output);
void inFolderCompressDir(const fs::path &folder_path, ofstream &output);
void FolderCompress(const fs::path &folder_path, const fs::path &zip_path);
void inFolderUncompressTravelDir(ifstream &input, const fs::path &folder_path);
void inFolderUncompressFile(ifstream &input, const fs::path &file_path);
void inFolderUncompressDir(ifstream &input, const fs::path &folder_path);
void FolderUncompress(const fs::path &zip_path, const fs::path &folder_path);
void Uncompress(const fs::path &zip_path, const fs::path &folder_path);
void zipPreview(const fs::path &zip_path);
void initEditBox(sys_edit *editBox, int x, int y, int width, int height);
void loadImages(PIMAGE *images, int num);
void releaseImages(PIMAGE *images, int num);
void drawMainInterface(PIMAGE *images);
void drawFileCompressInterface(PIMAGE *images);
void drawFolderCompressInterface(PIMAGE *images);
void drawUncompressInterface(PIMAGE *images);
void drawPreviewInterface(PIMAGE *images);

#endif