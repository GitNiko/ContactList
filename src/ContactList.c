#include "../include/ContactList.h"

/**
 * 初始化联系人列表
 * @param  pContactList I 联系人列表指针
 * @param  size         I 列表大小
 * @return
 */
Status initContactList(ContactList ** pContactList, Int size) {
  if(NULL == *pContactList) {
    // 初始化联系人
    ContactList contactList;
    contactList.pUserInfo = (UserInfo *)malloc(sizeof(UserInfo) * size);
    if(NULL == contactList.pUserInfo) {
      return OVERFLOW;
    }
    contactList.self = &contactList;
    contactList.length = size;
    *pContactList = &contactList;
    return OK;
  } else {
    // 已经初始化过了
    return ERROR;
  }
}
// 计算联系人个数
Int countContactList(ContactList * self) {
  Int count = 0;
  for(count; count < self->length; count++) {
    Int offset = count * sizeof(UserInfo);
    printf("%s", ((UserInfo*)(self->pUserInfo + offset))->mobile);
    if(strlen(self->pUserInfo[count].mobile) == 0) {
      // 电话号码为空的时候返回
      break;
    }
  }
  return count;
}
// 判断联系人是否满了
Bool isMax(ContactList * self) {
  if(self->length == countContactList(self)) {
    return TRUE;
  }
  return FALSE;
}

Status destoryContactList(ContactList * self) {
  // todo
  return ERROR;
}

Status searchUser(ContactList * self, char* name) {
  // todo
  return ERROR;
}
// 创建一个联系人
UserInfo createUser(char* name, char* mobile, char* address, Int gender) {
  UserInfo user;
  // todo:字符长度检查
  strcpy(user.name, name);
  strcpy(user.mobile, mobile);
  strcpy(user.address, address);
  user.gender = gender;

  return user;
}
// 添加一个联系人
Status addUser(ContactList * self, UserInfo * pUserInfo) {
  if(isMax(self) != TRUE) {
    //联系人没有满,可以添加
    int index = 0;
    for(index; index < self->length;index++) {
      if(strlen(self->pUserInfo[index].mobile) == 0) {
        // 未空表示没有联系人，可以添加
        self->pUserInfo[index] = *pUserInfo;
        printf("ContactList add user success!\n");
        break;
      }
    }
    return OK;
  } else {
    printf("ContactList is max!\n");
    return ERROR;
  }
}

Status deleteUser(ContactList * self, ContactList userInfo) {
  // todo
  return ERROR;
}
