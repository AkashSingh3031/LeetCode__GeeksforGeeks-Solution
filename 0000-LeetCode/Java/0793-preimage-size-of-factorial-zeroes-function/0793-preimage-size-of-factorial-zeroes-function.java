class Solution {
    public int preimageSizeFZF(int k) {
        long low = 0;
        long high = (long)Math.pow(10,10);
        
        while(low<=high){
            long mid  = low + (high-low)/2;
            long val = mid;
            long ans = 0;
            while(val!=0){
                val/=5;
                ans+=val;
            }
            if(ans==k){
                return 5;
            }else if(ans>k){
                high = mid-1;
            }else{
                low = mid+1;
            }
        }
        
        return 0;
    }
}