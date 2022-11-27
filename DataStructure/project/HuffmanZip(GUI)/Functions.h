#ifndef FUNCTIONS_HPP
#define FUNCTIONS_HPP

#include <filesystem>
#include <graphics.h>
#include <wchar.h>
#include <ege/sys_edit.h>
#include "HuffmanNode.h"
#include "HuffmanTree.h"

namespace fs = std::filesystem;

//获取文件中字符的频率，将其存储在一个优先队列中并返回
priority_queue<HuffmanNode, vector<HuffmanNode>, greater<HuffmanNode>>
GetChFreq(const fs::path &file_path, long *file_size);

//文件压缩操作
void FileCompress(const fs::path &file_path, const fs::path &zip_path);

//文件解压缩操作
void FileUncompress(const fs::path &zip_path, const fs::path &folder_path);

//文件夹压缩操作内部的遍历目录递归函数
void inFolderCompressTravelDir(const fs::path &folder_path, ofstream &output);

//文件夹压缩操作内部的对单个文件压缩的操作
void inFolderCompressFile(const fs::path &folder_path, ofstream &output);

//文件夹压缩操作的内部递归函数
void inFolderCompressDir(const fs::path &folder_path, ofstream &output);

//文件夹压缩操作
void FolderCompress(const fs::path &folder_path, const fs::path &zip_path);

//
void inFolderUncompressTravelDir(ifstream &input, const fs::path &folder_path);

//
void inFolderUncompressFile(ifstream &input, const fs::path &file_path);

//
void inFolderUncompressDir(ifstream &input, const fs::path &folder_path);

//
void FolderUncompress(const fs::path &zip_path, const fs::path &folder_path);

//
void Uncompress(const fs::path &zip_path, const fs::path &folder_path);

//
void zipPreview(const fs::path &zip_path, string &preview_graph);

//
void initEditBox(sys_edit *editBox, int x, int y, int width, int height);

//
void loadImages(PIMAGE *images, int num);

//
void releaseImages(PIMAGE *images, int num);

//
void drawMainInterface(PIMAGE *images);

//
void drawFileCompressInterface(PIMAGE *images);

//
void drawFolderCompressInterface(PIMAGE *images);

//
void drawUncompressInterface(PIMAGE *images);

//
void drawPreviewInterface(PIMAGE *images);

#endif