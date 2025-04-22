#include<iostream>
#include<unistd.h>
#include<sys/wait.h>
using namespace std;

int main()
{
    int pipe1[2],pipe2[2];
    pipe(pipe1);
    pipe(pipe2);
    
    pid_t p = fork();
    if(p>0)
    {
        close(pipe1[0]);
        close(pipe2[1]);
        write(pipe1[1],"Shreya",7);
        
        char buffer[100];
        read(pipe2[0],buffer,5);
        cout<<"Message from Child:"<<buffer;
        
        wait(NULL);
    }
    else
    {
        close(pipe1[1]);
        close(pipe2[0]);
        
        char buffer[100];
        read(pipe1[0],buffer,7);
        cout<<"Message from Parent:"<<buffer;
        
        write(pipe2[1],"Ansh",5);
    }
    
    return 0;
}