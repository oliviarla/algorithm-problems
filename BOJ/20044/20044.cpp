#include <iostream>
#include <algorithm>
using namespace std;

typedef long long ll;
int main(){
    ll n, min=200000, team;
    cin>>n;
    ll *arr = new ll[2*n];
    for(ll i=0;i<2*n;i++){
        cin>>arr[i];
    }
    sort(arr, arr+2*n);
    for(ll i=0;i<n;i++){
        team = arr[i] + arr[2*n-1-i];
        min = team<min?team:min;
    }
    cout<<min;
}