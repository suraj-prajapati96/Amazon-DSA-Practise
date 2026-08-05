#include<bits/stdc++.h>
using namespace std;

bool canFinish(int n,vector<vector<int>>&prerequisties){
    vector<vector<int>> adj(n);
    vector<int> indegree(n,0);
    queue<int>queue;
    for(auto x:prerequisties){
        adj[x[1]].push_back(x[0]);
        indegree[x[0]]++;
    }
    for(int i=0; i<n; i++){
        if(indegree[i]==0){
            queue.push(i);
        }
    }
    int count=0;
    while(!queue.empty()){
        int c = queue.front();
        queue.pop();
        count++;
        for(int j:adj[c]){
            if(--indegree[j]==0){
                queue.push(j);
            }
        }
    }
    return count==n;
}

int main(){
    int n=4;
    vector<vector<int>> arr;
    arr.push_back({1,0});
    arr.push_back({2,0});
    arr.push_back({3,1});
    arr.push_back({3,2});
    if(canFinish(n,arr)){
        cout<<"true"<<endl;
    }else{
        cout<<"false"<<endl;
    }
    return 0;
}