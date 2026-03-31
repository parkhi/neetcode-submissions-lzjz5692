class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {

        unordered_map<int, vector<int>> adj(edges.size()+1);
        vector<bool> visited(edges.size()+1, false);
        bool cyclefound = false;
        unordered_set<int> cycle;

        for(auto edge : edges) {
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }

        dfs(adj, 0, edges[0][0], visited, cyclefound, cycle);

        cout<<"cycle is  ";
        for(int i : cycle) {
            cout << i << "  ";
        }
        cout << endl;
        
        for(int i=edges.size()-1; i>=0; i--) {
            if(cycle.count(edges[i][0]) && cycle.count(edges[i][1])) {
                return {edges[i][0], edges[i][1]};
            }
        }

        return {};
        
    }

void dfs (unordered_map<int, vector<int>>adj , int parent, int cur, vector<bool>& visited, bool& cyclefound, unordered_set<int>& cycle) {


        if(visited[cur]) {
            cyclefound = true;
            return;
        }

        visited[cur] = true;

        for( int nei : adj[cur]) {
            if(nei != parent) {
                dfs(adj, cur, nei, visited, cyclefound, cycle);
            if(cyclefound) {
                if(!cycle.count(cur)) {
                   cycle.insert(cur);
                }
                else {
                    cyclefound = false;
                }            
            return;
            }

        }
    }
    }
};
