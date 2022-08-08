class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        double sum=0;
        double max_sum=0;
        int i=0;
        for(;i<k;i++) //calculate the sum for first k values(intial window)
        {
            sum+=nums[i];
        }
        max_sum=sum;
        
        //now slide the window 
        //remove element from left and add from right 
        //make note of max sum
        int j=0;
        while(i<nums.size())
        {
            sum-=nums[j++];
            sum+=nums[i++];
            max_sum=max(max_sum,sum);
        }
        return max_sum/k;
    }
};