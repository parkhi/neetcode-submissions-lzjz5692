class Solution {
    unordered_map<string, priority_queue<string, vector<string>, greater<string>>> adj;
    vector<string> res;
public:
    void dfs(string cur) {
        while(!adj[cur].empty()) {
            string next = adj[cur].top();
            adj[cur].pop();

            dfs(next);
        }
        res.push_back(cur);
    }
    vector<string> findItinerary(vector<vector<string>>& tickets) {

        for(auto i : tickets) {
            adj[i[0]].push(i[1]);
        }

        string cur = "JFK";

        dfs(cur);
        reverse(res.begin(), res.end());
        return res;
    }
};
