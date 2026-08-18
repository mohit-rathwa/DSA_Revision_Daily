class Solution {
public:
    int max_row(vector<vector<int>>& mat,int col){
        int n = mat.size();
        int idx =-1;
        int maxi = INT_MIN;
        for(int i=0;i<n;i++){
            if(mat[i][col] > maxi){
                maxi = mat[i][col];
                idx = i;
            }
        }
        return idx;
        
    }
    vector<int> findPeakGrid(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();
        int ans = INT_MIN;

        int low = 0;
        int high = m-1;

        while(low <= high){
            int mid = low + (high-low)/2;

            int row = max_row(mat , mid);
            int left = (mid>=1) ? mat[row][mid-1] : -1;
            int right = (mid<m-1) ? mat[row][mid+1] : -1;
            int curr = mat[row][mid];

            if( curr>right && curr>left){
                return {row,mid};
            }
            else if( curr < left){
                high = mid-1;
            }
            else{
                low = mid+1;
            }
        }
        return {-1,-1};
    }
};