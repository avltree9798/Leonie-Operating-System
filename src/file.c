#include "../headers/file.h"

void init(){
  int size=0;
  sizeoftype(root,size);
  root = (struct DirectoryLL*)malloc(size);
  head = tail = curr = root;
}

void ls(){
    
}
