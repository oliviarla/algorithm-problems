#include <bits/stdc++.h>
using namespace std;

int lc[30];
int rc[30];

void preorder(int cur){
    cout<< char(cur-1+'A');
    if(lc[cur]!=0) preorder(lc[cur]);
    if(rc[cur]!=0) preorder(rc[cur]);
}

void inorder(int cur){
    if(lc[cur]!=0) inorder(lc[cur]);
    cout<< char(cur-1+'A');
    if(rc[cur]!=0) inorder(rc[cur]);
}

void postorder(int cur){
    if(lc[cur]!=0) postorder(lc[cur]);
    if(rc[cur]!=0) postorder(rc[cur]);
    cout<< char(cur-1+'A');
}


int main(void){
    int n;
    cin>>n;

    for(int i=0;i<n;i++){
        char p,l,r;
        cin>>p>>l>>r;
        p = p-'A'+1;
        if(l!='.') lc[p]=l-'A'+1;
        else lc[p]=0;
        if(r!='.') rc[p]=r-'A'+1;
        else rc[p]=0;
    }

    preorder(1);
    cout<<'\n';
    inorder(1);
    cout<<'\n';
    postorder(1);
}