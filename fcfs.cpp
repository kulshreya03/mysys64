#include <iostream>
#include <algorithm>
using namespace std;

struct Process
{
    int pid;
    int at,bt,ct,tat,wt;
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

    sort(p,p+n,compare);

    int currentTime = 0,avgTAT=0,avgWT=0;
    for(int i=0;i<n;i++)
    {
        if(currentTime<p[i].at)
            currentTime = p[i].at;
        
        p[i].ct = currentTime+p[i].bt;
        p[i].tat = p[i].ct-p[i].at;
        p[i].wt = p[i].tat-p[i].bt;

        currentTime = p[i].ct;
        avgTAT+=p[i].tat;
        avgWT+=p[i].wt;
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