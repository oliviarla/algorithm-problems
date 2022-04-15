#include <bits/stdc++.h>
using namespace std;

int n=10;
int arr[1000001]={2, 5, 1, 12, 45, 3, 76, 37, 26, 67};
void quick_sort(int st, int en){
    if(en<=st+1) return;
    int pivot = st;
    int l = st+1, r=en-1;
    while(1){
        while(l<=r && arr[l]<=arr[pivot]) l++;
        while(l<=r && arr[r]>=arr[pivot]) r--;
        if(l>r) break;
        swap(arr[l], arr[r]);
    }
    swap(arr[r], arr[st]);
    quick_sort(st, r);
    quick_sort(r+1, en);
}

int main(void){
    quick_sort(0, n);
    for(int i=0;i<n;i++) cout<<arr[i]<<" ";
}