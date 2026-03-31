class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> subs;
        int max = 0, l = 0, r = 0;

        int size = s.length();

        while (r<size)
        {
            if(subs.find(s[r]) == subs.end())
            {
                max = std::max(max , r-l+1);
            }
            else
            {
                l = std::max(l, subs[s[r]]+1);
                max = std::max(max , r-l+1);
            }

            subs[s[r]] = r;
            r++;
        }

    return max;
        
    }
};
