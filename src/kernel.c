#include "../headers/isr.h"
#include "../headers/idt.h"
#include "../headers/keyboard.h"
#include "../headers/bash.h"
#include "../headers/stdlib.h"
void kmain(){
  isr_install();
  clear();
  print("Welcome to Lean OS\ntype \"help\" to list all available commands\n");
  launchBash(0);
}
