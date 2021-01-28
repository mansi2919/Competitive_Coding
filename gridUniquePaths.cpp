#include<iostream>
#include<vector>
using namespace std;
// grid unique path
// recursive solution
int countPaths(int i, int j, int m, int n){
    if(i==m-1 && j==n-1)
        return 1;
    if(i >= m || j>=n)
        return 0;
    return countPaths(i+1,j,m,n) + countPaths(i,j+1,m,n);
}
// DP solution
int countDP(int i, int j, int m,int n, vector<vector<int>> &dp){
    if(i==m-1 && j==n-1)
        return 1;
    if(i>=m || j>=n)
        return 0;
    if(dp[i][j]!=-1) return dp[i][j];
    return dp[i][j] = countDP(i+1,j,m,n,dp) + countDP(i,j+1,m,n,dp);
}
//Combinatorics Solution
int count(int i, int j, int m, int n){
    int N = m+n-2;
    int r = m-1;
    int ans = 1;
    for(int i=1;i<=r;i++){
        ans = ans * (N - r + 1)/ i;
    }
    return ans;
}
int main(){
    int ans = countPaths(0,0,2,3);
    cout<<ans<<endl;
    vector<vector<int>>v(2,vector<int> (3, -1));
    ans = countDP(0,0,2,3,v);
    cout<<ans<<endl;
    ans = count(0,0,2,3);
    cout<<ans<<endl;
    return 0;
}