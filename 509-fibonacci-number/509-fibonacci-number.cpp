class Solution {
public:
    int fib(int n) {
        if(n==0 || n==1)
            return n;
        while(n>1){
            n = fib(n-1) + fib(n-2);
            return n;
        }
        return -1;
    }
};