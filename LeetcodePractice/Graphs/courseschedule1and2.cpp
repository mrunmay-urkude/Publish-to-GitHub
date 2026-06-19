class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& pre) {
        vector<vector<int>> adj(numCourses);
        vector<int> indegree(numCourses,0);
        for(auto &it:pre){
            int a=it[0];
            int b=it[1];
            adj[b].push_back(a);
            indegree[a]++;
        }
        queue<int> q;
        for(int i=0;i<numCourses;i++){
            if(indegree[i]==0){
                q.push(i);
            }
        }
        int cnt=0;
        while(!q.empty()){
            int node=q.front();
            q.pop();
            cnt++;
            for(auto ngbr:adj[node]){
                indegree[ngbr]--;
                if(indegree[ngbr]==0){
                    q.push(ngbr);
                }
            }
        }
        return cnt==numCourses;
    }
};

class Solution {
public:

/*
vector<vector<int>> allOrders;
void topo(vector<vector<int>>& adj,vector<int>& indegree,vector<int>& vis,vector<int>& curr){
    bool found=false;
    for(int i=0;i<adj.size();i++){
        if(!vis[i] && indegree[i]==0){
            vis[i]=1;
            curr.push_back(i);
            for(int ngbr:adj[i])indegree[ngbr]--;
            topo(adj,indegree,vis,curr);
            for(int ngbr:adj[i])indegree[ngbr]++;
            curr.pop_back();
            vis[i]=0;
            found=true;
        }
    }
    if(!found)allOrders.push_back(curr);
}
*/
    vector<int> findOrder(int numCourses, vector<vector<int>>& pre) {
        vector<vector<int>> adj(numCourses);
        vector<int> indegree(numCourses,0);
        for(int i=0;i<pre.size();i++){
            int a=pre[i][0];
            int b=pre[i][1];
            adj[b].push_back(a);
            indegree[a]++;
        }
        queue<int>q;
        for(int i=0;i<indegree.size();i++){
            if(indegree[i]==0)q.push(i);
        }
        vector<int>topo;
        while(!q.empty()){
            int node=q.front();
            q.pop();
            topo.push_back(node);
            for(int i:adj[node]){
                indegree[i]--;
                if(indegree[i]==0)q.push(i);
            }
        }
        if(topo.size()==numCourses)return topo;
        return {};
    }
};