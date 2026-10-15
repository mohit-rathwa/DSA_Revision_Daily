class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.size();
        if(n==0) return 0;
        vector<int>seen(256,-1);

        int l = 0;
        int maxi = 1;

        for(int r=0;r<n;r++){
            if(seen[s[r]]>=l){
                l = seen[s[r]]+1;
            }
            seen[s[r]] = r;

            maxi = max(maxi , r-l+1 );
        }
        return maxi;
    }
};