class Solution {
public:
    const int MOD = 1e9+7;
    long long subArrayRanges(vector<int>& nums) {
        int n = nums.size();

        stack<int> st;
        vector<int> left(n,0);
        vector<int> right(n,0);

        for(int i=0;i<n;i++){
            while(!st.empty()  && nums[st.top()]>=nums[i]){
                st.pop();
            }
            left[i] = (st.empty() ? -1: st.top());
            st.push(i);
        }
        while(!st.empty()) st.pop();
        for(int i=n-1;i>=0;i--){
            while(!st.empty()  && nums[st.top()]>nums[i]){
                st.pop();
            }
            right[i] = (st.empty() ? n : st.top()); 
            st.push(i);
        }
        long long small = 0;
        for(int i=0;i<n;i++){
            long long l = i - left[i];
            long long r = right[i] - i;
            small = small + (nums[i]*r*l*1LL);
        }

        for(int i=0;i<n;i++){
            while(!st.empty()  && nums[st.top()]<=nums[i]){
                st.pop();
            }
            left[i] = (st.empty() ? -1: st.top());
            st.push(i);
        }
        while(!st.empty()) st.pop();
        for(int i=n-1;i>=0;i--){
            while(!st.empty()  && nums[st.top()]<nums[i]){
                st.pop();
            }
            right[i] = (st.empty() ? n : st.top());
            st.push(i);
        }
        long long big = 0;
        for(int i=0;i<n;i++){
            long long l = i - left[i];
            long long r = right[i] - i;
            big = (big + (nums[i]*r*l*1LL));
        }
        return 1LL*(big-small);

    } 
};