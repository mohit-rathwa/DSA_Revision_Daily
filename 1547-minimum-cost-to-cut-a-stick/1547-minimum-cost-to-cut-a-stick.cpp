class Solution {
public:
    int minCost(int n, vector<int>& cuts) {
        int m = cuts.size();
        cuts.push_back(n);
        cuts.insert(cuts.begin() , 0);
        sort(cuts.begin(),cuts.end());
        vector<vector<int>> dp( cuts.size()+1 , vector<int> ( cuts.size()+1 , 0));

        
        for(int i = m ; i>0 ;i--){
            for(int j=1 ; j<= m ; j++){
                if(i>j) continue;
                int res = INT_MAX;
                for(int idx = i ; idx<=j ; idx++){
                    int cost = cuts[j+1] - cuts[i-1] + dp[i][idx-1] + dp[idx+1][j];
                    res = min(res , cost);
                }
                dp[i][j] = res;
            }
        }

        return dp[1][m];
        
    }
};