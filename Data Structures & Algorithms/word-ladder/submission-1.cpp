class Solution {
public:

    void sortEachString(std::vector<std::string>& wordList) {
        // Iterate through each string in the vector
        for (std::string& s : wordList) {
            // Sort the characters within the current string using std::sort
            // The default comparison is ascending (alphabetical) order
            std::sort(s.begin(), s.end()); //
        }
    }

    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        int res = 0;
        int diff = 0;

        if(find(wordList.begin(), wordList.end() , endWord) == wordList.end()) {
            return res;
        }

        wordList.push_back(beginWord);

        unordered_map<string, vector<string>> adj(wordList.size());

        for(int i=0; i<wordList.size(); i++) {
            for(int j=i+1; j<wordList.size(); j++) {
                diff = 0;
                for (int k = 0; k < wordList[0].size(); k++) {
                    if (wordList[i][k] != wordList[j][k]) {
                        diff++;
                    }
                }

                if(diff == 1) {
                    adj[wordList[i]].push_back(wordList[j]);
                    adj[wordList[j]].push_back(wordList[i]);
                }
            }
        }
        
        unordered_map<string,bool> visited(wordList.size());

        queue<string> q;
        q.push(beginWord);

        while(!q.empty()) {

            int size = q.size();
            res++;       
            while(size--) {
                string val = q.front();
                q.pop();
                cout<< "val is "<<val<<" and res is "<<res<<" size is "<<size<<endl;

                if(val == endWord) {
                    return res;
                }
                visited[val] = true;

                for(string nei : adj[val]) {
                    cout<<"cur is " <<val <<" and nei is "<<nei<<endl;
                    if(visited[nei] == false)
                        q.push(nei);
                }
            }     
        }



        //dfs(beginWord, beginWord, "", adj, visited, endWord, res);


        return {};
    }

    void dfs(string beginWord, string cur, string parent, unordered_map<string, vector<string>> &adj,
                unordered_map<string,bool> &visited, string endWord, int& res) {
                    
                    

                    if(res != 0) {
                        return;
                    }          

                    if(cur == endWord) {
                        res++;
                        return;
                    }
                    if(visited[cur] == true) {
                        return;
                    }

                    visited[cur] = true;

                    for(string nei : adj[cur]) {
                        if(nei != parent && res==0) {
                            dfs(beginWord, nei, cur, adj, visited, endWord, res);

                            if(res != 0 ) {
                                if(cur != endWord)
                                    res++;
                                return;
                            }
                        }
                    }
                }
};
