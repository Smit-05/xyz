#include <iostream>
using namespace std;

long long int iterativeGcd(long long int num1,long long int num2){
    while(0!=num2){
        long long int rem = num1%num2;
        num1 = num2;
        num2 = rem;
    }
    return num1;
}


int main() {
    long long int n1,n2;
    cin>>n1>>n2;
	cout<<iterativeGcd(n1,n2);
	return 0;
}