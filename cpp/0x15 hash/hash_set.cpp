#include <iostream>

using namespace std;
class HashSet {
    private:
        int set[100];
    public:
        int hashing(int key);
        void insert(int data);
        bool find(int data);
};

int HashSet::hashing(int key) {
    key=key*key;
    key=key/7;
    key=key%65;
    return key;
}

void HashSet::insert(int data) {
    int key=hashing(data);
    set[key]=data;
}

bool HashSet::find(int data) {
    int key=hashing(data);
    if(set[key]==data)
        return true;

    return false;
}

int main() {
    HashSet s;
    s.insert(11);
    s.insert(32);
    s.insert(42);
    s.insert(17);
    s.insert(19);
    
    int target[]={11, 32, 29, 42, 19};
    cout<<"element\texists"<<endl;
    for(int i=0; i<5; i++) {
        int data=target[i];
        cout<<data<<"\t";
        if(s.find(data))
            cout<<"yes"<<endl;
        else 
            cout<<"no"<<endl;
    }
}