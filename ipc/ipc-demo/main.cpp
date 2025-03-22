#include <iostream>
#include <fstream>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <cstring>

using namespace std;

const char* filename = "students.txt";

// Function for parent to read student data
void write_in() {
    ifstream file(filename);
    if (!file) {
        cerr << "can't open file " << endl;
        exit(1);
    }

    cout << " Student Data (From File): " << endl;
    string line;
    while (getline(file, line)) {
        cout << line << endl;
    }
    file.close();
}

// Function for child to update student data
void read_from() {
    ofstream file(filename, ios::app);
    if (!file) {
        cerr << "Error: Could not open file.\n";
        exit(1);
    }

    cout << "Child process adding a new student...\n";
    file << "ID: 11, Name: Alex, Grade: A\n";  // Append new student
    file.close();
}

int main() {
    int fd[2]; 

    if (pipe(fd) == -1) {
        cerr << "Pipe creation failed!\n";
        return 1;
    }

    pid_t pid = fork();

    if (pid < 0) {
        cerr << "Fork failed!\n";
        return 1;
    } 
    else if (pid == 0) {
        // Child process
        close(fd[0]); 

        write_in(); 

        char msg[] = "Update complete";
        write(fd[1], msg, strlen(msg) + 1); 

        close(fd[1]); 
        exit(0);
    } 
    else {
        // Parent process
        close(fd[1]); 

        cout << "Parent waiting for child process to update file...\n";

        char buffer[100];
        read(fd[0], buffer, sizeof(buffer)); 
        close(fd[0]); 

        cout << "Parent received message: " << buffer << endl;
        cout << "Parent resumes execution...\n";

        read_from(); 

        wait(NULL); 
    }

    return 0;
}