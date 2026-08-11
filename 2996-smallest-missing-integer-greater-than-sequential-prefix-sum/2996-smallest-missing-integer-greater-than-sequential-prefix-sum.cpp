class Solution {
public:
    int missingInteger(vector<int>& nums) {
        unordered_set<int> st(nums.begin(),nums.end());
        int n = nums.size();

        int sum = nums[0];
        int prev = 0;
        
        for(int i=1;i<n;i++){
            if(nums[i] == nums[prev]+1){
                sum +=nums[i];
                prev++;
            }
            else break;
        }

        while(st.count(sum)){
            sum++;
        }
        return sum;
    }
};