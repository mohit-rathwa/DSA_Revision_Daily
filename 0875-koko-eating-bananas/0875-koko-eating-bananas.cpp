class Solution {
public:
    bool check_ele(vector<int>&piles , int h , int k){
        int curr = 0;
        for(auto it :piles){
            curr+=(it+k-1)/k;
            if(curr>h) return false;
        }
        return (curr<=h);
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int n = piles.size();
        int ans = 1;

        int low = 1;
        int high = *max_element(piles.begin(),piles.end());

        while(low<=high){
            
            int mid = low + (high-low)/2;
            if(check_ele(piles , h , mid)){
                ans = mid;
                high = mid - 1;
            }
            else{
                low = mid +  1;
            }
        }

        return ans;

    }
};