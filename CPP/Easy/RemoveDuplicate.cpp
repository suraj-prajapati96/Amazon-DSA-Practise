#include<iostream>
#include<vector>
using namespace std;

int removeDuplicate(vector<int>&nums){
    int i=nums[i];
    for(int j=1; j<nums.size(); j++){
        if(nums[i] < nums[j]){
            int temp = nums[i+1];
            nums[i+1] = nums[j];
            nums[j] = temp;
            i++;
        }
    }
    return i+1;
}

int main(){
    vector<int> nums = {0,1,1,1,2,2,3};
    cout<<removeDuplicate(nums)<<endl;
    return 0;
}