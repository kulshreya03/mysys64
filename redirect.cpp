#include<iostream>
#include<fcntl.h>
#include<unistd.h>
using namespace std;

int main()
{
    // Open input file and redirect stdin (fd 0) 
    int fin = open("input.txt",O_RDONLY);
    if (fin < 0) {
        perror("open input");
        return 1;
    }
    dup2(fin,0); // stdin now comes from input.txt
    close(fin);
    
     // Open output file and redirect stdout (fd 1)
    int fout = open("output.txt",O_WRONLY);
    dup2(fout,1);
    close(fout);
    
    int a,b;
    cin>>a>>b;
    cout<<"Sum:"<<(a+b);
    return 0;
}