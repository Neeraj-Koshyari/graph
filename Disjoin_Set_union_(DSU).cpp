// LINK: https://practice.geeksforgeeks.org/problems/union-find/1
// Explanation: https://www.youtube.com/watch?v=aBxjDBC4M1U&list=PLgUwDviBIf0oE3gA41TKO2H5bHpPd7fzn&index=46&ab_channel=takeUforward

class Solution
{
    public:
    //Function to find root of a node.
    int findRoot(int i, int par[]) 
    {
        //iterating to find the node whose par[i] is equal to i.
        while(i!=par[i]) {
            i = par[i];
        }
        return i;
    }
    
    //Function to merge two nodes a and b.
    void union_( int a, int b, int par[], int rank1[]) 
    {
        //find root of nodes a and b.
        int x = findRoot(a, par);
        int y = findRoot(b, par);
        
        //base case if they are already in same set.
        if(x==y)  return;
        
        //checking for rank, and putting in set with higher rank.
        if(rank1[x]>=rank1[y]) {
            rank1[x]++;
            par[y] = par[x];
        } else {
            rank1[y]++;
            par[x] = par[y];
        }
        return;
    }
    
    //Function to check whether 2 nodes are connected or not.    
    bool isConnected(int x,int y, int par[], int rank1[]) 
    {
        //if root of both nodes is same then they are connected.
        return (findRoot(x, par) == findRoot(y, par));
    }
};
