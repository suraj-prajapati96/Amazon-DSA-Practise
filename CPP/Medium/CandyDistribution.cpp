#include<bits/stdc++.h>
using namespace std;

void distributeCandy(vector<int>Ratings){
    int n = Ratings.size();
    vector<int> candy(n,1);
    for(int i=1; i<n; i++){
        if(Ratings[i]>Ratings[i-1]){
            candy[i] = candy[i-1]+1;
        }
    }
    for(int i=n-2; i>=0; i--){
        if(Ratings[i]>Ratings[i+1]){
            candy[i] = max(candy[i],candy[i+1]+1);
        }
    }
    for(int i=0; i<candy.size(); i++){
        cout<<candy[i]<<" ";
    }
}

int main(){
    vector<int> Ratings = {1, 3, 4, 5, 2};
    distributeCandy(Ratings);
    return 0;
}