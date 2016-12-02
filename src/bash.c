#include "../headers/bash.h"
void launchBash(int n){
  string ch = (string)malloc(200);
  int counter = 0;
  do{
    print("LeOS(");
    print(itoa(n));
    print(")> ");
    ch = readString();
    if(strcmp(ch,"help")){
      launchHelp();
    }else if(strcmp(ch,"exit")){
      println("\nBye!");
    }else if(strcmp(ch,"clear")){
      clear();
    }else if(strcmp(ch,"about")){
      launchAbout();
    }
  }while(!strcmp(ch,"exit"));
}
void launchAbout(){
  uint16 i=0;
  for(i;i<80;++i){
    printch("=");
  }
  println("");
  i=0;
  for(i;i<36;++i){
    printch(" ");
  }
  println("Leonie OS");
  println("= Version  : 0.1");
  println("= Codename : Hades");
  println("= Creator  : Anthony V");
  i=0;
  for(i;i<80;++i){
    printch("=");
  }
  println("");
}
void launchHelp(){
  print("\nhelp    : Show all available commands");
  print("\nexit    : Close current bash");
  print("\nclear   : Clear screen");
  println("\nabout   : About Leonie OS");
}
