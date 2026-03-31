class Solution {
public:
    string minWindow(string s, string t) {
        if(t.length()> s.length()) {
            return "";
        }
        
        int slen = s.length(), tlen = t.length();
        string temp = t, cursubs = "", minsubs = "";
        int p1 = 0, p2 = 0, curlen = 0, minlen = INT_MAX;

        while(p2 <= slen) {
            //cout<<"cursubs minsubs : "<<cursubs<<" "<<minsubs<<endl;
            if(temp == "") {
                curlen = p2 - p1;
                if(minlen >= curlen) {
                    minsubs = cursubs;
                    minlen = curlen;
                }
                p1 ++;
                p2 = p1;
                temp = t;
                cursubs = "";
                continue;
            }
            auto pos = temp.find(s[p2]);
            if(pos != string::npos) {
                if(temp == t) {
                    p1 = p2;
                }
                temp.erase(pos, 1);
            }
            if(temp == t) {
                p1++;
            }
            else {
                cursubs += s[p2];
            }
            p2++;

        }
        return minsubs;
    }
};
