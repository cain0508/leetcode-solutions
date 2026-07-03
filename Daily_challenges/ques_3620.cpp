class Solution {
    private:
    bool feasible(int n,vector<vector<int>> & edges,vector<bool> &online,long long k,int mincost){
        vector<vector<pair<int,int>>> adj(n);
        for(auto& e:edges){
            if(e[2]>= mincost){
                adj[e[0]].push_back({e[1],e[2]});
            }
        }

            priority_queue<pair<long long ,int>,vector<pair<long long, int>>,greater<pair<long long , int>>> pq;

            vector<long long> dist(n,LLONG_MAX);
            dist[0]=0;
            pq.push({0,0});
            while(!pq.empty()){
                auto[cost,u]=pq.top();pq.pop();
                if(cost>dist[u]) continue;
                if(u==n-1) return dist[n-1] <=k;
                for(auto& [v,w]:adj[u]){
                    if(v!=n-1&&!online[v]) continue;

                    long long newCost = dist[u]+w;
                    if(newCost<dist[v]){
                        dist[v]=newCost;
                        pq.push({newCost,v});
                    }
                }
            }
            return dist[n-1]<=k;
        }
public:
    int findMaxPathScore(vector<vector<int>>& edges, vector<bool>& online, long long k) {
        int n = online.size();
        vector<int> costs;
        for(auto& e:edges)
        costs.push_back(e[2]);
        sort(costs.begin(),costs.end());
        costs.erase(unique(costs.begin(),costs.end()),costs.end());

        int low = 0 , high = costs.size()-1 , ans = -1;

        while(low<=high){
            int mid = low +(high-low)/2;
            int mincost = costs[mid];

            if(feasible(n,edges,online,k,mincost)){
                ans= mincost;
                low = mid+1;
            }else{
                high = mid - 1;
            }
        }
        return ans;
    }
};