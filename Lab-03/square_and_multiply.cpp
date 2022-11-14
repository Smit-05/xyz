#include <bits/stdc++.h>
using namespace std;


vector<bool> decimalToBinary(long long int num){
    vector<bool> ans;
    while(0<num){
        ans.push_back(1&num);
        num >>= 1;
    }
    return ans;
}

long long int power(long long int base,long long int exponent,long long int mod){
    long long ans = 1;
    auto bin = decimalToBinary(exponent);
    int len = bin.size();
    for(int i=len-1;0<=i;i--){
        ans = ((ans%mod)*(ans%mod))%mod;
        if(true==bin[i]){
            ans = ((ans%mod)*(base%mod))%mod;
        }
    }
    return ans;
}

int main() {
	long long int base,expo,mod;
	mod = 1000000007;
	cin>>base>>expo;
	
	long long int ans = power(base,expo,mod);
	cout<<ans;
}