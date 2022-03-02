# 基于深度学习的智能钢琴演奏机器人-客户端

## 姊妹项目
基于深度学习的智能钢琴演奏机器人-客户端
https://github.com/ElderBacon/Pyanist-Server.git
## 软件环境
基于debian的Raspberry Pi OS x64
## 硬件环境
raspberry pi 4B
PCA9685 16通道PWM控制器
## 实现功能
将由摄像头获取到的图片发送至服务端，并接受服务端传回的乐谱信息
## 实现步骤
1. 与服务器之间建立Socket连接
2. 向服务端发送图片
3. 服务端处理完成后接收字符串形式的乐谱信息
4. 调用相应的控制程序进行演奏

## 实现细节
1. 使用Socket进行传输时容易产生误码，故加入了信息大小的检查作为校验，可在包中加入更多信息来确保传输的正确
2. 客户端直接调用 Python.h 头文件失败，故采用手动连接字符串方式来调用
3. executeCMD 函数用于执行系统命令，同时可读取终端中的输出并保存起来
4. 将收到的文件用日期命名，以免文件重名的同时还能方便管理

## 性能表现
由于预算有限，采用的是低速步进电机和舵机，仅能演奏小星星这样速度的音乐
## 演示视频
待续