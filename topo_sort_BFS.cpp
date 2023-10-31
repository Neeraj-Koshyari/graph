// LINK: https://practice.geeksforgeeks.org/problems/topological-sort/1
// This method is also known as KAHN's algo

class Solution
{
	public:
	vector<int> topoSort(int V, vector<int> adj[]) 
	{
	    // code here
	    vector<int> inEdge(V,0);
	    
	    for(int i=0;i<V;i++){
	        for(auto& x: adj[i])
	            inEdge[x]++;
	    }	    
	    
	    queue<int> qu;
	    vector<int> ans;
	    
	    for(int i=0;i<V;i++){
	        if(inEdge[i]==0)
	            qu.push(i);
	    }
	    
	    while(qu.size()){
	        int node=qu.front();
	        qu.pop();
	        ans.push_back(node);
	        
	        for(auto& x:adj[node]){
	            inEdge[x]--;
	            if(inEdge[x]==0)
	                qu.push(x);
	        }
	    }
	    
	    return ans;
	}
};
