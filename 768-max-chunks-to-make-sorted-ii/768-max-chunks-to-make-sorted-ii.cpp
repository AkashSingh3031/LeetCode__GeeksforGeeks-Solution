class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        stack<int>st;
        for(int i=0;i<arr.size();i++) {
            int curmax=st.empty() ? arr[i]: max(st.top(),arr[i]);
            while( (!st.empty()) && (st.top()>arr[i]) ) st.pop();
            st.push(curmax);
        }
        return st.size();
    }
};