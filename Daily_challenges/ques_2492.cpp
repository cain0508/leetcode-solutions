class Solution {
public:
    int minScore(int n, vector<vector<int>>& roads) {
        vector<vector<pair<int,int>>> adj(n+1);
        //bidirectional adjacency for the graph 0->1->2->1->0->1->2
         for(auto& r:roads){
            adj[r[0]].push_back({r[1],r[2]});
            adj[r[1]].push_back({r[0],r[2]});
         }
         queue<int> q;
         vector<bool> visited(n+1,false);

         q.push(1);
         visited[1]=true;
         int ans = INT_MAX;
         while(!q.empty()){
            int u = q.front();q.pop();
            for(auto& [next,cost]:adj[u]){
                ans = min(ans,cost);
                if(!visited[next]){
                    visited[next]= true;
                    q.push(next);
                }
            }
         }
         return ans;
    }
};