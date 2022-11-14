#include <bits/stdc++.h>
using namespace std;

void balanceLoads(vector<int> &loads,int jobs,int machine){
    vector<vector<int>> machines(machine);
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;

    for(int i=0;i<machine;i++){
        pq.push({0,i});
    }

    for(int j=0;j<jobs;j++){
        auto minLoad = pq.top();
        pq.pop();
        minLoad.first += loads[j];
        machines[minLoad.second].push_back(j);
        pq.push(minLoad);
    }

    cout<<"loads on each machine :"<<endl;
    while(!pq.empty()){
        auto job = pq.top();
        pq.pop();

        cout<<"load = "<<job.first<<" => jobs : ";
        for(int j : machines[job.second]){
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

// input :
// 6 3
// 5 4 3 6 1 7

// output
// loads on each machine :
// load = 5 => jobs : 1 4 
// load = 9 => jobs : 2 3 
// load = 12 => jobs : 0 5 
