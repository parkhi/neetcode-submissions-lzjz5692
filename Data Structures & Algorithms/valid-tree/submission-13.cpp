class Solution {
public:
    bool validTree(int n, vector<vector<int>>& edges) {

        unordered_set<int> visit;
        unordered_map<int, vector<int>> graph;
        int total = 0;

        if(n == 1 && edges.empty()) {
            return true;
        }

        for(auto edge : edges) {
            int node1 = edge[0];
            int node2 = edge[1];
            if(node1 == node2) {
                return false;
            }
            graph[node1].push_back(node2);
            graph[node2].push_back(node1);
        }
        bool res =  dfs(graph, visit, edges[0][0], -1, total);
        //cout<<"res is "<<res<<" total is "<<total<<" "<<endl;
        if(total < n) {
            res = false;
        }
        return res;
    }

    bool dfs(unordered_map<int, vector<int>> graph, unordered_set<int> visit, int node, int parent, int& total) {
        if(!visit.empty() && (visit.contains(node))) {
            return false;
        }
        
        visit.insert(node);
        total++;

        for(int nei : graph[node]) {
            if(nei != parent) {
                if(!dfs(graph, visit, nei, node, total)) {
                    return false;
                }
            }
        }

        visit.erase(node);
        return true;
    }
};
