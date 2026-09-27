#include<bits/stdc++.h>
class Solution {
public:
    bool ispalindrome(int i ,int j, string &s){
        
        while(i<j){
            if(s[i]!=s[j]) return false;
            i++;
            j--;
        }
        return true;
    }
    vector<int> dp;
    int solve(int idx , string &s){
        int n = s.size();

        if( idx == n) return 0;

        if(dp[idx]!=-1) return dp[idx];

        int ans = 1e9;
        for(int j=idx ; j<n ;j++){
            if( ispalindrome(idx , j , s) ){
                int mini = 1 + solve(j+1 , s);
                ans = min(ans,mini);
            }
            
        }
        return dp[idx]=ans;
    }
    int minCut(string s) {
        int n = s.size();
        dp.assign(n,-1);
        return solve(0 , s)-1;
    }
};