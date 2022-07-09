class Solution {
public:
    int m,n;
    vector <int> parent;
    vector <int> rank;
    vector <int> size;
    
    int find(int x){
        if (parent[x]!=x) parent[x]=find(parent[x]);
        return parent[x];
    }
    
    void Union(int x,int y){
        int r1=find(x);
        int r2=find(y);
        if (r1!=r2){
            if (rank[r1]>rank[r2]){
                parent[r2]=r1;
                size[r1]+=size[r2];
            }
            else if (rank[r2]>rank[r1]){
                parent[r1]=r2;
                size[r2]+=size[r1];
            }
            else{
                parent[r2]=r1;
                size[r1]+=size[r2];
                rank[r1]++;
            }
        }
    }
    void unionAround(int i,int j,vector<vector<int>>& grid){
        int seq=i*n+j+1;
        vector <pair<int,int>> directions={{0,1},{0,-1},{-1,0},{1,0}};
        for (auto &d: directions){
            int ni=i+d.first,nj=j+d.second;
            if (ni>=0 && ni<m && nj>=0 && nj<n && grid[ni][nj]==1){
                int new_seq=ni*n+nj+1;
                Union(seq,new_seq);
            }
        }
        if (i==0) Union(0,seq);
    }
    vector<int> hitBricks(vector<vector<int>>& grid, vector<vector<int>>& hits) {
        ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
        m=grid.size();
        n=grid[0].size();
        int hitCnt=hits.size();
        vector <int> Size(m*n+1,1);
        size=Size;
        size[0]=0;
        vector <int> Parent(m*n+1,0);
        parent=Parent;
        for (int i=0;i<=m*n;i++) parent[i]=i;
        vector <int> Rank(m*n+1,0);
        rank=Rank;
        vector <int> ans(hitCnt,0);
        for (auto &v: hits){
            int x=v[0],y=v[1];
            if (grid[x][y]==1) grid[x][y]=2;
        }
        for (int i=0;i<m;i++){
            for (int j=0; j<n;j++){
                if (grid[i][j]==1) unionAround(i,j,grid);
            }
        }
        int currCnt=size[find(0)];
        for (int i=hitCnt-1; i>=0; i--){
            int x=hits[i][0],y=hits[i][1];
            if (grid[x][y]==2){
                grid[x][y]=1;
                unionAround(x,y,grid);
                int newCnt=size[find(0)];
                if (newCnt>currCnt) ans[i]=newCnt-currCnt-1;
                currCnt=newCnt;
            }
        }
        return ans;
    }
};