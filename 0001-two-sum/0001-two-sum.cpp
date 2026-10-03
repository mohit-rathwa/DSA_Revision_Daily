class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n = nums.size();
        unordered_map<int,int> mp;
        int sum = 0;
        vector<int>ans;

        for(int i=0;i<n;i++){

            int cur = nums[i];
            int diff = target - cur;

            if(mp.find(diff) != mp.end() ){
                return {i , mp[diff]};
            }

            mp[nums[i]] = i;
        }

        return {};
    }
};