#include<iostream>
#include<vector>
using namespace std;

void goodDayToRobBank(vector<int>&nums, int time){
    int n = nums.size();
    vector<int> pre(n);
    vector<int> suf(n);
    int cnt=0;
    for(int i=1; i<n; i++){
        if(nums[i]<=nums[i-1]){
            cnt++;
        }else{
            cnt=0;
        }
        pre[i] = cnt;
    }
    for(int i=n-2; i>=0; i--){
        if(nums[i]<=nums[i+1]){
            cnt++;
        }else{
            cnt=0;
        }
        suf[i] = cnt;
    }
    for(int i=0; i<n; i++){
        if(pre[i]>=time && suf[i]>=time){
            cout<<i<<" ";
        }
    }
}
int main(){
    vector<int> nums = {5,3,3,3,5,6,2};
    goodDayToRobBank(nums,2);
    return 0;
}