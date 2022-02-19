#include "dataTrans.h"

void *sendMsg(void *socket) {
    int sock = *((int *) socket);
    while (1) {
        char msg[4096];
        string filename;
        cin >> filename;
        FILE *fp = fopen(filename.c_str(), "rb");
        if (fp == NULL) {
            cout << "file not found" << endl;
            continue;
        }
        while (!feof(fp)) {
            memset(msg, 0, sizeof(msg));
            size_t readlength = fread(msg, 1, 4096, fp);
            if (readlength <= 0) {
                continue;
            }
            ssize_t bytecount = send(sock, msg, readlength, 0); //发送消息
            if (bytecount < 0) {
                cout << "send failed" << endl;
            }
        }
        cout << "successfully send " + filename << endl;
    }
}

void *recvMsg(void *socket) {
    int sock = *((int *) socket);
    while (1) {
        char msg[4096];
        memset(msg, 0, sizeof(msg));

        ssize_t bytecount = recv(sock, msg, sizeof(msg), 0); //接收消息
        if (bytecount <= 0) {
            continue;
        } else {
            cout << "recv:" << msg << endl;
        }
    }
}
