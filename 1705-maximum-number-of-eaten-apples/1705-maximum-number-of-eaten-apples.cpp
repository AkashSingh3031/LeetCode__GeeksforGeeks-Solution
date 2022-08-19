class Solution {
public:
    typedef pair<int, int> P; // {last date before expiration, number of apples}
    int eatenApples(vector<int>& apples, vector<int>& days) {
        int ans = 0, n = apples.size();
		// min heap, the pair with the smallest expiration date is on the top
        priority_queue<P, vector<P>, greater<P>> que;
        int i = 0;
        while(i < n || que.size()){
			// add today's apples
            if(i < n && apples[i] > 0) que.push({i + days[i] - 1, apples[i]});
			
			// remove outdate apples
            while(que.size() && que.top().first < i) que.pop();
			
			// get the apple that can be eat today
            if(que.size()){
                auto p = que.top();
                que.pop();
                if(p.second > 1) que.push({p.first, p.second - 1});
                ++ans;
            }
            
            ++i;
        }
        return ans;
    }
};