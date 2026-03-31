class Solution {
public:
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
               // cout<< "val is "<<val<<" and res is "<<res<<" size is "<<size<<endl;

                if(val == endWord) {
                    return res;
                }
                visited[val] = true;

                for(string nei : adj[val]) {
                   // cout<<"cur is " <<val <<" and nei is "<<nei<<endl;
                    if(visited[nei] == false)
                        q.push(nei);
                }
            }     
        }
        return {};
    }
};
