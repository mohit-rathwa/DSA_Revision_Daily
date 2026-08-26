class Solution {
public:
    int trap(vector<int>& height) {
        // int n =height.size();

        // int left=0;
        // int leftmax=0;
        // int right=n-1;
        // int rightmax=0;

        // int ans=0;

        // while(left<=right){
        //     if( leftmax < rightmax ){
        //         if( leftmax <= height[left] ){
        //             leftmax=height[left]; 
        //         }
        //         left++;
        //     }
        //     else{
        //         if( rightmax <= height[right] ){
        //             rightmax=height[right]; 
        //         }
        //         right--;
        //     }
            

        //     ans += min(leftmax,rightmax)*(right-left+1);
        // }
        int n = height.size();
        vector<int> l_max(n,0);
        vector<int> r_max(n,0);

        l_max[0] = height[0];
        for(int i=1;i<n;i++){
            l_max[i] = max(l_max[i-1] ,height[i]);
        }
        r_max[n-1] = height[n-1];
        for(int i=n-2;i>=0;i--){
            r_max[i] = max(r_max[i+1] , height[i]);
        }
        int cnt = 0;

        for(int i=0;i<n;i++){
            int ht =  min(l_max[i],r_max[i]);
            int diff = max(0 , ht-height[i]);
            cnt+=diff;
        }

        return cnt;
    }
};