class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> res(numCourses);
        vector<int> indegree(numCourses, 0);
        unordered_map<int,vector<int>> adj(numCourses);

        for(auto preq : prerequisites) {
            indegree[preq[1]]++ ;
            adj[preq[0]].push_back(preq[1]);
        }

        queue<int> q;
        for(int i=0; i<numCourses; i++) {
            if(indegree[i] == 0) {
                q.push(i);
            }
        }
        int finish = 0;
        while(!q.empty()) {
            int done = q.front();
            q.pop();
            res[numCourses-finish-1] = done;
            finish++;

            for(int ad : adj[done]) {
                indegree[ad]--;
                if(indegree[ad] == 0) {
                    q.push(ad);
                }
            }

        }

        if(finish != numCourses) {
            return {};
        }

        return res;
    }
};
