#include<iostream>
#include<vector>

using namespace std;

void insertionSortAsc(vector<int>&vec){
    int n=vec.size();
    for(int i=1;i<n;i++){
        int key=vec[i];
        int j=i-1;
        while(j>=0 && key<vec[j]){
            vec[j+1]=vec[j];
            j--;
        }
        vec[j+1]=key;
    }
}

void insertionSortDesc(vector<int>&vec){
    int n=vec.size();
    for(int i=1;i<n;i++){
        int key=vec[i];
        int j=i-1;
        while(j>=0 && key>vec[j]){
            vec[j+1]=vec[j];
            j--;
        }
        vec[j+1]=key;
    }
}

int main(){
    int n;
    cin>>n;
    int value;
    vector<int> pos;
    vector<int> neg;
    for(int i=0;i<n;i++){
        cin>>value;
        if(value>=0){
            pos.push_back(value);
        }
        else{
            neg.push_back(value);
        }
    }
    insertionSortDesc(neg);
    insertionSortAsc(pos);
    neg.insert(neg.end(),pos.begin(),pos.end());
    for(int i=0;i<n;i++){
        cout<<neg[i]<<'\n';
    }

return 0;}