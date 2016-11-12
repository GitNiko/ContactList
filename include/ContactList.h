#ifndef __CONTACTLIST_H__
#define __CONTACTLIST_H__

#include "Types.h"
#include <string.h>

#define Female            0
#define Male              1
// 姓名最大长度
#define MaxNameLength     20
// 姓名最小长度
#define MinNameLength     1
// 号码最大位数
#define MaxMobileLength   18
// 号码最小位数
#define MinMobileLength   11
// 住址最大内容
#define MaxAddressLength  50
// 住址最小内容
#define MinAddressLength   0


struct Tag_UserInfo {
  // 姓名
  char name[MaxNameLength];
  // 电话
  char mobile[MaxMobileLength];
  // 地址
  char address[MaxAddressLength];
  // 性别
  Int gender;
};
typedef struct Tag_UserInfo UserInfo;

Status initContactList();
Status searchUser(char* name);
Status addUser(UserInfo userInfo);
Status deleteUser(UserInfo userInfo);
Status destoryContactList();
#endif
