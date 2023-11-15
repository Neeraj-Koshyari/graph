// Question Link: https://practice.geeksforgeeks.org/problems/strongly-connected-components-kosarajus-algo/1?utm_source=geeksforgeeks&utm_medium=ml_article_practice_tab&utm_campaign=article_practice_tab
// Explanation by Striver
// Link:  https://www.youtube.com/watch?v=R6uoSjZ2imo&list=PLgUwDviBIf0oE3gA41TKO2H5bHpPd7fzn&index=54&ab_channel=takeUforward


class Solution
{
	public:

	void topo_sort(int node,vector<vector<int>>& adj, vector<int>& vis,stack<int>& st){
	    vis[node]=1;
	    for(auto& x:adj[node]){
	        if(!vis[x]) topo_sort(x,adj,vis,st);
	    }
	    st.push(node);
	}
	
	vector<vector<int>> reverseGraph(vector<vector<int>>& adj,int V){
	    vector<vector<int>> nadj(V);
	    
	    for(int i=0;i<V;i++){
	        for(auto& x:adj[i]) nadj[x].push_back(i);
	    }
	    
	    return nadj;
	}
	
	void DFS(int node,vector<vector<int>>& nadj,vector<int>& vis){
	    vis[node]=1;
	    for(auto& x:nadj[node]){
	        if(!vis[x]) DFS(x,nadj,vis);
	    }
	}
	
    int kosaraju(int V, vector<vector<int>>& adj)
    {
        stack<int> st;
        vector<int> vis(V,0);
        
        //step1: Sort according to their finishing time using Topological sort
        for(int i=0;i<V;i++){
            if(!vis[i]) topo_sort(i,adj,vis,st);
        }
        
        
        //Step2: Reverse all the edges
        vector<vector<int>> nadj=reverseGraph(adj,V);
      
        
        //Step3: Od DFS according to Topo_sort path
        int count=0;            // To count the number of SCC
        vis=vector<int>(V,0);
        while(st.size()){
            int x=st.top();
            st.pop();
            
            if(!vis[x]){
                DFS(x,nadj,vis);
                count++;
            }
        }
        
        return count;
    }
};
