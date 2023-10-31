// LINK: https://practice.geeksforgeeks.org/problems/detect-cycle-in-an-undirected-graph/1

class Solution {
  public:
    bool dfs(vector<int> adj[], vector<int>& vis,int node,int parent){
        vis[node]=1;
        
        for(auto& x:adj[node]){
            if(!vis[x]){ 
                if(dfs(adj,vis,x,node)) return true;
            }
            else if(parent!=x)  return true;
        }
        return false;
    }
    bool isCycle(int V, vector<int> adj[]) {
        vector<int> vis(V,0);
        
        for(int i=0;i<V;i++){
            if(!vis[i]){
                if(dfs(adj,vis,i,-1))  return true;
            }
        }
        return false;
    }
};
