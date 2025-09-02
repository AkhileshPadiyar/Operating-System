#include<bits/stdc++.h>
using namespace std;

typedef struct process{
    int pid;
    int at;
    int bt;
    int priority;
    bool flag;
    int TAT;
    int WT;

    process(int pid, int at, int bt, int priority, bool flag) {
        this -> pid = pid;
        this -> at = at;
        this -> bt = bt;
        this -> priority = priority;
        this -> flag = flag;
    }
}process;



void push(process * val, vector<process *> &pq) {
    pq.push_back(val);
    int i = pq.size() - 1;
    while(i > 0) {
        int parent = (i - 1) / 2;
        if(pq[parent] -> priority < pq[i] -> priority) {
            swap(pq[parent], pq[i]);
            i = parent;
        }
        else if(pq[parent] -> priority > pq[i] -> priority) {
            break;
        }
        else {
            if(pq[parent] -> at > pq[i] -> at) {
                swap(pq[parent], pq[i]);
                i = parent;
            }
        }
    }
    return;
}



int main() {
    int n;
    printf("Enter the number of process: ");
    cin >> n;
    vector<process*>p(n);
    for(int i = 0; i < n; i++) {
        int at, bt, priority;
        bool flag;
        printf("Enter process %d's AT, BT, Priority, Flag: ", i + 1);
        cin >> at >> bt >> priority >> flag;
        p[i] = new process(i + 1, at, bt, priority, flag);
    }
    int Timer = 0;
    int completedProcess = 0;
    while(completedProcess < n) {
        vector<process*> pq;
        for(int i = 0; i < n; i++) {
            if(p[i] -> at <= Timer && p[i] -> flag) {
                push(p[i], pq);
            }
        }
        if(pq.empty()) {
            Timer++;
            continue;
        }
        process * currProcess = pq[0];
        Timer += currProcess -> bt;
        currProcess -> TAT = Timer - currProcess -> at;
        currProcess -> WT = currProcess -> TAT - currProcess -> bt;
        currProcess -> flag = false;
        completedProcess++;

    }

    double AvgTAT = 0.0, AvgWT = 0.0;
    for(int i = 0; i < n; i++) {
        AvgTAT += p[i] -> TAT;
        AvgWT += p[i] -> WT;
    }
    AvgTAT /= n;
    AvgWT /= n;
    double TP = 1.0 * n / Timer;
    printf("Average TurnAround time: %.2lf, Average Waiting Time: %.2lf, Throughput: %.2lf\n", AvgTAT, AvgWT, TP);
    return 0;
}