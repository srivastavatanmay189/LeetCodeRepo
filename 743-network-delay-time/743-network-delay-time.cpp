class Solution {
public:
  
// recursion would cause TLE as we have to explore all the paths
    void dfs(vector<vector<pair<int,int>>>& graph, int sv, vector<int>& vis, vector<int>& dist){
        if(vis[sv])return;
        vis[sv] = 1;
        
        for(auto x: graph[sv]){
            if(dist[x.first] > dist[sv]+x.second){
               dist[x.first] = min(dist[x.first], dist[sv]+x.second);
               dfs(graph, x.first, vis, dist);
            }
        }
        vis[sv] = 0;
    }
    
    void bfs(vector<vector<pair<int,int>>>& graph, int sv, vector<int>& vis, vector<int>& dist){
        
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
        pq.push({0,sv});
        
        while(!pq.empty()){
            pair<int,int> t = pq.top();
            pq.pop();
            
            for(int i = 0 ; i<graph[t.second].size() ; i++){
                if(dist[graph[t.second][i].first] > t.first + graph[t.second][i].second){
                    dist[graph[t.second][i].first] =  t.first + graph[t.second][i].second;
                   pq.push({dist[graph[t.second][i].first],graph[t.second][i].first});
                }
            }
        }
        return ;
    }
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<int>dist(n, INT_MAX);
        vector<int>vis(n,0);
        vector<vector<pair<int,int>>>graph(n);
        
        for(int i = 0; i< times.size(); i++){
            graph[times[i][0]-1].push_back({times[i][1]-1,times[i][2]});
        }
        
        dist[k-1] = 0;
        bfs(graph,k-1,vis, dist);
        
        int ans = -1;
        for(int i= 0; i<n; i++){
            ans = max(ans, dist[i]);
        }
        return ans==INT_MAX?-1:ans;
    }
};