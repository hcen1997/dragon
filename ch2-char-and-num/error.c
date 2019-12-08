// error.c

#include "global.h"

// 生成所有错误信息
error(char *m){
    fprintf(stderr,"line %d: %s\n",lineno,m);
    // 非正常终止
    exit(1);
}