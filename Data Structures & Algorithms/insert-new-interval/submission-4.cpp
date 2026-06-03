class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>> res ;
        int start , end ;
        start = newInterval[0], end = newInterval[1];
        
        for (int i=0; i<intervals.size(); i++) {
            //vector<int> cur = intervals[i];
            
            if (intervals[i][1] < start) {
                res.push_back(intervals[i]);
            }
            else if (intervals[i][0] > end) {
                res.push_back(newInterval);
                copy(intervals.begin() + i, intervals.end(), back_inserter(res));

                return res;

            } else {
                newInterval[0] = min(newInterval[0], intervals[i][0]);
                newInterval[1] = max(newInterval[1], intervals[i][1]);
                start = newInterval[0], end = newInterval[1];
            }
        }

        res.push_back(newInterval);
        return res;

    }
};
