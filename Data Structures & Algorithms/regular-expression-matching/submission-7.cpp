class Solution {
    vector<vector<int>> memo;
public:
    bool isMatch(string s, string p) {
        memo.resize(s.size()+1, vector<int>(p.size()+1, -1));

        return dfs(s, p, 0, 0);
    }

    bool dfs(string s, string p, int i, int j) {

        if(j == p.size()) {
            return i == s.size();
        }
        if(memo[i][j] != -1) {
            return memo[i][j];
        }
        bool match = (i<s.size() && (s[i] == p[j] || p[j] == '.'));

        if(j+1 < p.size() && p[j+1] == '*') {
            memo[i][j] = dfs(s, p, i, j+2) || (match && dfs(s, p, i+1, j));
        } else {
            memo[i][j] = match && dfs(s, p, i+1, j+1);
        }

        return memo[i][j];
    }
};
