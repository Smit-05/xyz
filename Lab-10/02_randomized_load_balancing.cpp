#include <bits/stdc++.h>
using namespace std;

void balanceLoads(vector<int> &loads,int jobs,int machine){
    vector<vector<int>> machines(machine);
    vector<int> machine_loads(machine,0);
    srand(NULL);
    for(int i=0;i<jobs;i++){
        int m = rand()%m;
        machine_loads[m] += jobs[i];
        machines[m].push_back(i);
    }
    
    cout<<"loads on each machine :"<<endl;
    for(int i=0;i<machine;i++){
        cout<<"load = "<<machine_loads[i]<<" => jobs : ";
        for(int j : machines[i]){
            cout<<j<<" ";
        }
        cout<<endl;
    }
}

int main(){
    int jobs,machine;
    cin>>jobs>>machine;
    vector<int> loads(jobs);
    for(int i=0;i<jobs;i++)
        cin>>loads[i];

    balanceLoads(loads,jobs,machine);
    return 0;
}

// input:
// 6 3
// 5 4 3 6 1 7

// output :
// loads on each machine :
// load = 7 => jobs : 1 2 
// load = 6 => jobs : 3 
// load = 13 => jobs : 0 4 5 
