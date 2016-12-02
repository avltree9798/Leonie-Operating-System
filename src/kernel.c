#include "../headers/isr.h"
#include "../headers/idt.h"
#include "../headers/keyboard.h"
#include "../headers/bash.h"
#include "../headers/stdlib.h"
kmain(){
  isr_install();
  clear();
  println("Welcome to Leonie OS\ntype \"help\" to list all available commands");
  launchBash(0);
}
