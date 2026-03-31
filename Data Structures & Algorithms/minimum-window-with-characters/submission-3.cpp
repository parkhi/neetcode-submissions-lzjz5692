class Solution {
public:
    string minWindow(string s, string t) {
        if(t.length()> s.length()) {
            return "";
        }
        unordered_map<char, int> tmap, curmap;
        int slen = s.length(), tlen = t.length();
        string cursubs = "", minsubs = "";
        int p1 = 0, p2 = 0, curlen = 0, minlen = INT_MAX;
        int have = 0, need = 0;

        for(char ch : t) {
            tmap[ch]++;
            need++;
        }

        while(p2 <= slen) {
            while(have == need) {
                curlen = p2 - p1;
                if(minlen >= curlen) {
                    minlen = curlen;
                    minsubs = s.substr(p1, minlen);
                    cout<<"minsubs: "<<minsubs<<endl;
                }

                curmap[s[p1]]--;
                if(tmap.count(s[p1]) && curmap[s[p1]] < tmap[s[p1]])
                    {
                        have--;
                    }
                p1++;
            }
            curmap[s[p2]]++;

            if(tmap.count(s[p2]) && curmap[s[p2]] <= tmap[s[p2]]) {
                have++;
            }
            p2++;

        }
        return minsubs;
    }
};
