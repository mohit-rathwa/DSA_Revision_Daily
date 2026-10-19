class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n = nums.size();
        priority_queue<pair<int,int>> pq;
        vector<int> ans;

        for(int r=0;r<n;r++){
            pq.push({nums[r],r});
            if(r>=k-1){
                while(pq.top().second <= r-k) pq.pop();
                ans.push_back(pq.top().first);
            }
        }
        return ans;
    }
};