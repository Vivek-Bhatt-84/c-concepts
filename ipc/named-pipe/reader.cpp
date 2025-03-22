#include <iostream>
#include <fcntl.h>
#include <cstring>
#include <unistd.h>


using namespace std;

int main(){ 
    const char* filePath = "mypipe";

    int fd  = open("mypipe" , O_RDONLY );
    char buffer[100];
    read(fd , buffer , sizeof(buffer));
    cout << "data from writer side : " << buffer << endl;
    return 0;
}