#include<iostream>
#include<vector>
using namespace std;
void merge(vector<int> &arr,int left,int mid , int right){
    vector<int> temp;
    int arr1ptr=left;
    int arr2ptr=mid+1;
    while(arr1ptr<=mid && arr2ptr<=right){
        if(arr[arr1ptr]<arr[arr2ptr]){
            temp.push_back(arr[arr1ptr]);
            arr1ptr++;
        }
        else{
            temp.push_back(arr[arr2ptr]);
            arr2ptr++;
        }
    }
        //leftover
        while(arr1ptr<=mid){
            temp.push_back(arr[arr1ptr]);
            arr1ptr++;
        }
        while(arr2ptr<=right){
            temp.push_back(arr[arr2ptr]);
            arr2ptr++;
        }
        //transfer
        for(int i=left;i<=right;i++){
            arr[i]=temp[i-left];
        }
}

void mergeSort(vector<int> &arr , int left , int right){
    if (left>=right)return;
    int mid=(left+right)/2;
    mergeSort(arr,left,mid);
    mergeSort(arr,mid+1,right);
    merge(arr,left,mid,right);
}


int main(){
    vector<int> check={2,5,7,9,1,10};

return 0;}