#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct Process {
    int id;
    int arrival_time;
    int burst_time;
    int remaining_time;
    int priority;
};

bool compare_arrival_time(Process p1, Process p2) {
    return p1.arrival_time < p2.arrival_time;
}

bool compare_priority(Process p1, Process p2) {
    return p1.priority > p2.priority;
}

void calculateFB(vector<Process> processes, int quantum1, int quantum2) {
    int n = processes.size();
    int current_time = 0;
    int total_waiting_time = 0;
    int total_turnaround_time = 0;
    queue<Process> queue1, queue2, queue3;


    while (!processes.empty() || !queue1.empty() || !queue2.empty() || !queue3.empty()) {
        while (!processes.empty() && processes[0].arrival_time <= current_time) {
            queue1.push(processes[0]);
            processes.erase(processes.begin());
        }

        if (!queue1.empty()) {
            Process current_process = queue1.front();
            queue1.pop();

            if (current_process.remaining_time <= quantum1) {
                total_waiting_time += current_time - current_process.arrival_time;
                total_turnaround_time += current_time + current_process.remaining_time - current_process.arrival_time;
                current_time += current_process.remaining_time;
                current_process.remaining_time = 0;
                queue3.push(current_process);
            }
            else {
                current_process.remaining_time -= quantum1;
                current_time += quantum1;
                queue2.push(current_process);
            }
        }
        else if (!queue2.empty()) {
            Process current_process = queue2.front();
            queue2.pop();

            if (current_process.remaining_time <= quantum2) {
                total_waiting_time += current_time - current_process.arrival_time;
                total_turnaround_time += current_time + current_process.remaining_time - current_process.arrival_time;
                current_time += current_process.remaining_time;
                current_process.remaining_time = 0;
                queue3.push(current_process);
            }
            else {
                current_process.remaining_time -= quantum2;
                current_time += quantum2;
                current_process.priority++;
                queue3.push(current_process);
            }
        }
        else if (!queue3.empty()) {
            Process current_process = queue3.front();
            queue3.pop();

            total_waiting_time += current_time - current_process.arrival_time;
            total_turnaround_time += current_time + current_process.remaining_time - current_process.arrival_time;
            current_time += current_process.remaining_time;
            current_process.remaining_time = 0;
        }
        else {
            current_time = processes[0].arrival_time;
        }

        for (int i = 0; i < processes.size(); i++) {
            if (processes[i].arrival_time <= current_time) {
                queue1.push(processes[i]);
                processes.erase(processes.begin() + i);
                i--;
            }
        }
    }
    double avg_turnaround_time = (double) total_turnaround_time / n;
    cout << "Average Turnaround Time: " << avg_turnaround_time << endl;
}

int main() {
    vector<Process> processes = {
        {1, 0, 3, 3, 0},
        {2, 2, 6, 6, 0},
        {3, 4, 4, 4, 0},
        {4, 6, 5, 5, 0},
        {5, 8, 2, 2, 0}
    };

    int quantum1 = 2;
    int quantum2 = 0;

    calculateFB(processes, quantum1, quantum2);

    return 0;
}