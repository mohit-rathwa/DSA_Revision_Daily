class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();
        int maxi = nums[0];
        int mini = nums[0];
        int ans = nums[0];

        for(int i=1;i<n;i++){
            int x = nums[i];
            if(x<0) swap(maxi , mini);
            maxi = max(x , x*maxi);
            mini = min(x , x*mini);
            ans = max(ans,maxi);
        }
        return ans;

    }
};