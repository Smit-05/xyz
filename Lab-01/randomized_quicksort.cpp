#include <bits/stdc++.h>
using namespace std;

int comparision;

int partition(vector<int> &arr,int left,int right){
    
    int x = arr[right]; // pivot
    int i = left-1,j;
    
    for(int j=left;j<right;j++){
        comparision ++;
        if(arr[j]<=x){
            i++;
            swap(arr[j],arr[i]);
        }
    }
    swap(arr[i+1],arr[right]);
    return i+1;
    
}
int randomNumber(vector<int> &arr,int left,int right){
    srand(time(NULL));
    int random_num = left+(rand()%(right-left+1)); // why we are adding left, bcoz rand function will generate number between 0 to right, ans we need to get number between left to right that's why we adding left in to generated random number.

    swap(arr[random_num],arr[right]);
    
    return partition(arr,left,right);
}

void randomizedQuickSort(vector<int> &arr,int left,int right){
    comparision ++;
    if(left<right){
        int pos = randomNumber(arr,left,right);
        randomizedQuickSort(arr,left,pos-1);
        randomizedQuickSort(arr,pos+1,right);
    }
}

int main() {
    comparision = 0;
    int n;
    cin>>n;
    vector<int> arr(n);
    for(int i=0;i<n;i++)
        cin>>arr[i];
        
    randomizedQuickSort(arr,0,n-1);
    
    for(int ai : arr){
        cout<<ai<<" ";
    }
    cout<<endl;
    cout<<"Total Comparision :- "<<comparision;
	return 0;
}