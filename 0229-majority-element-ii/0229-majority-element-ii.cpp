class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans;
        int c1=0,c2=0;
        int v1=0,v2=0;

        for(auto it : nums){
            if(it == c1) v1++;
            else if(it == c2) v2++;
            else if(v1 == 0){
                c1 = it;
                v1 = 1;
            }
            else if(v2 == 0){
                c2 = it;
                v2 = 1;
            }
            else{
                v1--;v2--;
            }
        }

        v1 = 0 , v2 = 0;
        for(int i=0;i<n;i++){
            if(nums[i] == c1) v1++;
            if(nums[i] == c2) v2++;
        }

        if(v1 > (n/3)) ans.push_back(c1);
        if(c1!=c2 && v2 > (n/3)) ans.push_back(c2);

        return ans;
    }
};