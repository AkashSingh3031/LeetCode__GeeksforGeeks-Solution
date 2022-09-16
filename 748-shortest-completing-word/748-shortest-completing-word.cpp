#include <vector>
#include <string>
#include <limits>

using namespace std;

class Solution {
public:
    string shortestCompletingWord(string licensePlate, vector<string>& words) {
        vector<int> cntlic(26, 0);
        for (auto ch : licensePlate) {
            if (isalpha(ch)) {
                ++cntlic[tolower(ch) - 'a'];
            }
        }
        
        int minL = numeric_limits<int>::max();
        string res;
        for (auto& str : words) {
            vector<int> cnt(26, 0);
            for (auto ch : str) {
                ++cnt[ch - 'a'];
            }
            
            bool complete = true;
            for (int i = 0; i < 26; ++i) {
                if (cnt[i] < cntlic[i]) {
                    complete = false;
                    break;
                }
            }
            
            if (complete && str.length() < (size_t)minL) {
                res = str;
                minL = str.length();
            }
        }
        
        return res;
    }
};