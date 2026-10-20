class Solution {
public:
    static bool compare(vector<int>&first , vector<int>&second){
        return first[1] < second[1];
    }
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        int n = intervals.size();

        if(n == 0) return intervals.size();

        sort(intervals.begin(),intervals.end(), compare);

        int lst = intervals[0][1];
        int cnt = 0;

        for(int i=1;i<n;i++){
            if(lst > intervals[i][0]){
                cnt++;
            }
            else{
                lst = intervals[i][1];
            }
        }

        return cnt;
    }
};