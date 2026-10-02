class Solution {
public:
    bool solve(int &i , string &s){
        int n = s.size();

        if(s[i] == 't'){
            i++;
            return true;
        }
        if(s[i] == 'f'){
            i++;
            return false;
        }

        char op = s[i];
        i+=2;
        vector<bool> vals;

        while(s[i] != ')'){
            if(s[i] == ','){
                i++;
            }
            else{
                vals.push_back(solve(i , s));
            }
        }
        i++;

        if(op == '|'){
            for(bool x : vals){
                if(x) return true;
            }
            return false;
        }

        if(op == '&'){
            for(bool x : vals){
                if(!x) return false;
            }
            return true;
        }

        if(op == '!'){
            return (!vals[0]);
        }

        return false;
    } 
    bool parseBoolExpr(string expression) {
        int n = expression.size();
        int i = 0;
        return solve( i , expression );
    }
};