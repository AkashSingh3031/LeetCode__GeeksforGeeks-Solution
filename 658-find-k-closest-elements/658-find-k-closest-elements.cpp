class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        multimap< int , int> mp;
        int n=arr.size();
        for(int i=0;i<n;i++)
        {
            int val=abs(x-arr[i]);
           mp.insert({val , arr[i]});
        }
        
        vector<int> res;
        for(auto it=mp.begin();it!=mp.end();it++)
        {
             if(res.size()==k)
             {
                 break;
             }
            
             res.push_back(it->second);
        }
        
        sort(res.begin(),res.end());
        
        return res;
    }
};