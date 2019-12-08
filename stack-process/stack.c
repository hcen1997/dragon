#include "stack.h"

int sp = -1;

push(int v) {
  sp = sp + 1;
  stack[sp] = v;
}

int pop() {
  int tmp = stack[sp];
  sp = sp - 1;
  return tmp;
}