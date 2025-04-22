#include<iostream>
#include<queue>
using namespace std;

struct Process
{
    int pid;
    int at,bt,ct,tat,wt,rt;
    bool inQueue=false;
};

int main()
{
    int n;
    cout<<"Enter the no. of processes:";
    cin>>n;

    Process p[n];
    for(int i=0;i<n;i++)
    {
        cout<<"Enter at,bt of "<<i+1;
        cin>>p[i].at>>p[i].bt;
        p[i].pid=i+1;
        p[i].rt=p[i].bt;
    }

    int timeQuantum;
    cout<<"Enter time quantum:";
    cin>>timeQuantum;

    queue<int> q;
    int currentTime=0;
    int totalTAT=0,totalWT=0;

    while(true)//push first available
    {
        bool found=false;
        for(int i=0;i<n;i++)
        {
            if(p[i].at<=currentTime && !p[i].inQueue && p[i].rt>0)
            {
                q.push(i);
                p[i].inQueue=true;
                found=true;
            }
        }
        if(found|| !q.empty())
            break;
        
        currentTime++;
    }

    while(!q.empty())
    {
        int idx = q.front();
        q.pop();
        
        int execTime=min(timeQuantum,p[idx].rt);
        currentTime=currentTime+execTime;
        p[idx].rt=p[idx].rt-execTime;

        for(int i=0;i<n;i++)//inser new
        {
            if(p[i].at<=currentTime && !p[i].inQueue && p[i].rt>0)
            {
                q.push(i);
                p[i].inQueue=true;
            }
        }

        if(p[idx].rt>0)
            q.push(idx);
        else
        {
            p[idx].ct=currentTime;
            p[idx].tat=p[idx].ct-p[idx].at;
            p[idx].wt=p[idx].tat-p[idx].bt;
            totalTAT+=p[idx].tat;
            totalWT+=p[idx].wt;
        }


    }
    
    cout << "\nPID\tAT\tBT\tCT\tTAT\tWT\n";
    for (int i = 0; i < n; i++) {
        cout << "P" << p[i].pid << "\t" << p[i].at << "\t" << p[i].bt << "\t"
             << p[i].ct << "\t" << p[i].tat << "\t" << p[i].wt << "\n";
    }

    cout << "\nAverage TAT: " << totalTAT / n;
    cout << "\nAverage WT: " << totalWT / n;

    return 0;
}