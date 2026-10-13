class Solution {
public:
    static bool compare(long long a,long long b){
        return abs(a) < abs(b);
    }
    long long maxAlternatingSum(vector<int>& nums) {
        int  n = nums.size();

        vector<int> maxi;
        vector<int> mini;
        vector<int> tmp = nums;

        sort(tmp.begin(),tmp.end(),compare);

        int i = 0 , j = tmp.size()-1;
        while(i<=j){
            maxi.push_back(abs(tmp[j]));
            if(i==j) break;
            mini.push_back(abs(tmp[i]));
            i++;
            j--;
        }
        long long ans = 0;
        for(int k=0;k<maxi.size();k++){
            ans+=(maxi[k]*maxi[k]);
        }
        for(int k=0;k<mini.size();k++){
            ans-=(mini[k]*mini[k]);
        }

        return ans;
    }
};