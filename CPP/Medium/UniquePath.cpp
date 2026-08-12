#include<iostream>
#include<vector>
#include<numeric>
using namespace std;

int solve(int i,int j,int m, int n, vector<vector<int>>&memo){
    if(i>=m || j>=n) return 0;
    if(i==m-1 && j==n-1) return 1;
    if(memo[i][j]!=-1){
        return memo[i][j];
    }else{
        return memo[i][j] = solve(i+1,j,m,n,memo) + solve(i,j+1,m,n,memo);
    }
}

int UniquePath(int m, int n){
    vector<vector<int>>memo(m,vector<int>(n,-1));
    return solve(0,0,m,n,memo);
}

int main(){
    int m=3,n=3;
    cout<<UniquePath(m,n)<<endl;
    return 0;
}






