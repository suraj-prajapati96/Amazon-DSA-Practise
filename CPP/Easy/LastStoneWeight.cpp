#include<bits/stdc++.h>
using namespace std;

int countStone(vector<int>&arr){
    priority_queue<int> pq(arr.begin(),arr.end());
    while(pq.size()>1){
        int a = pq.top();
        pq.pop();
        int b = pq.top();
        pq.pop();
        if(a!=b){
            pq.push(a-b);
        }
    }
    if(pq.size()==0){
        return 0;
    }
    return pq.top();
}

int main(){
    vector<int> arr = {9,3,5,7,3};
    cout<<countStone(arr);
    return 0;
}