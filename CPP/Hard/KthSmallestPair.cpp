#include<bits/stdc++.h>
using namespace std;

int smallestDistancePair(vector<int>arr,int k){
    sort(arr.begin(), arr.end());
    int n = arr.size();

    int l=0;
    int r = arr[n-1] - arr[0];

    while(l<r){
        int mid = l+(r-l)/2;
        int cnt = 0;
        for(int i=0, j=0; i<n; i++){
            while(j<n && arr[j]-arr[i]<=mid){
                j++;
            }
            cnt += j-i-1;
        }
        if(cnt<k){
            l=mid+1;
        }else {
            r = mid;
        }
    }
    return l;
}

int main(){
    vector<int> arr = {1,6,1};
    cout<<(smallestDistancePair(arr,3));
    return 0;
}