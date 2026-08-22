class Solution {
public:
    bool checkDivisibility(int n) {
        int ori = n;
        int sum = 0;
        int prod = 1;

        while(n>0){
            int dig = n%10;
            sum+=dig;
            prod*=dig;
            n = n/10;
        }
        int div = sum+prod;
        if(ori%div == 0)return true;
        return false;
    }
};