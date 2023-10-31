// LINK: https://practice.geeksforgeeks.org/problems/detect-cycle-in-a-directed-graph/1

class Solution {
  public:
    bool isCyclic(int V, vector<int> adj[]) {
        // code here
        vector<int> inEdge(V,0);
        
        for(int i=0;i<V;i++){
            for(auto& x:adj[i]) inEdge[x]++;
        }
        
        queue<int> qu;
        for(int i=0;i<V;i++){
            if(inEdge[i]==0)    qu.push(i);
        }
        
        int count=0;
        while(qu.size()){
            int node=qu.front();
            qu.pop();
            count++;
            
            for(auto& x:adj[node]){
                inEdge[x]--;
                if(inEdge[x]==0)  qu.push(x);
            }
        }
        
        if(count!=V)    return true;
        return false;
    }
};
