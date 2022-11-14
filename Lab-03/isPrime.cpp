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
    if(base>mod)
        base %= mod;
        
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

long long int gcd(long long int num1,long long int num2){
    if(0==num2) return num1;
    return gcd(num2,num1%num2);
}

long long int iterativeGcd(long long int num1,long long int num2){
    while(0!=num2){
        long long int rem = num1%num2;
        num1 = num2;
        num2 = rem;
    }
    return num1;
}

// O(k*log(number))
bool isPrime(long long int number,long long int k,long long int mod){
    srand(time(NULL));
    while(0<k){
        long long int a = 2+(rand()%(number-3));
        
        if(1!=iterativeGcd(a,number))
            return false;
        long long temp = power(a,mod-1,mod);
        if(1!=temp)
            return false;
        k--;
    }
    return true;
}

int main() {
    long long int num,k,mod;
    mod = 1000000007;
    cin>>num>>k>>mod;
    if(isPrime(num,k,mod)){
        cout<<"Given Number is Probably Prime!!"<<endl;
    }else{
        cout<<"Given Number is Not Prime!!"<<endl;
    }
}