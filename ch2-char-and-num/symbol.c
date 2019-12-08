// symbol.c

#include "global.h"

// lexemes 数组大小
#define STRMAX 999
// symtable 的大小
#define SYMMAX 100
char lexemes[SYMMAX];
// lexemes 中最后引用的位置
int lastchar = -1;
struct entry symtable[SYMMAX];
int lastentry = 0;

// 返回 s 的表项的位置
int lookup(char s[]) {
  int p;
  for (p = lastentry; p > 0; p = p - 1) {
    if (strcmp(symtable[p].lexptr, s) == 0) {
      return p;
    }
  }
  return 0;
}

// 返回 s 的表项位置
int insert(char s[], int tok) {
  int len;
  len = strlen(s);

  if (lastentry + 1 >= SYMMAX) {
    error("symbol table full");
  }
  if (lastchar + len + 1 >= STRMAX) {
    error("lexemes array full");
  }

  lastentry = lastentry + 1;
  symtable[lastentry].token = tok;
  symtable[lastentry].lexptr = &lexemes[lastchar + 1];
  lastchar = lastchar + len + 1;
  strcpy(symtable[lastentry].lexptr, s);
  
  return lastentry;
}

