class Solution {
public:
    bool uniformArray(vector<int>& nums1) {
        int ev =0 , od = 0;
       for(auto it : nums1){
           if(it%2 ==0) ev++;
           else od++;
       }
        if(ev==od) return true;
        else if(ev==0) return true;
        else if(od==0) return true;
        return true;
    }
};