#ifndef MONITOR_H
#define MONITOR_H
#include "system.h"
#include "string.h"
int cursorX , cursorY;
const uint8 sw ,sh ,sd ;
void clearLine(uint8 from,uint8 to);
void updateCursor();
void clear();
void scrollUp(uint8 lineNumber);
void newLineCheck();
void printch(char c);
void print(string ch);
void println(string ch);
void set_screen_color_from_color_code(int color_code);
void set_screen_color(int text_color,int bg_color);
void print_colored(string ch,int text_color,int bg_color);
#endif
