#include <bits/stdc++.h>
using namespace std;

int partition(vector<int> &arr, int left, int right)
{
    int x = arr[right]; // pivot
    int i = left - 1, j;
    for (int j = left; j < right; j++){
        if (arr[j] <= x){
            i++;
            swap(arr[j], arr[i]);
        }
    }
    swap(arr[i + 1], arr[right]);
    return i + 1;
}

int randomizedPartition(vector<int> &num,int left, int right){
    srand(time(NULL));
    int random_num = left + (rand() % (right - left + 1));
    swap(num[random_num], num[right]);
    return partition(num, left, right);
}

int findKthSmallest(vector<int> &num, int k, int left, int right)
{
    int pos = randomizedPartition(num, left, right);
    int a_size = pos - left;
    if (a_size == k - 1)
        return num[pos];
    else if (a_size < k - 1)
        return findKthSmallest(num, k - (a_size + 1), pos + 1, right);

    return findKthSmallest(num, k, left, pos - 1);
}

int main()
{
    int n = 7;
    // cin>>n;
    vector<int> num = {10,15,-14,13,-19,56,78};
    // for(int i=0;i<n;i++){
    //     cin>>num[i];
    // }
    int kth;
    cin >> kth;
    int kth_smallest = findKthSmallest(num, kth, 0, n - 1);
    cout << "Kth smallest element :- " << kth_smallest;
    return 0;
}