#include <iostream>
#include<vector>
using namespace std;
void merge(int *arr, int s, int mid, int e){
    int i = s;
    int j = mid+1;
    int k = s;
    vector<int>temp;
   // int temp[100];
    while(i<=mid && j<=e){
        if(arr[i] <= arr[j]){
            temp.push_back(arr[i]); 
            //temp[k++] = arr[i];
            i++;
        }
        else{
            temp.push_back(arr[j]);
            //temp[k++] = arr[j];
            j++;
        }
    }
    while(i<=mid){
        temp.push_back(arr[i]);
        //temp[k++] = arr[i];
        i++;
    }
    while(j<=e){
        temp.push_back(arr[j]);
        //temp[k++] = arr[j];
        j++;
    }
    for(int i= s;i<=e;i++){
        arr[i] = temp[i-s];
    }
}
void mergesort(int *arr, int s, int e){
    if(s >=e ) return ;
    int mid = (s+e)/2;
    mergesort(arr,s,mid);
    mergesort(arr,mid+1,e);
    merge(arr,s,mid,e);
}
int main() {
    int arr[] = {221,22,3,42,5};
    int n = sizeof(arr)/sizeof(int);
    mergesort(arr,0,n-1);
    for(int i =0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    return 0;
}
