#include<bits/stdc++.h>
using namespace std;

    unordered_map<int,bool> memo;

     bool helper(vector<int>&nums, int i){
        if(i==nums.size()-1) return true;
        if(i>=nums.size()-1) return false;
        if(memo.find(i)!=memo.end()){
            return false;
        }
        bool res = false;
        for(int j=1; j<=nums[i]; j++){
            res = helper(nums,i+j);
            if(res) return true;
        }
        memo.insert({i,false});
        return false;
    }
    
    // bool jumpGame(vector<int> &nums){
    //     return helper(nums,0);
    // }
    int main(){
        vector<int> nums = {2,3,1,1,4};
        cout<<(helper(nums,0))<<endl;
    }

