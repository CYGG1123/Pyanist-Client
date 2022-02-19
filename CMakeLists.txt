cmake_minimum_required(VERSION 3.18)
project(Pyanist_Client)

set(CMAKE_CXX_STANDARD 20)
# set(CMAKE_CXX_FLAGS "${CAMKE_CXX_FLAGS} -std=c++20")
set(CMAKE_CXX_FLAGS "-pthread")

#set(CAMKE_CXX_FLAGS "-I/home/pi/miniforge3/envs/pianist/include/python3.8/ -l python3.8")
add_executable( Pyanist_Client src/main.cpp
                src/dataTrans.cpp src/dataTrans.h
                src/playMusic.cpp src/playMusic.h
                src/executeCMD.cpp src/executeCMD.h)