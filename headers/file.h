#ifndef FILE_H
#define FILE_H
#include "types.h"
struct File{
  string name;
  string content;
};
struct FileLL{
  struct File *curr;
  struct File* next, prev;
};
struct Directory{
  struct Directory *parent;
  string name;
  struct FileLL *files;
};
struct DirectoryLL{
  struct Directory* curr;
  struct Directory* next, prev;
};
void ls();
void cd(string dirname);
void mkdir(string parent);

struct DirectoryLL *root;
struct DirectoryLL *head;
struct DirectoryLL *tail;
struct DirectoryLL *curr;
#endif
