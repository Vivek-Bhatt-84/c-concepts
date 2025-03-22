#include<iostream>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

using namespace std;

int main(){

    pid_t pid;
    cout << pid << endl;
    if(pid < 0){
        cerr << "process creation failed " << endl;
        return 1;
    }

    if(pid == 0){
        cout << "in this " << endl;
        cout << "parent process with id : " << getpid() << endl;
        cout << "child process with id : " << getppid() << endl;
    }

    else{
        cout << "parent process with id : " << getpid() << endl;
        cout << "child process with id : " << pid << endl;
        wait(NULL);
    }

return 0;
}
