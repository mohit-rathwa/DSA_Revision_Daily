class Solution {
public:
    bool sumGame(string num) {
        int n = num.size();
        int l = 0;
        int r = 0;
        int l_s = 0;
        int r_s = 0;
        int mid = n/2;
        for(int i=0;i<n;i++){
            if(i < mid){
                if(num[i]=='?') l++;
                else{
                    l_s += num[i]-'0';
                }
            }else{
               if(num[i]=='?') r++;
               else{
                r_s += num[i]-'0';
               } 
            }
        }
        if((l+r)%2 == 1){
            return true;
        }
        
        int left = 2*l_s + (9)*l;
        int right = 2*r_s + (9)*r;

        if(left == right) return false;
        return true;
    }
};