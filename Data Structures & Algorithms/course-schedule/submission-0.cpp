class Solution {
public:
    unordered_map<int, vector<int>> pre;
    unordered_map<int, bool> visiting;

    bool dfs(int i) {
        if (visiting[i]) return false;

        if (pre[i].empty()) return true;

        visiting[i] = true;

        for (auto x : pre[i]) {
            if (!dfs(x)) return false;
        }

        visiting[i] = false;
        pre[i].clear();

        return true;
    }

    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        for (int i = 0; i < numCourses; i++) {
            pre[i] = {};
            visiting[i] = false;
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