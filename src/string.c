#include "../headers/string.h"
uint16 strlen(string ch){
  int i = 0;
  while(ch[i++]);
  return i-1;
}
uint8 strcmp(string ch1, string ch2){
  uint8 size = strlen(ch1);
  if(size!=strlen(ch2)) return 0;
  else{
    uint8 i = 0;
    for(i;i<size;++i){
      if(ch1[i]!=ch2[i])return 0;
    }
  }
  return 1;
}
