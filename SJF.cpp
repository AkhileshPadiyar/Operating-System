#include<iostream>
#include<vector>
using namespace std;

typedef struct process {
	int pid;
	int at;
	int bt;
	float tat;
	float wt;

	process(int pid, int bt) {
		this->pid = pid;
		this -> bt = bt;
		this -> at = 0;
	}
	
	process(int pid, int at, int bt) {
		this -> pid = pid;
		this -> at = at;
		this -> bt = bt;
	}

	void setTAT(int total_time) {
		this -> tat = total_time - this -> at;
		this -> wt = this -> tat - this -> bt;
	}
	
	float getTAT() {
		return this -> tat;
	}

	float getWT() {
		return this -> wt;
	}
}process;

void sorted(vector<process *> &arr) {
    int n = arr.size();
    for(int i = 0; i < n; i++) {
        for(int j = i + 1; j < n; j++) {
            process * temp = arr[i];
            process * temp2 = arr[j];
            if(temp -> at > temp2 -> at) {
                swap(arr[i], arr[j]);
            }
            else if(temp -> at < temp2 -> at)
                continue;
            else {
                if(temp -> bt > temp2 -> bt)
                    swap(arr[i], arr[j]);
            }
        }
    }
}

void printProcesses(vector<process *> &arr) {
    printf("After sorting\n");
    for(int i = 0; i < arr.size(); i++) {
        printf("PID: %d, Arrival Time %d, BurstTime %d\n",arr[i]-> pid, arr[i]->at, arr[i]->bt);
    }
    cout << endl;
    return;
}

int main() {
	int n;
	printf("Enter the number of process: ");
	cin >> n;
	vector<process *> arr(n);
	for(int i = 0; i < n; i++) {
		int pid, at, bt;
		printf("Enter pid, Arrival Time, Bursttime: ");
		cin >> pid >> at >> bt;
		arr[i] = new process(pid, at, bt);
	}
	
	for(int i = 0; i < n; i++) {
	    printf("PID: %d, BurstTime: %d \n", arr[i] -> pid, arr[i] -> bt);
	}
	sorted(arr);
	printProcesses(arr);
	
	int total_time = 0;
	for(int i = 0; i < n; i++) {
	    process *temp = arr[i];
	    total_time += temp -> bt;
	    temp -> setTAT(total_time);
	}
	float TAT = 0, AWT = 0;
	for(int i = 0; i < n; i++) {
	    process *temp = arr[i];
	    TAT += temp -> getTAT();
	    AWT += temp -> getWT();
	}
	TAT /= n;
	AWT /= n;
	printf("Average Turnaround Time: %f, Average Waiting Time %f\n", TAT, AWT);
}
