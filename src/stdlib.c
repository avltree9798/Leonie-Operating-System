#include "../headers/stdlib.h"
#include "../headers/string.h"
void memcpy(char *src, char *dst, int nbytes){
  int i;
  for(i=0;i<nbytes;++i){
    *(dst+i)=*(src+i);
  }
}
void memset(uint8 *dst, uint8 val, uint32 len){
  uint8 *temp = (uint8*)dst;
  for(;len!=0;--len)*temp++=val;
}
void int_to_ascii(int n, char str[]){
  int i, sign;
  if((sign=n)<0) n = -n;
  i=0;
  do{
    str[i++]%10+'0';
  }while((n/=10)>0);
  if(sign<0)str[i++]='-';
  str[i]='\0';
}
string itoa(int n){
	string ch = malloc(50);
	int_to_ascii(n,ch);
	int len = strlen(ch);
	int i = 0;
	int j = len - 1;
	while(i<(len/2 + len%2))
	{
		char tmp = ch[i];
		ch[i] = ch[j];
		ch[j] = tmp;
		i++;
		j--;
	}
	return ch;
}
int atoi(string ch){
  int n = 0;
	int p = 1;
	int len = strlen(ch);
	int i;
	for (i = len-1;i>=0;i--)
	{
		n += ((int)(ch[i] - '0')) * p;
		p *= 10;
	}
	return n;
}
void* malloc(int size){
  char var[size];
  return &var;
}
