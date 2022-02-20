//
// Created by 郭淳宇 on 2022/2/8.
//

#ifndef PYANIST_CLIENT_DATATRANS_H
#define PYANIST_CLIENT_DATATRANS_H

#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <iostream>
#include "fileSize.h"
using namespace std;

void *sendMsg(void *socket);

void *recvMsg(void *socket);

#endif //PYANIST_CLIENT_DATATRANS_H
