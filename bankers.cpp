#include <iostream>
using namespace std;

int main()
{
    int n,m;
    cout<<"Enter no. of processes,resources";
    cin>>n>>m;

    int alloc[n][m],max_need[n][m],avail[m],need[n][m];
    int f[n],ans[n],ind=0;

    cout<<"Enter Allocation Matrix";
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            cin>>alloc[i][j];
        }
    }

    cout<<"Enter Max_Need Matrix";
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            cin>>max_need[i][j];
        }
    }

    cout<<"Enter Available";
    for(int i=0;i<m;i++)
    {
        cin>>avail[i];
    }

    //Find remaining_need
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            need[i][j] = max_need[i][j]-alloc[i][j];
        }
    }

    for(int i=0;i<n;i++)
        f[i]=0;

    
    //Find safe seq.
    for(int k=0;k<n;k++)
    {
        for(int i=0;i<n;i++)
        {
            if(f[i]==0)
            {
                int flag = 0;
                for(int j=0;j<m;j++)
                {
                    if(need[i][j]>avail[j])//not possible
                    {
                        flag=1;
                        break;
                    }
                }
                if(flag==0)
                {
                    ans[ind++]=i;
                    f[i]=1;
                    for(int j=0;j<m;j++)
                        avail[j] = avail[j]+alloc[i][j];
                }
            }
        }
    }

    //check if safe seq founds
    bool found = true;
    for(int i=0;i<n;i++)
    {
        if(f[i]==0)
        {
            found = false;
            break;
        }
    }

    if(!found)
        cout<<"Safe seq not found";
    else
    {
        for(int i=0;i<n;i++)
            cout<<ans[i]<<"->";
    }
    return 0;
}