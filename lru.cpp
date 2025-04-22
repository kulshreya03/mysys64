#include <iostream>
using namespace std;

void lru(int pages[],int n, int capacity)
{
    int frame[capacity],recentlyUsed[capacity];
    int faultcnt=0;

    
    for(int i=0;i<capacity;i++)
    {
        frame[i]=-1;
        recentlyUsed[i]=-1;
    }


    //check if present
    for(int i=0;i<n;i++)
    {
        int page = pages[i];
        bool found = false;

        for(int j=0;j<capacity;j++)
        {
            if(page==frame[j])
            {
                found=true;
                cout<<"Page "<<page<<" found";
                recentlyUsed[j]=i;
                break;
            }
        }
        if(found)
            continue;

        //if place is empty
        bool placed = false;
        for(int j=0;j<capacity;j++)
        {
            if(frame[j]==-1)
            {
                placed=true;
                frame[j]=page;
                cout<<"Page "<<page<<" fault occured";
                faultcnt++;
                recentlyUsed[j]=i;
                break;
            }
        }

        if(!placed)
        {
            int lruIndex=0;
            for(int j=0;j<capacity;j++)
            {
                if(recentlyUsed[j]<recentlyUsed[lruIndex])
                    lruIndex=j;
            }

            frame[lruIndex] = page;
            recentlyUsed[lruIndex] = i;
            faultcnt++;
        }

        cout << " Frame: ";
        for (int j = 0; j < capacity; j++) {
            cout << (frame[j] == -1 ? "-" : to_string(frame[j])) << " ";
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

    lru(pages,n,capacity);

    return 0;
}
