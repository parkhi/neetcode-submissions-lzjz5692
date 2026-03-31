class Solution {
    void backtrack(int n, vector<string>& res, string& comb, int open, int close) {
        if(open == close && open == n) {
            res.push_back(comb);
            return;
        }
        if(open<n) {
            comb += '(';
            backtrack(n, res, comb, open+1, close);
            comb.pop_back();
        }
        if(close<open) {
            comb += ')';
            backtrack(n, res, comb, open, close+1);
            comb.pop_back();
        }
    }

public:
    vector<string> generateParenthesis(int n) {
        vector<string> res;
        string comb;
        backtrack(n, res, comb, 0, 0);

        return res;
        
    }
};
