class Solution {
public:
    int characterReplacement(string s, int k) {
        int n = s.size();
        if(n==0) return 0;

        int l=0,r=0;
        vector<int> mp(26,0);
        int max_freq = 1;
        int max_len = 1;

        while(r<n){
            mp[s[r]-'A']++;
            max_freq = max(max_freq , mp[s[r]-'A']);
            if((r-l+1)-max_freq > k){
                mp[s[l]-'A']--;
                l++;
            }

            max_len = max(max_len , r-l+1);
            r++;
        }
        return max_len ;
    }
};