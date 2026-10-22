class Solution {
public:
    bool check_palindrome(int si,int e,string &s){
        while(si <= e){
            if(s[si++]!=s[e--]) return false;
        }
        return true;
    }

    void solve(int idx,string &s,vector<vector<string>>&ans,vector<string>&curr){

        if(idx == s.size()){
            ans.push_back(curr);
            return;
        }

        for(int i= idx ; i<s.size() ; i++){
            if(check_palindrome(idx , i , s)){
                curr.push_back(s.substr(idx , i-idx+1));
                solve(i+1,s,ans,curr);
                curr.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) {
        int n = s.size();

        vector<vector<string>> ans;
        vector<string> curr;

        solve(0 , s , ans , curr);

        return ans;


    }
};