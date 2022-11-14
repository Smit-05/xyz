#include <bits/stdc++.h>
using namespace std;

int findPattern(string &text,string &pattern){
    int n = text.size();
    int m = pattern.size();
    // preprocessing start
    map<char,int> shiftTable;
    unordered_set<char> chInPattern;
    for(int i=0;pattern.size()-1>i;i++){
        shiftTable[pattern[i]] = m-1-i;
        chInPattern.insert(pattern[i]);
    }
    chInPattern.insert(pattern.back());
    
    // preprocessing end

    int j=0;
    while(j+m<n){
        if(pattern[m-1]==text[j+m-1]){
            int i = m-2;
            while(0<=i && pattern[i]==text[j+i])
                i--;
            if(-1==i)
                return j;
        }
        cout<<j<<" ";
        if(0==shiftTable[text[j+m-1]])
            j += m;
        else
            j += shiftTable[text[j+m-1]];
    }
    return -1;
}
int main(){
    string text,pattern;
    getline(cin,text);
    getline(cin,pattern);
    int index = findPattern(text,pattern);
    if(0>index){
        cout<<"Pattern not found!!"<<endl;
    }else{
        cout<<"Pattern found at "<<index<<"th index"<<endl;
    }
    return 0;
}
