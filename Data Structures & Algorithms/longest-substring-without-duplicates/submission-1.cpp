class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_set<char> subs;
        int max = 1, l = 0, r = 1;

        int size = s.length();
        if(size == 0)
            return 0;

        subs.insert(s[l]);

        while (r<size)
        {
            if(subs.find(s[r]) == subs.end())
            {
                subs.insert(s[r]);
                max = std::max(max , static_cast<int>(subs.size()));
                r++;
            }
            else
            {
                subs.erase(s[l]);
                l++;
            }

        }

    return max;
        
    }
};
