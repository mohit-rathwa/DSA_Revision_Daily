class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        int n = nums.size();

        vector<int> hash(n);

        sort(nums.begin(),nums.end());
        vector<int> dp(n,1);
        int lst = 0;
        int maxi = 1;

        for(int i=0;i<n;i++){
            hash[i] = i;
            for(int j= 0; j < i ;j++){
                if(nums[i]%nums[j] == 0 && dp[i]<dp[j]+1){
                    dp[i] = dp[j] + 1;
                    hash[i] = j;
                }
            }
                if(maxi < dp[i]){
                    maxi = dp[i];
                    lst = i;
                }
        }
        vector<int> tmp;
        while(lst != hash[lst]){
            tmp.push_back(nums[lst]);
            lst = hash[lst];
        }
        tmp.push_back(nums[lst]);
        reverse(tmp.begin(),tmp.end());

        return tmp;
    }
};