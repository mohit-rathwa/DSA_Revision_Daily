class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<int> curr(2 , 0);
        vector<int> next1(2 ,0);
        vector<int> next2(2,0);

        for(int i=n-1;i>=0;i--){
            for(int buy = 0; buy<=1 ; buy++){
                if(buy){
                    curr[buy] = max(-prices[i]+next1[0],next1[1]);
                }
                else{
                    curr[buy] = max(+prices[i]+next2[1],next1[0]);
                }
            }
            next2 = next1;
            next1 = curr;
        }


        return curr[1];
    }
};