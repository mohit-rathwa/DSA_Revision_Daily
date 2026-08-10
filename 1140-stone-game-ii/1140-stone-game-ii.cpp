class Solution {
public:
    int n;
    vector<vector<vector<int>>> dp;

    int solveforA(int person , int idx, int M ,vector<int>&piles){

        if(idx >= n) return 0;

        if(dp[person][idx][M] != -1) return dp[person][idx][M];

        int res = (person == 1) ? -1 : INT_MAX;
        int stones = 0;

        for(int x=1 ; x <= min(2*M,n-idx) ; x++){

            stones += piles[idx+x-1];
            if(person == 1){
                res = max(res , stones + solveforA(!person , idx+x , max(M,x) , piles));
            }
            else{
                res = min(res , solveforA(!person , idx+x , max(M,x) , piles));
            }
        }

        return dp[person][idx][M] = res;
    }
    int stoneGameII(vector<int>& piles) {
        n = piles.size();
        dp.resize( 2 , vector<vector<int>> (n+1 ,(vector<int> (n+1,-1))));

        return solveforA(1 , 0 , 1 , piles);
    }
};