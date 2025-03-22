#include <iostream>
#include <unistd.h>
#include <cstring>

using namespace std;

int main(){

    int fd[2];

    pid_t pid;

    if(pipe(fd) == -1){
        cerr << "pipe creation failed " << endl;
        return 1;
    }

    pid = fork();

    if(pid == 0) {
        close(fd[1]);

        char buffer[100];
        read(fd[0] , buffer , sizeof(buffer));
        cout << "message from parent : " << buffer << endl;
        close(fd[0]);
    }
    else{
        close(fd[0]);

        const char* buff = "hello from parent   ";
        write(fd[1] , buff , strlen(buff)+1);
        close(fd[1]);

    }

    return 0;
}