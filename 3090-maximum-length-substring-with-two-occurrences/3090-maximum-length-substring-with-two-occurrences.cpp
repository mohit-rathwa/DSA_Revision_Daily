class Solution {
public:
    int maximumLengthSubstring(string s) {
        vector<int> cha(26,0);

        int l = 0;
        int maxi = 0;

        for(int i=0;i<s.size();i++){
            cha[s[i]-'a']++;

            while(cha[s[i]-'a'] > 2){
                cha[s[l]-'a']--;
                l++;
            }

            maxi = max(maxi , i-l+1);
        }
        return maxi;
    }
};