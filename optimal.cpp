#include <iostream>
using namespace std;

int findOptimal(int pages[],int frame[],int n,int current,int capacity)
{
    int farthest = current;//current index
    int replaceIndex = -1;

    for(int i=0;i<capacity;i++)
    {
        int j;
        for(j=current+1;j<n;j++)
        {
            if(frame[i]==pages[j])
            {
                if(j>farthest)
                {
                    farthest = j;
                    replaceIndex = i;
                }
                break;
            }
        }
        if (j == n) //page never used again
            return i;
    }

    return (replaceIndex == -1) ? 0 : replaceIndex; //no current page appears again
}

void optimal(int pages[],int n, int capacity)
{
    int frame[capacity];
    int faultcnt = 0;

    for(int i=0;i<capacity;i++)
        frame[i] = -1;
    
    for(int i=0;i<n;i++)
    {
        int page = pages[i];
        bool found = false;

        //Check if already present
        for(int j=0;j<capacity;j++)
        {
            if(frame[j]==page)
            {
                found = true;
                cout<<"\nPage "<<page<<" is already present";
                break;
            }
        }
        if(found)
            continue;

        //check if free space to be placed
        bool placed = false;
        for(int j=0;j<capacity;j++)
        {
            if(frame[j]==-1)
            {
                placed = true;
                frame[j]=page;
                faultcnt++;
                cout<<"\nPage "<<page<<" caused a page fault.";
                break;
            }
        }

        //if no free space, replace
        if(!placed)
        {
            int replaceIndex = findOptimal(pages,frame,n,i,capacity);
            frame[replaceIndex]=page;
            faultcnt++;
            cout<<"\nPage "<<page<<" caused a page fault.";
        }
    }

    cout<<"\nTotal page faults="<<faultcnt;
    cout<<"\nFault Ratio="<<(faultcnt/(float)n)*100;
}

int main()
{
    int n;
    cout<<"Enter the no. of pages:";
    cin>>n;

    int pages[n],capacity = 4;
    for(int i=0;i<n;i++)
        cin>>pages[i];

    optimal(pages,n,capacity);

    return 0;
}
