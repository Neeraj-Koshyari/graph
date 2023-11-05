// LINK: https://practice.geeksforgeeks.org/problems/bipartite-graph/1Bipartite

class Solution {
public:
    bool ans=true;
    void do_color(int node,vector<int> adj[],vector<int>& vis,vector<int>& color,int node_color){
        if(color[node]!=-1 && color[node]!=node_color){
            ans=false;
            return;
        }
        
        color[node]=node_color;
        if(vis[node]==1)    return;
        
        vis[node]=1;
        
        for(int i=0;i<adj[node].size();i++){
            do_color(adj[node][i],adj,vis,color,node_color^1);
        }
    }
	bool isBipartite(int V, vector<int>adj[]){
	    // Code here
	    vector<int> vis(V,0),color(V,-1);
	    for(int i=0;i<V;i++){
	        if(vis[i]!=1)
	            do_color(i,adj,vis,color,0);
	    }
	    return ans;
	}

};
