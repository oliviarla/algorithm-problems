
#include <iostream>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cout.tie(0);
    int n, x;
    cin>> n >> x;
    int temp;
    for(int i=0;i<n;i++){
        cin>>temp; 
        if(temp<x){
            cout<<temp <<" ";
        }
    }
    return 0;
}
