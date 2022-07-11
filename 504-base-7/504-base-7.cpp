class Solution {
public:
    string convertToBase7(int n) {
        if (n < 0) return "-" + convertToBase7(-n);
        if (n < 7) return to_string(n);
        return convertToBase7(n / 7) + to_string(n % 7);
    }
};