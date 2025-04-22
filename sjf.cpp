#include <iostream>
#include <algorithm>
using namespace std;

struct Process
{
    int pid;
    int at,bt,ct,tat,wt;
    bool visited = false;
};

bool compare(Process a, Process b)
{
    return a.at<b.at;
}
int main()
{
    int n;
    cout<<"Enter no. of processes";
    cin>>n;
    Process p[n];

    for(int i=0;i<n;i++)
    {
        cout<<"Enter Arrival and Burst Time of "<<i+1;
        cin>>p[i].at>>p[i].bt;
        p[i].pid = i+1;
    }

    int avgTAT=0,avgWT=0;
    int completed = 0;
    int currentTime = 0;
    while(completed<n)
    {
        int idx=-1;
        int minBT = 1e9;

        for(int i=0;i<n;i++) //find min in all arrived
        {
            if(!p[i].visited && p[i].at<=currentTime && p[i].bt < minBT)
            {
                idx = i;
                minBT = p[i].bt;
            }
        }

        if(idx!=-1)
        {
            p[idx].ct=currentTime+p[idx].bt;
            p[idx].tat=p[idx].ct-p[idx].at;
            p[idx].wt=p[idx].tat-p[idx].bt;

            currentTime=p[idx].ct;
            avgTAT+=p[idx].tat;
            avgWT+=p[idx].wt;

            p[idx].visited=true;
            completed++;

        }
        else
            currentTime++;


    }

    


    cout<<"PID\tAT\tBT\tCT\tTAT\tWT\n";
    for(int i=0;i<n;i++)
    {
        cout<<p[i].pid<<"\t"<<p[i].at<<"\t"<<p[i].bt<<"\t"<<p[i].ct<<"\t"<<p[i].tat<<"\t"<<p[i].wt<<"\n";
    }
    cout<<"\n Avg tat:"<<avgTAT/n;
    cout<<"\nAvg WT:"<<avgWT/n;

    return 0;
}