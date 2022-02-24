#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <iostream>

#include "dataTrans.h"
#include "playMusic.h"
#include "executeCMD.h"
using namespace std;

int main()
{
    pthread_t recv;
    pthread_t send;
    char ipaddr[14] = "192.168.5.193";
    int port = 7777;
    int sock = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP); // AF_INET指明使用ipv4，sock_stream指定使用流套接字，ipproto_tcp指定使用tcp协议

    if (sock < 0)
    {
        cout << "socket() failed" << endl;
    }

    struct sockaddr_in servAddr; //结构体用于存放地址
    memset(&servAddr, '\0', sizeof(struct sockaddr_in));
    servAddr.sin_family = AF_INET;

    int rtn = inet_pton(AF_INET, ipaddr, &servAddr.sin_addr.s_addr); //转换ip地址格式，从本机字节序转换成为网络字节序
    if (rtn == 0)
    {
        cout << "address wrong ,inet_pton() failed" << endl;
    }
    else if (rtn < 0)
    {
        cout << "inet_pton() failed" << endl;
    }

    servAddr.sin_port = htons(port);

    if (connect(sock, (struct sockaddr *)&servAddr, sizeof(servAddr)) < 0) //连接到服务器
    {
        cout << "connect failed" << endl;
    }
    else
    {
        cout << "connect success" << endl;
    }

    pthread_create(&recv, NULL, recvMsg, &sock);
    pthread_create(&send, NULL, sendMsg, &sock);
    pthread_join(recv, 0);
    pthread_join(send, 0);

    close(sock);
}