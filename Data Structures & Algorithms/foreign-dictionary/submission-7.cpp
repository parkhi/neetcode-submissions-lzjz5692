class Solution {
    unordered_map<char,unordered_set<char>> ad;
    unordered_map<char, bool> visited;

    bool dfs(char cur, string& res) {
        if(visited.count(cur)) {
            return visited[cur];
        }

        visited[cur] = true;

        for(char next : ad[cur]) {
            if(dfs(next, res)) {
                return true;
            }
        }
        res.push_back(cur);
        visited[cur] = false;

        return false;
    }

public:
    string foreignDictionary(vector<string>& words) {
        
        char first;
        unordered_set<char> start;

        for(string word : words) {
            for(char ch : word) {
                ad[ch] = {};
            }
        }

        for(int i=0; i<words.size()-1; i++) {
            string w1 = words[i];
            string w2 = words[i+1];
            
            int len = (w1.length()>w2.length())?w2.length():w1.length();

            for(int j=0; j<len; j++) {
               // cout<<" "<<j<<" "<<endl;
                if(w1[j] == w2[j]) {

                    if((w1.length() > w2.length()) && (w2.length() == j+1)) {
                        return "";
                    }
                    continue;
                }

                ad[w1[j]].insert(w2[j]);
                break;
            }
        }

       string res("");

            for(auto ch : ad) {
                if(dfs(ch.first, res)) 
                    return "";
            }

        reverse(res.begin(), res.end());
        return res;
    }
};
