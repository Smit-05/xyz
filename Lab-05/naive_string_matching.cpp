#include <bits/stdc++.h>
using namespace std;

vector<int> naiveApproach(string &text,string &pattern){
    int n = text.size();
    int m = pattern.size();
    if(n<m) return {};
    vector<int> ans;
    for(int t=0;t<=n-m;t++){
        bool is_matched = true;
        for(int p=0;p<m;p++){
            if(text[t+p]!=pattern[p]){
                is_matched = false;
                break;
            }
        }
        if(is_matched){
            ans.push_back(t+1);
        }
    }
    return ans;
}

int main(){
    string text,pattern;
    getline(cin,text);
    getline(cin,pattern);
    // cin>>text>>pattern;
    vector<int> indexs = naiveApproach(text,pattern);
    for(int i : indexs){
        cout<<"pattern match at : "<<i<<"\n";
    }
    return 0;
}