// Sum of subset problem using 0/1 knapsack solution

#include <bits/stdc++.h>
using namespace std;

void sumOfSubset(vector<int> &s,int n,int target){
    // here s is equal to profit and weight array, so profit = weight = s
    vector<vector<int>> dp(n+1,vector<int>(target+1,0));
    for(int i=0;i<n+1;i++) dp[0][i];
    for(int i=0;i<n+1;i++) dp[i][0];

    for(int i=1;i<n+1;i++){
        for(int j=1;j<target+1;j++){
            if(s[i-1]<=j){
                dp[i][j] = max(dp[i-1][j],s[i-1]+dp[i-1][j-s[i-1]]);
            }else{
                dp[i][j] = dp[i-1][j];
            }
        }
    }
    // DP Table
    cout<<"DP Table :- ";
    for(int i=0;i<n+1;i++){
        for(int j=0;j<target+1;j++){
            cout<<dp[i][j]<<" ";
        }
        cout<<endl;
    }
    
    vector<int> solution(n,0);
    int i=n,j=target;
    while(0<i && 0<j){
        if(dp[i][j]!=dp[i-1][j]){
            solution[i-1] = 1;
            j -= s[i-1];
        }
        i--;
    }
    cout<<"Solution :- ";
    for(int e : solution){
        cout<<e<<" ";
    }
    // cout<<dp[n][target]<<endl;
}

int main(){
    int n,target;
    cin>>n>>target;
    vector<int> s(n);
    for(int i=0;i<n;i++){
        cin>>s[i];
    }
    sumOfSubset(s,n,target);
    return 0;
}