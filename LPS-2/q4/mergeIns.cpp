#include <iostream>
using namespace std;
void merge(float arr[],int l,int m,int r) {
    int i=l;
    int j=m+1;
    int k=0;
    float temp[r-l+1];
    while (i<=m&&j<=r) {
        if (arr[i]<=arr[j]) {
            temp[k]=arr[i];
            i++;
        } else {
            temp[k]=arr[j];
            j++;
        }
        k++;
    }
    while (i<=m) {
        temp[k]=arr[i];
        i++;
        k++;
    }
    while (j<=r) {
        temp[k]=arr[j];
        j++;
        k++;
    }
    for (int p=0;p<k;p++) {
        arr[l+p]=temp[p];
    }
}
void merges(float arr[],int l,int r) {
    if (l<r) {
        int m=(l+r)/2;
        merges(arr,l,m);
        merges(arr,m+1,r);
        merge(arr,l,m,r);
    }
}
void ins(float arr[],int m,int r) {
    for (int i=m+1;i<=r;i++) {
        float tmp=arr[i];
        int j=i-1;
        while (j>=m&&arr[j]>tmp) {
            arr[j+1]=arr[j];
            j--;
        }
        arr[j+1]=tmp;
    }
}
int main() {
    int n=0;
    cin>>n;
    float arr[n];
    for (int i=0;i<n;i++) {
        cin>>arr[i];
    }
    int l=0;
    int r=n-1;
    int m=(l+r)/2;
    merges(arr,l,m);
    ins(arr,m+1,r);
    merge(arr,l,m,r);
    for (int i=0;i<n;i++) {
        cout<<arr[i]<<endl;
    }
    return 0;
}