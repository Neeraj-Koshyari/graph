// LINK: https://leetcode.com/problems/is-graph-bipartite/submissions/1081429576/

class Solution {
public:
    bool DFS(vector<vector<int>>& g, vector<int>& vis,vector<int>& color,int node,int col){
        if(vis[node]){
            if(color[node]!=col)    return false;
            return true;
        }
        vis[node]=1;
        color[node]=col;

        for(auto& x:g[node]){
            if(!DFS(g,vis,color,x,col^1)) return false;
        }
        return true;
    }

    bool isBipartite(vector<vector<int>>& g) {
        vector<int> vis(g.size(),0),color(g.size(),0);

        for(int i=0;i<g.size();i++){
            if(!vis[i]){
                if(!DFS(g,vis,color,i,0)) return false;
            }
        }
        return true;
    }
};
