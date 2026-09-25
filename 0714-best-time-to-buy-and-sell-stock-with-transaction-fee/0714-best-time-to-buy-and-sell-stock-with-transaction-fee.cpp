class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        int n = prices.size();

        vector<int> curr(2 , 0);
        vector<int> next(2 , 0);

        for(int idx=n-1;idx>=0;idx--){
            for(int buy = 0; buy<=1 ; buy++){
                if(buy==1){
                    curr[buy] = max(-prices[idx]+next[0],next[1]);
                }
                else{
                    curr[buy] = max(+prices[idx]-fee+next[1],next[0]);
                }
            }
            next = curr;
        }

        return curr[1];
    }
};