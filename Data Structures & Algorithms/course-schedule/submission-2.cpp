class Solution {
public:
    bool isCyclicUtil( unordered_map<int, vector<int>>& preqmap, int i, vector<bool>& isvisited, vector<bool>& recstack) {
            if(recstack[i]) {
                return true;
            }
            if(isvisited[i]) {
                return false;
            }

            if (preqmap[i].empty()) {
                return false;
            }

            recstack[i] = true;
            isvisited[i] = true;

            for (int j : preqmap[i]) {
                if(isCyclicUtil(preqmap, j, isvisited, recstack)) {
                    return true;
                }
            }

            recstack[i] = false;
            return false;

    }

    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
         unordered_map<int, vector<int>> preqmap(numCourses);
        vector<bool> isvisited(numCourses, false);
        vector<bool> recstack(numCourses, false);

        for(auto pre : prerequisites) {
            preqmap[pre[0]].push_back(pre[1]);
        }

        // Run DFS from every unvisited node
        for (int i = 0; i < numCourses; i++) {
          if (!isvisited[i] && isCyclicUtil(preqmap, i, isvisited, recstack))
                return false;
         }

        return true;
    }
};
