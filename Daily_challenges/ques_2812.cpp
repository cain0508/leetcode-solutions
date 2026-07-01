class Solution {
public:
    int maximumSafenessFactor(vector<vector<int>>& grid) {
        //using multi level bfs and for maximum safeness using dijkstra with max heap
        int n = grid.size();
        vector<vector<int>> dist(n,vector<int>(n,-1));
        queue<pair<int,int>> q;
        for(int i =0;i<n;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==1){
                    dist[i][j]=0;
                    q.push({i,j});
                }
            }
        }

        //multi level bfs right +1 left -1 up -1 down +1
        int dirs[4][2]={{0,1},{0,-1},{1,0},{-1,0}};
        while(!q.empty()){
            auto[r,c] = q.front();q.pop();
            for(auto& d: dirs){
                int nr = r+d[0];
                int nc = c+d[1];
                if(nr >=0&& nr<n &&nc>=0 && nc<n && dist[nr][nc]==-1){
                    dist[nr][nc] = dist[r][c]+1;
                    q.push({nr,nc});
                }
            }
        }
        //dijkstra with max_heap
        priority_queue<tuple<int,int,int>> pq;
        vector<vector<bool>> visited(n,vector<bool>(n,false));
        pq.push({dist[0][0],0,0});
        visited[0][0]=true;
        while(!pq.empty()){
            auto[safe,r,c]=pq.top();pq.pop();
            if(r==n-1&&c==n-1) return safe;
            for(auto& d:dirs){
                int nr = r+d[0];
                int nc = c+d[1];
                if(nr>=0&&nr<n&&nc>=0&&nc<n&&!visited[nr][nc]){
                    int newsafe = min(safe,dist[nr][nc]);
                    pq.push({newsafe,nr,nc});
                    visited[nr][nc]=true;
                }
            }
        }
        return -1;
    }
};