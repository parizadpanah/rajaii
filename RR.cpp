#include <iostream>
#include <bits/stdc++.h>
#include <climits>
using namespace std;

struct Process {
	int AT, BT, ST[20], WT, FT, TAT, pos;
};


void calculateRR(int arriv[],int burst[] , int n, int q){
    int i,j;
    int quant=q;
	Process p[n];
    for (i = 0; i < n; i++ ) {
		p[i].pos = i+1;
        p[i].AT = arriv[i];
        p[i].BT = burst[i];
	}
	int c = n, s[n][20];
	float time = 0, mini = INT_MAX, b[n], a[n];
	int proc = -1;
	for (i = 0; i < n; i++) {
		b[i] = p[i].BT;
		a[i] = p[i].AT;
		for (j = 0; j < 20; j++) {
			s[i][j] = -1;
		}
	}

	int tot_wt, tot_tat;
	tot_wt = 0;
	tot_tat = 0;
	bool flag = false;
    int total_Turnaround_Time = 0;
    double total_processing_time = 0;

	while (c != 0) {
		mini = INT_MAX;
		flag = false;

		for (i = 0; i < n; i++) {
			float p = time + 0.1;
			if (a[i] <= p && mini > a[i] && b[i] > 0) {
				proc = i;
				mini = a[i];
				flag = true;
			}
		}
		if (!flag) {
			time++;
			continue;
		}
		j = 0;

		while (s[proc][j] != -1) {
			j++;
		}

		if (s[proc][j] == -1) {
			s[proc][j] = time;
			p[proc].ST[j] = time;
		}

		if (b[proc] <= quant) {
			time += b[proc];
			b[proc] = 0;
		} else {
			time += quant;
			b[proc] -= quant;
		}

		if (b[proc] > 0) {
			a[proc] = time + 0.1;
		}
		if (b[proc] == 0) {
			c--;
			p[proc].FT = time;
			p[proc].WT = p[proc].FT - p[proc].AT - p[proc].BT;
			tot_wt += p[proc].WT;
			p[proc].TAT = p[proc].BT + p[proc].WT;
			tot_tat += p[proc].TAT;
		}
	} 

	for (i = 0; i < n; i++) {
        total_Turnaround_Time += p[i].TAT;
        total_processing_time += double(p[i].TAT)/p[i].BT;
	}
	cout << "Average processing time: " << double(total_processing_time) / n  << endl;
    cout << "Average turnaround time: " << double(total_Turnaround_Time) / n << endl;
}

int main() {
	int arriv[] = { 0, 2, 4, 6, 8 };
	int burst[] = { 3, 6, 4, 5, 2 };
    calculateRR(arriv,burst,5,1);
}
