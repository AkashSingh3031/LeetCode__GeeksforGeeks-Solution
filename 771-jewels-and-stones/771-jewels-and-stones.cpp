class Solution {
public:
    int numJewelsInStones(string J, string S) {
        int res = 0;
        unordered_set<char> setJ(J.begin(), J.end());
        for (char s : S)
            if (setJ.count(s)) res++;
        return res;
    }
};