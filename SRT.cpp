
#include <bits/stdc++.h> 
using namespace std; 

struct Process { 
	int pid; 
	int bt; 
	int art; 
}; 
 
void calculateSRT(Process proc[],int arriv[],int burst[], int n) 
{ 
	int wt[n], tat[n], total_wt = 0, total_tat = 0; 
	int rt[n]; 
    double total_processing_time;
    for (int i = 0; i < n; i++ ) {
		proc[i].pid = i+1;
		proc[i].art = arriv[i];
		proc[i].bt = burst[i];
	}
	for (int i = 0; i < n; i++) 
		rt[i] = proc[i].bt; 

	int complete = 0, t = 0, minm = INT_MAX; 
	int shortest = 0, finish_time; 
	bool check = false; 

	while (complete != n) { 
		for (int j = 0; j < n; j++) { 
			if ((proc[j].art <= t) && 
			(rt[j] < minm) && rt[j] > 0) { 
				minm = rt[j]; 
				shortest = j; 
				check = true; 
			} 
		} 

		if (check == false) { 
			t++; 
			continue; 
		} 
		rt[shortest]--; 
		minm = rt[shortest]; 
		if (minm == 0) 
			minm = INT_MAX; 
		if (rt[shortest] == 0) { 
			complete++; 
			check = false; 
			finish_time = t + 1; 
			wt[shortest] = finish_time - 
						proc[shortest].bt - 
						proc[shortest].art; 

			if (wt[shortest] < 0) 
				wt[shortest] = 0; 
		} 
		t++; 
	}
    for (int i = 0; i < n; i++) 
		tat[i] = proc[i].bt + wt[i]; 

	for (int i = 0; i < n; i++) { 
		total_tat = total_tat + tat[i]; 
        total_processing_time += double(tat[i]) / proc[i].bt;
	} 
    cout << "Average processing time: " << total_processing_time / n ;
	cout << "\nAverage turn around time = "<< (float)total_tat / (float)n; 
} 

// Driver code 
int main() 
{ 
    int n = 5;
	Process p[n];
    int arriv[] = { 0, 2, 4, 6, 8 };
	int burst[] = { 3, 6, 4, 5, 2 };
    calculateSRT(p,arriv,burst,n);
	return 0; 
} 
