#include<iostream>
#include <unistd.h> // Provides access to the POSIX operating system API, 
// including functions like pipe() and fork().
#include <sys/types.h> //Defines data types used in system calls, such as pid_t.

#include <cstring>
using namespace std;

int main(){

    int fd[2];
    if(pipe(fd) == -1){
        cerr << "pipe creation failed " << endl;
        return 1;
    }
    pid_t  pid = fork();

    if(pid  < 0){
        cerr << "process creation failed " << endl;
        return 1;
    }

    if(pid == 0){

        close(fd[0]);
        const char* mesg = "Hello from child " ;

        write(fd[1],mesg ,strlen(mesg) + 1);
        close(fd[1]);
    }
    else{
        close(fd[1]);
        char buff[50];
        
        read(fd[0] , buff , sizeof(buff));
        cout << "parent recevied child : " << buff  << endl;
        close(fd[0]);
    }

return 0;
}