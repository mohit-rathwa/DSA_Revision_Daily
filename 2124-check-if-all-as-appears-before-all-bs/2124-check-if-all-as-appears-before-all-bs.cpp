class Solution {
public:
    bool checkString(string s) {
        int check_B = false ;

        for(char ch : s){
            if(ch=='b') check_B = true;
            else{
                if(check_B) return false;
            }
        }
        return true;
    }
};