#include "stack.h"

process() {
  int result = 0;
  int t;
  int val = NONE;
  while (1) {
    t = getchar();
    if (t == ' ' || t == '\n') {
      ;
    } else if (isdigit(t)) {
      ungetc(t, stdin);
      scanf("%d", &val);
      if (val != NONE) {
        push(val);
      } else {
        fprintf(stderr, "error in scanf.");
      }
    } else if (t == '+') {
      int tmp1 = pop();
      int tmp2 = pop();
      push(tmp1 + tmp2);
    } else if (t == '-') {
      int tmp1 = pop();
      int tmp2 = pop();
      push(tmp1 - tmp2);
    } else if (t == '*') {
      int tmp1 = pop();
      int tmp2 = pop();
      push(tmp1 * tmp2);
    } else if (t == '/') {
      int tmp1 = pop();
      int tmp2 = pop();
      push(tmp1 / tmp2);
    } else if (t == EOF) {
      result = pop();
      printf("%d", result)
    } else {
      fprintf(stderr, "error in processing.");
      exit(1);
    }
  }
}