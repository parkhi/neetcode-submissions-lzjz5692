class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        int res = 0;
        sort(intervals.begin(), intervals.end());

        int cur_end = intervals[0][1];

        for(int i=1; i<intervals.size(); i++) {
            if(intervals[i][0] >= cur_end) {
                cur_end = intervals[i][1];
            }
            else {
                cur_end = min(intervals[i][1], cur_end);
                res++;
            }
        }

        return res;
    }
};
