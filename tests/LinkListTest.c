#include "../include/LinkList.h"

#define describe(desc) printf(desc);printf("\n");


int main( int argc, char** argv) {
  describe("LinkList init") {
    int element = 10;
    int * pInt = NULL;
    LinkList elementList;
    makeNode(&element, elementList);
    printf("element\n");
    printf("element is (%d)\n", *((int*)elementList->data));
  }
  return 0;
}
