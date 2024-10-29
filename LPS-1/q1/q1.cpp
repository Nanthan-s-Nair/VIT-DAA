#include<iostream>
#include<vector>
using namespace std;
void insertionsort(vector<int>& vec){
    int n=vec.size();
    for(int i=2;i<n;i++){
        int key=vec[i];
        int j=i-1;
        while(j>=0 && key<vec[j]){
            vec[j+1]=vec[j];
            --j;
        }
        vec[j+1]=key;
    }
}
int main(){
    printf("Enter the number of numbers n \n");
    int n;
    char value;
    cin>>n;
    vector<int> vec;
    for(int i=0;i<n;i++){
        cin>>value;
        vec.push_back(value);
    }
    insertionsort(vec);
    printf("Sorted alphabets \n");
    for(int i=0;i<n;i++){
        cout<<char(vec[i])<<'\n';
    }
    
return 0;}

