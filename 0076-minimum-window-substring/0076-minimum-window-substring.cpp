class Solution {
public:
    string minWindow(string s, string t) {
        int n = s.size();
        int m = t.size();

        if(n==0 || m==0 || m>n) return "";
        vector<int> seen(256,0);

        int l = 0 , start = 0;
        int req = m ;
        int min_len = INT_MAX;

        for(auto tc : t) seen[tc]++;

        for(int r=0 ; r<n ; r++){
            
            if(seen[s[r]] > 0) req--;
            seen[s[r]]--;


            while(req == 0){
                if(r-l+1 < min_len){
                    min_len = r-l+1;
                    start = l;
                }

                seen[s[l]]++;
                if(seen[s[l]]>0) req++;
                l++;
            }
        }

        return min_len == INT_MAX ? "" : s.substr(start ,min_len);
    }
};