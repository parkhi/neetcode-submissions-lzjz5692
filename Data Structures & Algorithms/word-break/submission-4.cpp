class Solution {
public:
    vector<int> memo;
    bool wordBreak(string s, vector<string>& wordDict) {
        memo.resize(s.size()+1, -1);
        memo[s.size()] = 1;

        unordered_set<string> dict;
        
        for(string word : wordDict) {
            dict.insert(word); 
            //cout<<"word "<<word<<endl;
        }

        return wordbr(s, dict, 0);
    }

    bool wordbr(string& s, unordered_set<string>& dict, int ind) {
        if (ind == s.size()) {
            return true;
        }

        if(memo[ind] != -1) {
            return memo[ind]==1 ;
        }

        for(int i=ind; i<s.length(); i++) {
            string cur = s.substr(ind, i-ind+1);
            cout<<"cur "<<cur<<" ";
            if(dict.count(cur)) {
                cout<<"i am in "<<endl;
                if(wordbr(s, dict, i+1)) {
                    memo[ind] = 1;
                    return true;
                }
            }
        }
        memo[ind] = 0;
        return false;
    }
};
