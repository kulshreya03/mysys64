#include<iostream>
#include<unistd.h>
#include<sys/wait.h>

#include <cstring>
#include <cstdlib>  // for exit()
using namespace std;


int main() 
{
    int choice;
    char source[100], destination[100], pattern[100], filename[100];

    cout << "Choose a command to simulate:" << endl;
    cout << "1. cp (copy file)" << endl;
    cout << "2. grep (search pattern in file)" << endl;
    cout << "Enter your choice (1 or 2): ";
    cin >> choice;

    pid_t pid = fork();

    if (pid < 0) {
        perror("Fork failed");
        exit(EXIT_FAILURE);
    }

    if (pid == 0) {
        // Child process
        cout << "[Child] PID: " << getpid() << endl;

        if (choice == 1) {
            cout << "Enter source file: ";
            cin >> source;
            cout << "Enter destination file: ";
            cin >> destination;

            execlp("cp", "cp", source, destination, (char *)NULL);
            perror("execlp failed for cp");
            exit(EXIT_FAILURE);  // Only reached if execlp fails
        } else if (choice == 2) {
            cout << "Enter pattern to search: ";
            cin >> pattern;
            cout << "Enter filename: ";
            cin >> filename;

            execlp("grep", "grep", pattern, filename, (char *)NULL);
            perror("execlp failed for grep");
            exit(EXIT_FAILURE);  // Only reached if execlp fails
        } else {
            cout << "Invalid choice" << endl;
            exit(EXIT_FAILURE);
        }
    } else {
        // Parent process
        cout << "[Parent] PID: " << getpid() << ", waiting for child PID: " << pid << endl;
        wait(NULL);
        cout << "Command executed. Parent exiting." << endl;
    }

    return 0;
}











