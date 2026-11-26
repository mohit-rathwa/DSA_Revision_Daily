class Solution {
public:
    bool canAliceWin(int n) {
        int cnt = 0;
        int num = 10;

        while(n >= num){
            n-=num;
            cnt++;
            num--;
        }

        return cnt%2 == 1;
    }
};