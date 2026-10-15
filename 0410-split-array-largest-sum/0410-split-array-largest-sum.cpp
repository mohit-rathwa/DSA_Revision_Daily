class Solution {
public:
    bool check_k(vector<int>& nums , int k ,int d){
        int cnt = 1;
        int sum = 0;

        for(int i=0;i<nums.size();i++){
            if(sum+nums[i]>d){
                cnt++;

                sum = nums[i];
            }
            else{
                sum+=nums[i];
            }
        }
        return cnt <= k;
    }
    int splitArray(vector<int>& nums, int k) {
        int n = nums.size();

        int s = *max_element(nums.begin(),nums.end());
        int e = accumulate(nums.begin(),nums.end(),0);
        int ans = s;

        while(s<=e){
            int mid = s + (e-s)/2;

            if(check_k(nums , k , mid)){
                ans = mid;
                e = mid - 1;
            }
            else{
                s = mid + 1;
            }
        }

        return ans;
    }
};