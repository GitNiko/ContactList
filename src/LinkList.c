#include "../include/Types.h"
#include "../include/LinkList.h"

static STATUS init() {
  return ERROR;
}
static STATUS (*init)() {
  return ERROR;
}
static STATUS (*insert)(void *value){
  return ERROR;
}
static STATUS (*append)(void *value){
  return ERROR;
}
static STATUS (*remove)(int index){
  return ERROR;
}
static STATUS (*get)(int index){
  return ERROR;
}
static STATUS (*destory)(){
  return ERROR;
}

LinkList

//
// Status makeNode(void * element, LNode * pNode) {
//   pNode = (LinkList)malloc(sizeof(LNode));
//   pNode->data = element;
//   pNode->next = NULL;
//   return OK;
// }
//
