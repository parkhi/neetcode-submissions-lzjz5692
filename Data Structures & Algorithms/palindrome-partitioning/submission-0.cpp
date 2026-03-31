class Solution {
    vector<vector<string>> res;
public:
    vector<vector<string>> partition(string s) {
        vector<string> cur ;

        fetch(s, 0, 0, cur);
       
       return res;
    }

void  fetch(string s, int i, int j, vector<string> cur) {
        if (j >= s.size()) {
            if (i == j) {
                res.push_back(cur);
            }
            return;
        }

        if(valid(s, i, j)) {
            cur.push_back(s.substr(i,j-i+1));
            fetch(s,j+1,j+1,cur);
            cur.pop_back();
        }

        fetch(s,i,j+1,cur);
    }

bool valid(string &s, int l, int r) {
        while (l < r) {
            if (s[l] != s[r]) {
                return false;
            }
            l++;
            r--;
        }
        return true;
    }
};
