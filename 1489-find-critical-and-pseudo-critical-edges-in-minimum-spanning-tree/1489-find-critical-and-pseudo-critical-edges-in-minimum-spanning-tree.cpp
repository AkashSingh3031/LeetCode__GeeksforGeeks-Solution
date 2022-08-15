class Solution {
public:
    int findPar(int x, vector<int> &parent)
    {
        while(x != parent[x])
            x = parent[x];
        return x;
    }
    void unionn(int x, int y, vector<int> &parent, vector<int> &rank)
    {
        x = findPar(x,parent);
        y = findPar(y, parent);
        if(rank[x] < rank[y])
            parent[x] = y;
        else if(rank[x] > rank[y])
            parent[y] = x;
        else
        {
            parent[y] = x;
            rank[x]++;
        }
    }
    int MST(int &n, vector<vector<int>> &edges, vector<int> &include, vector<int> &exclude)//O(E)
    {
        int cost = 0;
        vector<int> rank(n,0);
        vector<int> parent(n);
        for(int i=0; i<n; i++)
            parent[i] = i;

//if my must include edge is not null then I will join them and add their cost if they do not have same component
        if(include.size() != 0)
        {
            if(findPar(include[0],parent) != findPar(include[1],parent))
            {
                unionn(include[0], include[1], parent, rank);
                cost += include[2];
            }
        }
        for(auto edge: edges)//O(E) as union find operation constant only for loop
        {
//if curr edge is not equal to must exclude vertex we will check further and do simple kruskal's method
            if(edge != exclude)
            {
                if(findPar(edge[0],parent) != findPar(edge[1],parent))
                {
                    unionn(edge[0],edge[1],parent,rank);
                    cost += edge[2];
                }
            }
        }
        //now if kruskal was not possbile by excluding any node, means all nodes can't be connected together then in that case we will return INF 
        
        for(int i=0; i<n; i++)
        {
            //means when all are not connected so return
            if(findPar(i,parent) != findPar(0,parent))
                return 1e5;
        }
        return cost;
    }
    static bool compare(vector<int> &a, vector<int> &b)
    {
        return a[2] < b[2];///sorting according to weigths in asc order
    }
    vector<vector<int>> findCriticalAndPseudoCriticalEdges(int n, 
    vector<vector<int>>& edges) 
    {
        vector<int> criticalEdge;
        vector<int> pseudoEdge;
        map<vector<int>,int> edgeIndex;
//map of edge and index as I want the indexes for the ans
        
        for(int i=0; i<edges.size(); i++)
        {
            edgeIndex[edges[i]] = i;
        }
        sort(edges.begin(), edges.end(), compare);//O(ElogE);
        
        vector<int> temp;
//empty vector which I am going to pass when I want the must include include edge null and same for must exclude edge
        
        int minCost = MST(n, edges, temp, temp);//min cost considering all edges

        for(auto edge: edges)//O(E^2)
        {
//I will check if by excluding and including current edge in the loop what effect it has on cost
            int exclude_cost = MST(n, edges,temp, edge);//(n,edges,include,exclude)
            if(exclude_cost > minCost)
                criticalEdge.push_back(edgeIndex[edge]);//means critical edge as by excluding it our cost gets increased
            else
            {
                int include_cost = MST(n,edges,edge,temp);
                if(include_cost == minCost)//means pseudoEdge as by excluding and including it doesn't effect our minCost 
                    pseudoEdge.push_back(edgeIndex[edge]);
            }
        }
        return {criticalEdge, pseudoEdge};//our final ans
        
        //hope you all understood it well :)
    }
};