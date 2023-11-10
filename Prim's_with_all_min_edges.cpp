//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
	public:
	//Function to find sum of weights of edges of the Minimum Spanning Tree.
    vector<pair<pair<int,int>,int>> spanningTree(int V, vector<vector<int>> adj[])
    {
        // code here
        vector<int> vis(V,0);
        vector<pair<pair<int,int>,int>> edges;      //  {u, v, wt}
        
        set<pair<int,pair<int,int>>> st;      //  {wt, v, u}
        st.insert({0,{0,-1}});
        
        while(st.size()){
            auto node=*st.begin();
            st.erase(st.begin());
            
            int u=node.second.first;
            int parent=node.second.second;
            int wt=node.first;
            
            if(vis[u])  continue;
            vis[u]=1;
            if(parent!=-1) edges.push_back({{parent,u},wt});    //-1 because of first node (0) which has -1 as parent
            
            for(auto& x:adj[u]){
                if(!vis[x[0]]) st.insert({x[1],{x[0],u}});
            }
        }
        
        return edges;
    }
};

//{ Driver Code Starts.


int main()
{
    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;
        vector<vector<int>> adj[V];
        int i=0;
        while (i++<E) {
            int u, v, w;
            cin >> u >> v >> w;
            vector<int> t1,t2;
            t1.push_back(v);
            t1.push_back(w);
            adj[u].push_back(t1);
            t2.push_back(u);
            t2.push_back(w);
            adj[v].push_back(t2);
        }
        
        Solution obj;
    	vector<pair<pair<int,int>,int>> ans = obj.spanningTree(V, adj);

      for(auto& x:ans){
        cout<<x.first.first<<" "<<x.first.second<<" "<<x.second<<endl;    // {u, v, wt}
    }

    return 0;
}
// } Driver Code Ends

/*
input:
  5 6
  0 1 2
  0 2 1
  1 2 1
  2 4 2
  2 3 2
  4 3 1

output:  
  0 2 1
  2 1 1
  2 3 2
  3 4 1    
*/
