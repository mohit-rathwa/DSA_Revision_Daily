class Solution {
public:
    bool static const comparetor(string &s1,string &s2){
        return s1.size() < s2.size();
    }
    int longestStrChain(vector<string>& words) {
        int n = words.size();
        int lst = 0;
        int maxi = 1;

        sort(words.begin(),words.end(),comparetor);

        unordered_map<string,int> dp;

        for(auto &it : words){
            dp[it] = 1;

            for(int j=0 ;j<it.size();j++){

                string s = it.substr(0,j) + it.substr(j+1);

                if(dp.find(s) != dp.end()){
                    dp[it] = max(dp[it],dp[s]+1);
                }
                if(maxi < dp[it]){
                    maxi = dp[it];
                }
            }
        }

        return maxi;
    }
};