#include <iostream>
using namespace std;
int merge(int *arr, int s, int mid, int e){
    int i = s;
    int j = mid+1;
    int k = s;
    int inv = 0;
    int temp[100];
    for(i = s;i<=mid;i++){
        while(j<=e && arr[i] > 2*arr[j]){
            j++;
        }
        inv += (j - (mid + 1));
    }
    i = s;
    j = mid+1;
    while(i<=mid && j<=e){
        if(arr[i] <= arr[j])
            temp[k++] = arr[i++];
        else{
            temp[k++] = arr[j++];
           // inv+= mid-i+1;
        }
    }
    while(i<=mid){
        temp[k++] = arr[i++];
    }
    while(j<=e){
        temp[k++] = arr[j++];
    }
    for(int i =s;i<=e;i++){
         arr[i] = temp[i];
    }
    return inv;
}
int mergesort(int *arr, int s, int e){
    if(s>=e) return 0 ;
    int mid = (s+e)/2;
  int inv =  mergesort(arr, s, mid);
    inv +=mergesort(arr, mid+1, e);
    inv +=merge(arr,s,mid,e);
    return inv;
}
int main() {
    int arr[] = {40, 25,19,12,9,6,2};
    int n = sizeof(arr)/sizeof(int);
   int ans =  mergesort(arr,0,n-1);
    // for(int i =0;i<n;i++)
    //     cout<<arr[i]<<" ";
    // cout<<"\n";
    cout<<ans<<"\n";
    return 0;
}
