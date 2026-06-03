class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>> res ;
        int start , end ;
        start = newInterval[0], end = newInterval[1];
        for (int i=0; i<intervals.size(); i++) {
            vector<int> cur = intervals[i];          

            if (cur[1] < start) {
                res.push_back(cur);
            }
            else if (cur[0] > end) {
                res.push_back(newInterval);
                res.insert(res.end(),
                    std::make_move_iterator(intervals.begin() + i),
                    std::make_move_iterator(intervals.end()));

                return res;

            } else {
                newInterval[0] = min(newInterval[0], cur[0]);
                newInterval[1] = max( newInterval[1], cur[1]);
            }
        }

        res.push_back(newInterval);
        return res;

    }
};
