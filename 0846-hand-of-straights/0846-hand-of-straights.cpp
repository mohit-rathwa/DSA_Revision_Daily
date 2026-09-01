class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int k) {
        int n = hand.size();
        priority_queue<int,vector<int>,greater<int>> pq;
        unordered_map<int,int> mp;
        for(auto it : hand){
            mp[it]++;
        }
        for(auto m : mp){
            pq.push(m.first);
        }

        while(!pq.empty()){
            int st = pq.top();

            if(mp[st] == 0){
                pq.pop();
                mp[st--];
                continue;
            }

            for(int i=0;i<k;i++){
                if(mp[st+i] == 0) return false;
                mp[st+i]--;
            }
        }
        return true;
    }
};