#include <iostream>
using namespace std;

void sstf(int n,int requests[],int head)
{
    int seek = 0;
    bool visited[n] = {false};
    cout<<head;

    for(int i=0;i<n;i++)
    {
        int minSeek = 1e9;
        int minIndex = -1;
        for(int j=0;j<n;j++)
        {
            if(!visited[j] && abs(requests[j]-head)<minSeek)
            {
                minSeek = abs(requests[j]-head);
                minIndex = j;
            }
        }

        seek+=abs(requests[minIndex]-head);
        head = requests[minIndex];
        cout<<"->"<<head;
        visited[minIndex]=true;
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

    sstf(n,requests,head);

    return 0;
}