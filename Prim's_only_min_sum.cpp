// LINK: https://practice.geeksforgeeks.org/problems/minimum-spanning-tree/1
// This code only calculate the minimum sum.

class Solution
{
	public:
    int spanningTree(int V, vector<vector<int>> adj[])
    {
        int ans=0;
        vector<int> vis(V,0);
        
        set<pair<int,int>> st;
        st.insert({0,0});
        
        while(st.size()){
            auto node=*st.begin();
            st.erase(st.begin());
            
            int u=node.second;
            int d=node.first;
            
            if(vis[u])  continue;
            vis[u]=1;
            ans+=d;
            
            for(auto& x:adj[u]){
                if(!vis[x[0]]) st.insert({x[1],x[0]});
            }
        }
        
        return ans;
    }
};
