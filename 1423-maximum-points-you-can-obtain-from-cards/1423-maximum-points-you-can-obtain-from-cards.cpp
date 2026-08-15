class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int n = cardPoints.size();
        int n_idx = n-1;
        int l_sum = 0;
        int r_sum = 0;
        for(int i=0;i<k;i++) l_sum+=cardPoints[i];
        int maxi = l_sum;

        for(int i=k-1;i>=0;i--){
            l_sum -= cardPoints[i];
            r_sum += cardPoints[n_idx];
            n_idx--;
            maxi = max(maxi, l_sum+r_sum);
        }
        return maxi;
    }
};