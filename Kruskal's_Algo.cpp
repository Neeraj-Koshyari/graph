// LINK: https://www.geeksforgeeks.org/problems/minimum-spanning-tree/1

class Solution
{
	public:
	vector<int> par,rank;
	int find(int x){
	    if(par[x]==x)   return x;
	    return par[x]=find(par[x]);    //path compression
	}
	
	void UNION(int u,int v){
	    int pu=find(u),pv=find(v);
	    if(pu==pv)  return;
	    
	    if(rank[pu]<rank[pv]){
	        rank[pv]+=rank[pu];
	        par[pu]=pv;
	    }
	    else{
	        rank[pu]+=rank[pv];
	        par[pv]=pu;
	    }
	}
	
    int spanningTree(int V, vector<vector<int>> adj[])
    {
        // code here
        par.resize(V);
        rank.resize(V);
        
        for(int i=0;i<V;i++)    par[i]=i;        //initially all nodes are parent of itself
        
        int totalWt=0;
        vector<pair<int,pair<int,int>>> g;
        for(int i=0;i<V;i++){
            for(auto& x:adj[i])     g.push_back({x[1],{i,x[0]}});    //  all edges { wt, { u, v } }
        }
        
        sort(g.begin(),g.end());      //sort by weight
        
        for(auto& x:g){
            int wt=x.first;
            int u=x.second.first;
            int v=x.second.second;
            
            if(find(u)!=find(v)){
                totalWt+=wt;
                UNION(u,v);
            }
        }
        return totalWt;
    }
};
