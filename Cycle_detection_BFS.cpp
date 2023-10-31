// LINK: https://practice.geeksforgeeks.org/problems/detect-cycle-in-an-undirected-graph/1

class Solution {
  public:
    bool isCycle(int V, vector<int> adj[]) {
        // Code here
        vector<int> vis(V,0);
        
        for(int i=0;i<V;i++){
            if(vis[i])  continue;
            queue<pair<int,int>> qu;
            qu.push({i,-1});
            vis[i]=1;
        
            while(qu.size()){
                int node=qu.front().first;
                int pnt=qu.front().second;
                qu.pop();
                
                for(auto& x:adj[node]){
                    if(!vis[x]){
                        qu.push({x,node});
                        vis[x]=1;
                    }
                    else if(pnt!=x)    return true;
                }
            }
        }
        return false;
    }
};
