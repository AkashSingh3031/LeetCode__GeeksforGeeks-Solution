class Solution {
public:
    vector<int> v;
    std::mt19937 gen;
    std::uniform_int_distribution<> dis;
    Solution(int N, vector<int> blacklist) {
        v = blacklist;
        sort(v.begin(), v.end());
        v.push_back(N);
        for (int i = 0; i < v.size(); i++) v[i] -= i;
        
        std::random_device rd;  //Will be used to obtain a seed for the random number engine
        gen = std::mt19937(rd()); //Standard mersenne_twister_engine seeded with rd()
        dis = std::uniform_int_distribution<>(0, N - v.size());
    }
    
    int pick() {
        int rnd = dis(gen);
        auto it = upper_bound(v.begin(), v.end(), rnd) - 1;
        int idx = it - v.begin();
        return idx + rnd + 1;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(n, blacklist);
 * int param_1 = obj->pick();
 */