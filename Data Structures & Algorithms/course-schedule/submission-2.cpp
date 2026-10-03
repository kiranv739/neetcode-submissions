class Solution {
public:
    unordered_map<int, vector<int>> pre;
    unordered_map<int, bool> visited;

    bool dfs(int i) {
        if (visited[i]) return false;

        if (pre[i].empty()) return true;

        visited[i] = true;

        for (auto x : pre[i]) {
            if (!dfs(x)) return false;
        }

        visited[i] = false;
        pre.erase(i);

        return true;
    }

    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        for (int i = 0; i < numCourses; i++) {
            pre[i] = {};
            visited[i] = false;
        }

        for (auto x : prerequisites) {
            pre[x[0]].push_back(x[1]);
        }

        for (int i = 0; i < numCourses; i++) {
            if (!dfs(i)) return false;
        }

        return true;
    }
};