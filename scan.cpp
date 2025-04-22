#include <iostream>
using namespace std;

void scan(int n,int requests[],int head,int disk_size)
{
    int seek = 0;
    int direction = 1;

    requests[n++]=head;
    requests[n++]=0;
    requests[n++]=disk_size-1;

    //Bubble sort reqyests[]
    for(int i=0;i<n-1;i++)
    {
        for(int j=i+1;j<n;j++)
        {
            if(requests[i]>requests[j])
            {
                int temp = requests[i];
                requests[i]=requests[j];
                requests[j]=temp;
            }
        }
    }
    
    int index = 0;
    for(int i=0;i<n;i++)
    {
        if(requests[i]==head)
        {
            index=i;
            break;
        }
    } 
    cout<<head;

    for(int i=index+1;i<n;i++)
    {
        seek+=abs(requests[i]-head);
        head=requests[i];
        cout<<"->"<<head;
    }
    for(int i=index-1;i>=0;i--)
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

    int requests[100]; //it will increase
    cout<<"Enter requests";
    for(int i=0;i<n;i++)
        cin>>requests[i];

    scan(n,requests,head,200);

    return 0;
}