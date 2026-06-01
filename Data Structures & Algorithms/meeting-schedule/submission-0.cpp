/**
 * Definition of Interval:
 * class Interval {
 * public:
 *     int start, end;
 *     Interval(int start, int end) {
 *         this->start = start;
 *         this->end = end;
 *     }
 * }
 */
bool func(const Interval& a, const Interval& b) {
    if (a.start == b.start) {
        return a.end < b.end;
    }
    
    return a.start < b.start;
}

class Solution {
public:

    bool canAttendMeetings(vector<Interval>& intervals) {
        sort(intervals.begin(), intervals.end(), func);

        for (int i = 1; i < intervals.size(); ++i) {
            if (intervals[i].start < intervals[i - 1].end) {
                return false;
            }
        }

        return true;
    }
};
