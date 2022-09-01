class Solution {
public:
    struct pairHash {
      size_t operator()(const pair<int, int> &x) const { return x.first ^ x.second; }
    };
    vector<int> gridIllumination(int N, vector<vector<int>>& lamps, vector<vector<int>>& queries) {
      vector<int> res;
      unordered_map<int, int> x, y, a_d, d_d;
      unordered_set<pair<int, int>, pairHash> ls;
      for (auto l : lamps) {
        auto i = l[0], j = l[1];
        if (ls.insert({ i, j }).second) ++x[i], ++y[j], ++a_d[i + j], ++d_d[i - j];
      }
      for (auto q : queries) {
        auto i = q[0], j = q[1];
        if (x[i] || y[j] || a_d[i + j] || d_d[i - j]) {
          res.push_back(1);
          for (int li = i - 1; li <= i + 1; ++li)
            for (int lj = j - 1; lj <= j + 1; ++lj) {
              if (ls.erase({li, lj})) {
                --x[li], --y[lj], --a_d[li + lj], --d_d[li - lj];
              }
            }
        }
        else res.push_back(0);
      }
      return res;
    }
};