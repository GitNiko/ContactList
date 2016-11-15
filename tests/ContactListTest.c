#include <string.h>
#include "../include/ContactList.h"

#define describe(desc) printf(desc);printf("\n");


int main( int argc, char** argv) {
  describe("init contact list") {
    ContactList * self = NULL;
    initContactList(&self, 20);
    UserInfo lfy = createUser("lfy", "18012344321", "340 Main St, Venice, CA 90291", Female);
    UserInfo lj = createUser("lj", "18032342310", "340 Main St, Venice, CA 90291", Male);
    addUser(self, &lfy);
    addUser(self, &lj);
  }
  return 0;
}
