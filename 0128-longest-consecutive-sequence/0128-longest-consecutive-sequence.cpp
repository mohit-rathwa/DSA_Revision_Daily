class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n = nums.size();
        if(n==0) return 0;
        sort(nums.begin(),nums.end());
        int maxi = 1;
        int curr = 1;

        for(int i=0;i<n;i++){
            if(i>0 && nums[i]==nums[i-1]) continue;
            if(i>0 && nums[i]==nums[i-1]+1) curr++;
            else curr = 1;
            maxi = max(curr , maxi);
        }

        return maxi;
    }
};