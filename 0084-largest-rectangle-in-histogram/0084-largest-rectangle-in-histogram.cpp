class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        vector<int> pse(n);
        vector<int> nse(n);
        stack<int> st;

        for(int i=0;i<n;i++){
            while(!st.empty() && heights[st.top()]>=heights[i]){
                st.pop();
            }
            pse[i] = (st.empty()) ? -1 : st.top();
            st.push(i);
        }
        while(!st.empty()) st.pop();
        for(int i=n-1;i>=0;i--){
            while(!st.empty() && heights[st.top()]>=heights[i]){
                st.pop();
            }
            nse[i] = (st.empty()) ? n : st.top();
            st.push(i);
        }
        int maxi = 0;
        for(int i=0;i<n;i++){
            int l = i-pse[i];
            int r = nse[i]-i;
            int ans = heights[i]*(r+l-1);
            maxi = max(maxi , ans);
        }
        return maxi;
    }
};