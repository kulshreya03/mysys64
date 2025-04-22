#include <iostream>
using namespace std;

struct Process {
    int pid;
    int at, bt, ct, tat, wt, rt;
    bool visited = false;
};

int main() {
    int n;
    cout << "Enter no. of processes: ";
    cin >> n;

    Process p[n];

    for (int i = 0; i < n; i++) {
        cout << "Enter Arrival and Burst Time of " << i + 1 << ": ";
        cin >> p[i].at >> p[i].bt;
        p[i].pid = i + 1;
        p[i].rt = p[i].bt;  // Initialize remaining time
    }

    int completed = 0, currentTime = 0;
    int totalTAT = 0, totalWT = 0;

    while (completed < n) 
    {
        int idx = -1;
        int minRT = 1e9;

        // Find the process with shortest remaining time at this time
        for (int i = 0; i < n; i++) 
        {
            if (p[i].at <= currentTime && p[i].rt > 0 && p[i].rt < minRT) 
            {
                minRT = p[i].rt;
                idx = i;
            }
        }

        if (idx != -1) 
        {
            p[idx].rt--;
            currentTime++;

            if (p[idx].rt == 0) 
            {
                p[idx].ct = currentTime; //imp
                p[idx].tat = p[idx].ct - p[idx].at;
                p[idx].wt = p[idx].tat - p[idx].bt;

                totalTAT += p[idx].tat;
                totalWT += p[idx].wt;
                
                p[idx].visited = true;
                completed++;
            }
        } 
        else 
            currentTime++; // No process is ready, idle CPU
    }

    // Output the results
    cout << "\nPID\tAT\tBT\tCT\tTAT\tWT\n";
    for (int i = 0; i < n; i++) {
        cout << p[i].pid << "\t" << p[i].at << "\t" << p[i].bt << "\t"
             << p[i].ct << "\t" << p[i].tat << "\t" << p[i].wt << "\n";
    }

    cout << "\nAvg TAT: " << (float)totalTAT / n;
    cout << "\nAvg WT: " << (float)totalWT / n;

    return 0;
}
