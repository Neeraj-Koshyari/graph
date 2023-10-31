// LINK: https://practice.geeksforgeeks.org/problems/topological-sort/1

class Solution
{
	public:
    vector<int> ans;
    void DFS(vector<int> g[], int node,vector<int>& vis){
        if(vis[node]==1)    
            return;
        vis[node]=1;
        for(int i=0;i<g[node].size();i++)
	        DFS(g,g[node][i],vis);
        ans.push_back(node);
    }
    
	vector<int> topoSort(int V, vector<int> adj[]) 
	{
	    // code here
	    vector<int> vis(V,0);
	    for(int i=0;i<V;i++)
	        DFS(adj,i,vis);
	    reverse(ans.begin(),ans.end());
	    return ans;
	}
};
