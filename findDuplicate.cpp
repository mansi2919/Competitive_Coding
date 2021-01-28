#include<iostream>
using namespace std;
int main(){
    int arr[] = {4,3,2,3,1};
    int n = sizeof(arr)/sizeof(int);
    int slow = arr[0];
    int fast = arr[0];
    do {
        slow = arr[slow];
        fast = arr[arr[fast]];
    }while(slow!=fast);
    fast = arr[0];
    while(slow!=fast){
        slow = arr[slow];
        fast = arr[fast];
    }
    cout<<slow;
    return 0;
}