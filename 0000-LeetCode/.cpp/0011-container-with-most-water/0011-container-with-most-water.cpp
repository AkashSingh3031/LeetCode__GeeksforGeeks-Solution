class Solution {
public:
    int maxArea(vector<int>& height) {
        int n = height.size();
        int l=0, r=n-1;
        int maxArea = (r-l)*min(height[l], height[r]);
        while(l < r) {
            if(height[l] < height[r])
                l++;
            else
                r--;
            maxArea = max(maxArea, (r-l)*min(height[l], height[r]));
        }
        return maxArea;
    }
};