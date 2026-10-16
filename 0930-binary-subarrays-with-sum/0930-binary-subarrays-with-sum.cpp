class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int k) {
        int n = nums.size();
        int cnt = 0 , sum = 0;
        unordered_map<int,int> mp;
        mp[0]=1;

        for(auto num : nums){
            sum+=num;
            cnt+=mp[sum - k];
            mp[sum]++;
        }

        return cnt;
    }
};