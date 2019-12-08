// global.h
// author hcen1997

// 输入输出
#include <stdio.h>
// 加载字符测试程序
#include <ctype.h>

// 缓冲区大小
#define BSIZE 128
#define NONE -1
#define EOS '\0'

#define NUM 256
#define DIV 257
#define MOD 258
#define ID 259
#define DONE 260

// 记号的属性值
int tokenval;
int lineno;

// 符号表的表项格式
struct entry {
  char *lexptr;
  int token;
};

// 符号表
struct entry symtable[];
