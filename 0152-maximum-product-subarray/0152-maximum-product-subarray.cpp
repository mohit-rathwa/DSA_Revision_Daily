class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();
        int maxi = INT_MIN;
        if(n==1) return nums[0];
        for(int i=0;i<n;i++){
            int prod = nums[i];
            maxi = max(maxi , prod);
            for(int j=i+1;j<n;j++){
                prod*=nums[j];
                maxi = max(maxi , prod);
            }
            maxi = max(maxi , prod);
        }
        return maxi;
    }
};