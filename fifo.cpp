#include <iostream>
using namespace std;

void fifo(int n,int requests[],int head)
{
    int seek = 0;
    cout<<head;
    for(int i=0;i<n;i++)
    {
        seek+=abs(requests[i]-head);
        head=requests[i];
        cout<<"->"<<head;
    }

    cout<<"\nTotal seek time:"<<seek;
}

int main()
{
    int n,head;
    cout<<"Enter no. of requests,head";
    cin>>n>>head;

    int requests[n];
    cout<<"Enter requests";
    for(int i=0;i<n;i++)
        cin>>requests[i];

    fifo(n,requests,head);

    return 0;
}