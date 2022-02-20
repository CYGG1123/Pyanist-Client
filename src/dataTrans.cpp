#include "dataTrans.h"

struct PacketHeader
{
    int size; // 大小：字节
    PacketHeader()
    {
        size = 0;
    }
};

void *sendMsg(void *socket)
{
    int sock = *((int *)socket);
    while (1)
    {
        string filename;
        cin >> filename;
        FILE *fp = fopen(("../image/" + filename).c_str(), "rb");
        if (fp == NULL)
        {
            cout << "file not found" << endl;
            continue;
        }
        int sz = FileSize(("../image/" + filename).c_str());
        cout << "文件打开成功,大小:" << sz << " Bytes" << endl;

        PacketHeader ph;
        ph.size = sz;
        send(sock, (const char *)&ph, sizeof(ph), 0);
        cout << "已发送头部信息" << endl;

        int nSend = 0;
        char buffer[1024];
        while (nSend < sz)
        {
            int nBytes = fread(buffer, sizeof(char), sizeof(buffer), fp);
            if (nBytes <= 0)
                break;
            send(sock, buffer, nBytes, 0);
            cout << "已发送 " << nBytes << " Bytes" << endl;
            nSend += nBytes;
            usleep(1000);
        }
        cout << "总计发送 " << nSend << " Bytes" << endl;
        fclose(fp);
        cout << "successfully send " + filename << endl;
    }
}

void *recvMsg(void *socket)
{
    int sock = *((int *)socket);
    while (1)
    {
        char msg[1024];
        memset(msg, 0, sizeof(msg));

        ssize_t bytecount = recv(sock, msg, sizeof(msg), 0); //接收消息
        if (bytecount <= 0)
        {
            continue;
        }
        else
        {
            cout << "recv:" << msg << endl;
        }
    }
}
