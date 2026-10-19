class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n = nums.size();
        deque<int> dq;
        vector<int> ans;

        for(int r=0;r<n;r++){
            while(!dq.empty() && nums[dq.back()]<=nums[r]){
                dq.pop_back();
            }
            dq.push_back(r);

            if(dq.front() < r-k+1) dq.pop_front();

            if(r >= k-1){
                ans.push_back(nums[dq.front()]);
            }
        }
        return ans;
    }
};