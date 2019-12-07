// parser.c
#include "global.h"
int lookahead;
// 分析并翻译表达式列表
parse() {
  lookahead = lexan();
  while (lookahead != DONE) {
    expr();
    match(';');
  }
}

expr() {
  int t;
  term();
  while (1) {
    switch (lookahead) {
      case '+':
      case '-':
        t = lookahead;
        match(lookahead);
        term();
        emit(t, NONE);
        continue;
      default:
        return;
    }
  }
}
term(){

}
factor(){

}
match(t){}