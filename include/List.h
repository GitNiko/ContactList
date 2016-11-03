#ifndef __LIST_H__
#define __LIST_H__

#include "Types.h"

typedef struct {
  STATUS (*init)();
  STATUS (*insert)(void *value);
  STATUS (*append)(void *value);
  STATUS (*remove)(int index);
  STATUS (*get)(int index);
  STATUS (*destory)();
} TagList;

#define List TagList

#endif
