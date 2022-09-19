class Solution {
public:
    bool pyramidTransition(string bottom, vector<string>& allowed) {
        unordered_set<string> invalid;
        // 7 characters from A to G, size 49 is sufficient.
        vector<vector<char>> edges(49);
        for (string& s: allowed) {
            int key = (s[0]-'A')*7+s[1]-'A';
            edges[key].push_back(s[2]);
        }
        return helper(invalid, bottom, edges);
    }
private:
    bool helper(unordered_set<string>& invalid, string& bottom, vector<vector<char>>& edges) {
        if (bottom.size() <= 1) return true;
        if (invalid.count(bottom)) return false;
        int n = bottom.size();
        // early termination if next level string is impossible
        for (int i = 0; i < n-1; i++) {
            int key = (bottom[i]-'A')*7+bottom[i+1]-'A';
            if (edges[key].empty()) {
                invalid.insert(bottom);
                return false;
            }
        }
        // try all possible strings (from backtracking) of next level
        string path(n-1, 'A');
        if (dfs(invalid, bottom, edges, path, 0)) return true;
        invalid.insert(bottom);
        return false;
    }
    bool dfs(unordered_set<string>& invalid, string& s, vector<vector<char>>& edges, string& path, int idx) {
        // find a possible string of next level
        if (idx+1 == s.size()) return helper(invalid, path, edges);
        int key = (s[idx]-'A')*7+s[idx+1]-'A'; 
        for (char c: edges[key]) {
            path[idx] = c;
            if (dfs(invalid, s, edges, path, idx+1)) return true;
        }
        return false;
    }
};