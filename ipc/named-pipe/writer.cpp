#include<iostream>
#include <fcntl.h>
#include <cstring>
#include <unistd.h>

using namespace std;

int main(){
    const char* fifoPath = "mypipe";

    int fd = open(fifoPath , O_WRONLY);
    // cout << fd << endl;

    string buff;
    getline(cin,buff);
    write(fd , buff.c_str() , buff.length()+1);
    close(fd);

    return 0;
}