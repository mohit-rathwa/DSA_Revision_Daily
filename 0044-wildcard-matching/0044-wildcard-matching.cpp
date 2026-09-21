class Solution {
public:
    vector<vector<int>> dp;
    bool solve(int i,int j,string &s,string &p){

        if(i<=0 && j<=0) return true;
        
        if(i<= 0 && j>=0){
            for(int k=1;k<=j;k++){
                if(p[k-1] != '*') return false;
            }
            return true;
        }
        if(i>=0 && j<=0){
            return false;
        }

        if(dp[i][j] != -1) return dp[i][j];

        if(s[i-1]==p[j-1]) return dp[i][j] = solve(i-1,j-1,s,p);
        else if(p[j-1]=='?'){
            return  dp[i][j]=solve(i-1,j-1,s,p);
        }
        else if(p[j-1]=='*'){
            return dp[i][j]=solve(i-1,j,s,p) || solve(i,j-1,s,p);
        }

        return dp[i][j]=false;
    }
    bool isMatch(string s, string p) {
        int n = s.size();
        int m = p.size();
        dp.assign(n+1 , vector<int> (m+1 , -1));

        return solve(n,m,s,p);
    }
};