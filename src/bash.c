#include "../headers/bash.h"
void launchBash(int n){
  string ch = (string)malloc(200);
  do{
    print("leanos> ");
    ch = readString();
    if(strcmp(ch,"help")){
      launchHelp();
    }else if(strcmp(ch,"exit")){
      print("\nBye!\n");
    }else if(strcmp(ch,"clear")){
      clear();
    }else if(strcmp(ch,"about")){
      launchAbout();
    }else if(strcmp(ch,"echo")){
      echo();
    }else{
      print("\nbash: ");
      print(ch);
      print(": command not found\n");
    }
  }while(!strcmp(ch,"exit"));
}
void echo(){
	print("\n");
	string str = readString();
	print("\n");
	print(str);
	print("\n");
}
void launchAbout(){
  uint16 i=0;
  print("\n");
  for(i;i<80;++i){
    print("=");
  }
  i=0;
  for(i;i<36;++i){
    print(" ");
  }
  print("Lean OS\n");
  print("= Version  : 0.1\n");
  print("= Codename : Hades\n");
  print("= Creator  : Anthony V\n");
  print("= Lean OS is an simple operating system written in C\n");
  i=0;
  for(i;i<80;++i){
    print("=");
  }
  print("\n");
}
void launchHelp(){
  print("\nhelp    : Show all available commands");
  print("\nexit    : Close current bash");
  print("\nclear   : Clear screen");
  print("\nabout   : About Lean OS\n");
}
