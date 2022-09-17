class Solution {
    int n, k, v;
    vector<vector<bool> > visited;
    string sequence;
public:
    string crackSafe(int n, int k) {
        if (k == 1) return string(n, '0');
        this->n = n;
        this->k = k;
        v = 1;
        for (int i = 0; i < n -1; ++i) v *= k;
        visited.resize(v, vector<bool>(k, false));
        dfs(0);
        return sequence + sequence.substr(0, n - 1);
    }
    
    void dfs(int u) {
        for (int i = 0; i < k; ++i) {
            if (!visited[u][i]) {
                visited[u][i] = true;
                dfs((u * k + i) % v);
                sequence.push_back('0' + i);
            }
        }
    }
};