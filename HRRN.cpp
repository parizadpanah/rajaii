// C++ program for Highest Response Ratio Next (HRRN)
// Scheduling
#include <bits/stdc++.h>
using namespace std;
struct process {
	int name;
	int at;
    int bt;
    int ct=0, wt=0, tt=0;
	int completed;
	float ntt;
} p[5];

void calculateHRRN(int arriv[],int burst[] , int n){
    int i, j, sum_bt = 0;
	float t;
    int total_Turnaround_Time = 0;
    double total_processing_time = 0;
    for (i = 0; i < n; i++ ) {
		p[i].name = i+1;
		p[i].at = arriv[i];
		p[i].bt = burst[i];
		p[i].completed = 0;
		sum_bt += p[i].bt;
	}
	for (t = p[0].at; t < sum_bt;) {
		float hrr = -9999;
		float temp;
		int loc;
		for (i = 0; i < n; i++) {
			if (p[i].at <= t && p[i].completed != 1) {

				temp = (p[i].bt + (t - p[i].at)) / p[i].bt;

				if (hrr < temp) {
					hrr = temp;
					loc = i;
				}
			}
		}

		t += p[loc].bt;
		p[loc].wt = t - p[loc].at - p[loc].bt;
		p[loc].tt = t - p[loc].at;
		p[loc].ntt = ((float)p[loc].tt / p[loc].bt);
		p[loc].completed = 1;
        total_Turnaround_Time += p[loc].tt;
        total_processing_time += p[loc].ntt;
	}
	
	cout << "Average processing time: " << total_processing_time/n << endl;
    cout << "Average turnaround time: " << double(total_Turnaround_Time )/n<< endl;
}
int main()
{
	int arriv[] = { 0, 2, 4, 6, 8 };
	int burst[] = { 3, 6, 4, 5, 2 };
    calculateHRRN(arriv,burst,5);
}
