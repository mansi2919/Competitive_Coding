#include <bits/stdc++.h>
using namespace std;
int maxContiguousSum(int *arr, int n){
    int max_so_far = INT_MIN;
    int max_ending_here = 0;
    for(int i =0;i<n;i++){
        max_ending_here += arr[i];
        if(max_ending_here > max_so_far)
            max_so_far = max_ending_here;
        if(max_ending_here < 0)
            max_ending_here = 0;
    }
    return max_so_far;
}
int main() {
    int arr[] = {-12,-45,-67,-34,-23};
    int n = sizeof(arr)/sizeof(int);
    int ans = maxContiguousSum(arr,n);
    cout<<ans<<endl;
    return 0;
}
