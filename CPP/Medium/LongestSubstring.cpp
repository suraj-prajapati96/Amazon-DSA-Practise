#include<iostream>
#include<string>
using namespace std;

void longestSubtring(string s){
    int start =0, end=1;
    int l=0, r = 0;
    for(int i=0; i<s.length(); i++){
        //even number of palindrome
        l=i;
        r = i+1;
        while(l>=0 && r<s.length() && s[l]==s[r]){
            if(r-l+1>end){
                start = l;
                end=r-l+1;
            }
            l--;
            r++;
        }
        //odd number of palindrome
        l=i-1;
        r=i+1;
        while(l>=0 && r<s.length() && s[l]==s[r]){
            if(r-l+1>end){
                start = l;
                end = r-l+1;
            }
            l--;
            r++;
        }
    }
    for(int i = start; i<end; i++){
        cout<<s[i];
    }
}
int main(){
    string s = "babad";
    longestSubtring(s);
    return 0;
}