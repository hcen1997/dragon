// init.c

#include "global.h"

struct entry keywords[] = {"div", DIV, "mod", MOD, 0, 0};

// 将关键字填入符号表
init() {
  struct entry *p;
  for (p = keywords; p->token; p++) {
    insert(p->lexptr, p->token);
  };
}