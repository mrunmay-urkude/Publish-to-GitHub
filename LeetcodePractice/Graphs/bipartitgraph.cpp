class Solution {
public:
    bool dfs(int node,int clr,vector<vector<int>>& graph,vector<int>& color){
        color[node]=clr;
        for(int nbr:graph[node]){
            if(color[nbr]==-1){
                if(!dfs(nbr,!clr,graph,color))
                    return false;
            }
            else if(color[nbr]==clr){
                return false;
            }
        }
        return true;
    }
    bool isBipartite(vector<vector<int>>& graph) {
        int n=graph.size();
        vector<int> color(n,-1);
        for(int i=0;i<n;i++){
            if(color[i]==-1){
                if(!dfs(i,0,graph,color))
                    return false;
            }
        }
        return true;
    }
};