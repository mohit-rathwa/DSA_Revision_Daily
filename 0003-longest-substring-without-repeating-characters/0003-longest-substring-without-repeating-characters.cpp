class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.size();
        vector<int> seen(256,-1);

        int l=0,r=0;
        int maxi = 0;

        while(r<n){
            if( seen[s[r]] != -1 && seen[s[r]] >= l ){
                l = seen[s[r]] + 1;
            }
            seen[s[r]] = r;
            maxi = max(maxi , r-l+1);
            r++;
        }
        return maxi;
    }
};