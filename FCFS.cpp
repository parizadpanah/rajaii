#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

struct Process {
    int id;
    int arrival_time;
    int burst_time;
    int waiting_time;
    int turnaround_time;
};

vector<Process> calculatefcfs(vector<Process> processes) {
    vector<Process> result;
    int current_time = 0;
    double total_processing_time = 0;
    int total_turnaround_time = 0;
    for (int i = 0; i < processes.size(); i++) {
        Process p = processes[i];
        if (p.arrival_time > current_time) {
            current_time = p.arrival_time;
        }
         p.waiting_time = current_time - p.arrival_time;
        p.turnaround_time = p.waiting_time + p.burst_time;
        total_turnaround_time += p.turnaround_time;
        total_processing_time += double(p.turnaround_time) / double(p.burst_time);
        current_time += p.burst_time;
        result.push_back(p);
    }
    cout << "Average processing time: " << total_processing_time / processes.size()<< endl;
    cout << "Average turnaround time: " << (double)total_turnaround_time / processes.size() << endl;
    return result;
}

int main() {
    vector<Process> processes = {{1, 0, 3}, {2, 2, 6}, {3, 4, 4},{4, 6, 5},{5, 8, 2}};
    vector<Process> result = calculatefcfs(processes);

    return 0;
}
