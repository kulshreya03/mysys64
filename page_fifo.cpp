#include <iostream>
using namespace std;

void fifo(int pages[],int n,int capacity)
{
    int frame[capacity];
    int front = 0;
    int faultcnt=0;

    for(int i=0;i<capacity;i++)
        frame[i] = -1;
    
    for(int i=0;i<n;i++)
    {
        int page = pages[i];
        bool found = false;

        for(int j=0;j<capacity;j++)
        {
            if(page==frame[j])
            {
                found = true;
                break;
            }
        }

        if(!found)
        {
            frame[front] = page;
            front = (front+1)%capacity;
            faultcnt++;
            cout<<"Page "<<page<<" caused a page fault.\n";
        }
        else
            cout<<"Page"<<page<<" already exists\n";
    }

    cout<<"Total page faults="<<faultcnt;
    cout<<"\nFault Ratio="<<(faultcnt/(float)n)*100;
}

int main()
{
    int n;
    cout<<"Enter the no. of pages:";
    cin>>n;

    int pages[n];
    cout<<"Enter the pages:";
    for(int i=0;i<n;i++)
        cin>>pages[i];

    int capacity = 3; //frame size
    fifo(pages,n,capacity);
    return 0;
}
