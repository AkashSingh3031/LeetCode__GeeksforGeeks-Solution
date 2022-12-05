class Solution {
public:
    int reverse(int x) {
        long long a=0;
        while(x) {
            a = x%10 + a*10;
            x /= 10;
        }
        return (a > INT_MAX || a < INT_MIN) ? 0 : a;
    }
};