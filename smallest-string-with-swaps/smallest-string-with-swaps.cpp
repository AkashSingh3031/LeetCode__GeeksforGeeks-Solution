class Solution {
public:
    bool flag[100011];
    vector<int> vec[100001], pos;
    vector<char> allChars;
    string str;
    string smallestStringWithSwaps(string s, vector<vector<int>>& pairs) {
        int n = pairs.size();
        for(int i=0;i<n;i++)flag[i] = false;
        str = s;
        for(int i=0;i<n;i++){
            int u = pairs[i][0];
            int v = pairs[i][1];
            
            vec[u].push_back(v);
            vec[v].push_back(u);
        }
        
        for(int i=0;i<n;i++){
            if(!flag[i]){
                pos.clear();
                allChars.clear();
                dfs(i);
                
                sort(allChars.begin(), allChars.end());
                sort(pos.begin(), pos.end());
                
                for(int j=0;j<pos.size();j++){
                    str[ pos[j] ] = allChars[j];
                }
            }
        }
        
        return str;
    }
    
    void dfs(int nd){
        flag[nd] = true;
        allChars.push_back(str[nd]);
        pos.push_back(nd);
        
        for(auto v: vec[nd]){
            if(!flag[v]){
                dfs(v);
            }
        }
        
    }
};