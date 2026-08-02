#include<bits/stdc++.h>
using namespace std;

void mergeSortedArray(vector<int>&nums1, vector<int>nums2, int m, int n){
    int i=m-1;
    int j=n-1;
    int x = nums1.size()-1;
    while(i>=0 && j>=0){
        if(nums1[i]<nums2[j]){
            nums1[x] = nums2[j];
            x--,j--;
        }
        else {
            nums1[x] = nums1[i];
            x--,i--;
        }
    }
    while(j>=0){
        nums1[x] = nums2[j];
        x--,j--; 
    }

    for(int i=0; i<nums1.size(); i++){
        cout<<nums1[i]<<" ";
    }
    cout<<endl;
}

int main(){
    int m=3,n=3;
    vector<int> nums1= {1,2,3,0,0,0};
    vector<int> nums2 = {2,5,6};
    mergeSortedArray(nums1,nums2,m,n);
    return 0;
}