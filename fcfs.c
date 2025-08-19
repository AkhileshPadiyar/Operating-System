#include<stdio.h>
#include<stdlib.h>

typedef struct process{
int PID;
int AT;
int BT;
int CT;
int TAT;
int WT;
}sl;

void sort(sl* arr[], int n) {
	for(int i = 0; i < 5; i++) {
		for(int j = 0; j < 5 - i - 1; j++) {
			if(arr[j] -> AT > arr[j + 1] -> AT) {
				sl* temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
			}
		}
	}
}

int main() {
sl* arr[5];
for(int i = 0; i < 5; i++) {
	int pid, at, bt;
	printf("Enter PID, arrival Time and Burst Time: ");
	scanf("%d%d%d",&pid, &at, &bt);
	sl* temp = (sl*)malloc(sizeof(sl));
	temp->PID = pid;
	temp->AT = at;
	temp->BT = bt;
	arr[i] = temp;
}
sort(arr, 5);

double total_time = 0;
for(int i = 0; i < 5; i++) {
	total_time = arr[i] -> BT + total_time;
	arr[i] -> CT = total_time;
	arr[i] -> TAT = total_time - arr[i] -> AT;
	arr[i] -> WT = arr[i] -> TAT - arr[i] -> BT;
}
double AWT = 0, ATT = 0, TP = 0;
for(int i = 0; i < 5; i++) {
	printf("PID: %d, Completion Time: %d, Turn around Time: %d, Waiting Time: %d\n",arr[i]->PID, arr[i]->CT, arr[i]->TAT, arr[i]->WT);
	AWT += arr[i] -> WT;
	ATT += arr[i] -> TAT;
}

AWT = AWT / 5;
ATT = ATT / 5;
TP = total_time / 5;
printf("Avg. Waiting Time : %lf, Avg. Turnaroud time : %lf, ThroughtPut Time %lf \n", AWT, ATT, TP);
return 0;
}
