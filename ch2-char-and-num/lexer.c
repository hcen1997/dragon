// lexer.c
// author hcen1997

#include "global.h"
char lexbuf[BSIZE];
int lineno = 1;
int tokenval = NONE;

// 词法分析器
int lexan() {
  int t;
  while (1) {
    t = getchar();
    if (t == ' ' || t == '\t') {
      // 去除空白符
      ;
    } else if (t == '\n') {
      lineno = lineno + 1;
    } else if (isdigit(t)) {
      ungetc(t, stdin);
      scanf("%d", &tokenval);
      return NUM;
    } else if (isalpha(t)) {
      int p, b = 0;
      while (isalnum(t)) {
        lexbuf[b] = t;
        t = getchar();
        b = b + 1;
        if (b >= BSIZE) {
          error("compiler error");
        }
      }
      lexbuf[b] = EOS;
      if (t != EOF) {
        ungetc(t, stdin);
      }
      p = lookup(lexbuf);
      if (p == 0) {
        p = insert(lexbuf, ID);
      }
      tokenval = p;
      return symtable[p].token;
    } else if (t == EOF) {
      return NONE;
    } else {
      tokenval = NONE;
      return t;
    }
  }
}