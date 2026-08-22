class Solution {
public:
    int nearestDrone(vector<vector<int>>& drones, vector<int>& target) {
        int idx = -1;
        int mini = INT_MAX;
        int n  = drones.size();
        for(int i=0;i<n;i++){
            int x = drones[i][0];
            int y = drones[i][1];
            int range = drones[i][2];

            int dist = abs(target[0]-x) + abs(target[1]-y);

            if(dist <= range){
                if(dist < mini || (dist == mini && i < idx)){
                    mini = dist;
                    idx = i;
                }
            }
        }
        return idx;
    }
};