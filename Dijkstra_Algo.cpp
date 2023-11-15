// LINK: https://practice.geeksforgeeks.org/problems/implementing-dijkstra-set-1-adjacency-matrix/1

class Solution
{
	public:
	   
    vector <int> dijkstra(int V, vector<vector<int>> adj[], int S)
    {
        priority_queue<pair<int,int>,vector<pair<int,int>>, greater<pair<int,int>>> qu;
        vector<int> dis(V,1e9);
        dis[S]=0;
        qu.push({0,S});
        
        while(qu.size()){
            int d=qu.top().first;
            int u=qu.top().second;
            qu.pop();
            
            for(auto& x:adj[u]){
                int v=x[0];
                int wt=x[1];
                
                if(dis[v]>(d+wt)){
                    dis[v]=(d+wt);
                    qu.push({dis[v],v});
                }
            }
        }
        return dis;
    }
};
