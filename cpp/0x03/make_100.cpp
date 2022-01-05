#include <bits/stdc++.h>
using namespace std;

int func2(int arr[], int len){
    int occr[101];
    fill(occr, occr+101, 0);
    for (int i=0;i<len;i++){
        if (occr[100-arr[i]]) {
            return 1;
        }
        occr[arr[i]]=1;
    }

    return 0;
}

int main(){  
    int arr1[]={1,52,48};
    int arr2[] ={50, 42};
    cout<<func2(arr1,3)<<'\n';
    cout<<func2(arr2,3)<<'\n';
}