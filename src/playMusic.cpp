#include "playMusic.h"

using namespace std;

int playMusic(char *music_cStyle)
{
    // dataTrans.cpp中接收到的字符串存入了char msg[4096];根据其中的字符串信息来处理
    string music_cppStyle(music_cStyle);
    if (system(("python3 /home/pi/Project/Pyanist-Client/src/test.py" + music_cppStyle).c_str()))
    {
        cout << "playMusic success" << endl;
        return 1;
    }
    else
    {
        cout << "playMusic failed" << endl;
        return 0;
    }
    // system("python3 /home/pi/Project/Pyanist-Client/src/servoControl.py");
    return 0;
}

int playMusic(string music_cppStyle)
{
    // dataTrans.cpp中接收到的字符串存入了char msg[4096];根据其中的字符串信息来处理
    if (system(("python3 /home/pi/Project/Pyanist-Client/src/servoControl.py" + music_cppStyle).c_str()))
    {
        return 1;
    }
    else
    {
        cout << "playMusic failed" << endl;
        return 0;
    }
}
