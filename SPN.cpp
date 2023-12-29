#include <iostream>
#include <algorithm>
using namespace std;

struct Process {
    int pid;
    int arrivalTime;
    int burstTime;
    int waitingTime;
    int turnaroundTime;
};

bool compare(Process p1, Process p2) {
    return p1.burstTime < p2.burstTime;
}

void calculateSPN(Process processes[], int n) {
    sort(processes, processes+n, compare);

    int currentTime = 0;
    double totalprocessingtime = 0;
    int totalTurnaroundTime = 0;

    for (int i = 0; i < n; i++) {
        processes[i].waitingTime = currentTime - processes[i].arrivalTime;

        if (processes[i].waitingTime < 0) {
            processes[i].waitingTime = 0;
        }

        processes[i].turnaroundTime = processes[i].waitingTime + processes[i].burstTime;

        currentTime += processes[i].burstTime;
        totalprocessingtime += double(processes[i].turnaroundTime) / processes[i].burstTime;
        totalTurnaroundTime += processes[i].turnaroundTime;
        
    }
    cout << "Average processing time: " << totalprocessingtime / n << endl;
    cout << "Average turnaround time: " << (double)totalTurnaroundTime / n << endl;
}

int main() {
    Process processes[5] = {{1, 0, 3}, {2, 2, 6}, {3, 4, 4},{4, 6, 5},{5, 8, 2}};

    calculateSPN(processes, 5);

    return 0;
}
