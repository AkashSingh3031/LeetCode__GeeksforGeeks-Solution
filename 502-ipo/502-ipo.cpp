class Solution {
public:
    int findMaximizedCapital(int k, int W, vector<int>& P, vector<int>& C) {
          priority_queue<int> low;      // P[i]'s within current W
          multiset<pair<int,int>> high; // (C[i],P[i])'s' outside current W

          for (int i = 0; i < P.size(); ++i) // initialize low and high
            if(P[i] > 0) if (C[i] <= W) low.push(P[i]); else high.emplace(C[i], P[i]);

          while (k-- && low.size()) { 
            W += low.top(), low.pop(); // greedy to work on most profitable first
            for (auto i = high.begin(); high.size() && i->first <= W; i = high.erase(i)) low.push(i->second);
          }
          return W;
    }
};