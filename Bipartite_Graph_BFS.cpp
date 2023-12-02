// LINK:	https://leetcode.com/problems/is-graph-bipartite/submissions/1081429576/

class Solution {
public:
    bool bfs(vector<vector<int>>& g,vector<int>& color,int type,int node){
        queue<pair<int,int>> qu;
        qu.push({type,node});

        while(qu.size()){
            int ty=qu.front().first;
            int nod=qu.front().second;
            color[nod]=ty;
            qu.pop();

            for(auto& x:g[nod]){
                if(color[x]==-1)    qu.push({ty^1,x});
                else if(color[x]==ty)   return false;
            }
        }
        return true;
    }

    bool isBipartite(vector<vector<int>>& g) {
        vector<int> color(g.size(),-1);

        for(int i=0;i<g.size();i++){
            if(color[i]==-1){
                if(!bfs(g,color,0,i))  return false;
            }
        }
        return true;
    }
};
