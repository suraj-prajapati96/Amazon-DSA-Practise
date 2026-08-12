#include<bits/stdc++.h>
using namespace std;

vector<vector<string>> groupAnagram(vector<string>strs){
    vector<vector<string>> ans;
    map<string,vector<string>> map;
    for(int i=0; i<strs.size(); i++){
        string temp = strs[i];
        sort(temp.begin(), temp.end());
        map[temp].push_back(strs[i]);
    }
    for(auto x:map){
        ans.push_back(x.second);
    }
    return ans;
}

int main(){
    vector<string> strs = {"eat","tea","tan","ate","nat","bat"};
    vector<vector<string>>s = groupAnagram(strs);
    return 0;
}