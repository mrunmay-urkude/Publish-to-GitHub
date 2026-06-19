class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n=graph.size();
        vector<vector<int>> rev(n);
        vector<int> indegree(n,0);
        for(int i=0;i<n;i++){
            for(int ngbr:graph[i]){
                rev[ngbr].push_back(i);
                indegree[i]++;
            }
        }
        queue<int> q;
        for(int i=0;i<n;i++){
            if(indegree[i]==0){
                q.push(i);
            }
        }
        vector<int> ans;
        while(!q.empty()){
            int node=q.front();
            q.pop();
            ans.push_back(node);
            for(int ngbr:rev[node]){
                indegree[ngbr]--;
                if(indegree[ngbr]==0){
                    q.push(ngbr);
                }
            }
        }
        sort(ans.begin(),ans.end());
        return ans;
    }
};