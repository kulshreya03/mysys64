#include<iostream>
using namespace std;

struct Process
{
    int pid;
    int at,bt,ct,tat,wt,priority;
    bool visited=false;
};

int main()
{
    int n;
    cout<<"Enter no. of processes:";
    cin>>n;

    Process p[n];
    for(int i=0;i<n;i++)
    {
        cout<<"Enter Arrival,Burst and Priority of "<<i+1;
        cin>>p[i].at>>p[i].bt>>p[i].priority;
        p[i].pid=i+1;
    }

    int completed=0,totalTAT=0,totalWT=0;
    int currentTime=0;
    while(completed<n)
    {
        int maxPrioriy=1e9;
        int idx = -1;
        for(int i=0;i<n;i++)
        {
            if(!p[i].visited && p[i].at<=currentTime && p[i].priority<maxPrioriy)
            {
                maxPrioriy=p[i].priority;
                idx=i;
            }
        }

        if(idx!=-1)
        {
            p[idx].ct=currentTime+p[idx].bt;
            p[idx].tat=p[idx].ct-p[idx].at;
            p[idx].wt=p[idx].tat-p[idx].bt;

            p[idx].visited=true;
            completed++;
            
            currentTime=p[idx].ct;
            totalTAT+=p[idx].tat;
            totalWT+=p[idx].wt;
        }
        else
            currentTime++;
    }

    cout<<"\nPID\tAT\tBT\tPr\tCT\tTAT\tWT";
    for(int i=0;i<n;i++)
    {
        cout<<"\n"<<p[i].pid<<"\t"<<p[i].at<<"\t"<<p[i].bt<<"\t"<<p[i].priority<<"\t"<<p[i].ct<<"\t"<<p[i].tat<<"\t"<<p[i].wt;
    }

    cout<<"Average TAT:"<<totalTAT/n;
    cout<<"Average WT:"<<totalWT/n;

    return 0;
}