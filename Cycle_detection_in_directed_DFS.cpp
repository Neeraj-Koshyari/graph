// LINK: https://practice.geeksforgeeks.org/problems/detect-cycle-in-a-directed-graph/1

class Solution {
  public:
    bool dfs(vector<int> adj[], vector<int>& vis, vector<int>& vp,int node){
        vis[node]=1;
        vp[node]=1;
        
        for(auto& x:adj[node]){
            if(!vis[x]){
                if(dfs(adj,vis,vp,x))   return true;
            }
            else if(vp[x])   return true;
        }
        vp[node]=0;
        return false;
    }
    bool isCyclic(int V, vector<int> adj[]) {
        // code here
        vector<int> vis(V,0),vp(V,0);
        
        for(int i=0;i<V;i++){
            if(!vis[i]){
                if(dfs(adj,vis,vp,i)) return true;
            }
        }
        return false;
    }
};
