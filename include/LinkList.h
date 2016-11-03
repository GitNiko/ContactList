#ifndef __LINKLIST_H__
#define __LINKLIST_H__

#include "List.h"

typedef struct {
  void * data;
  struct LNode *next;
}TagLNode;
#define LNode TagLNode

typedef struct {
  // interface
  List list;

  //data
  LNode *node;
}TagLinkList;
#define LinkList TagLinkList

// Status makeNode(void * element, LNode * pNode);
// Status initList( LinkList * linkList );
// Status destoryList( LinkList * linkList);
// Status clearList( LinkList * linkList);
// Status isEmptyList( LinkList * linkList);
// Status getElem();

#endif
