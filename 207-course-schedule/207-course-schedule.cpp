class Solution {
public:
    
    bool check(vector<vector<int>>& graph, int sv, vector<int>& vis){
        if(vis[sv] == 1)return false;
        vis[sv] = 2;
        for(auto x : graph[sv]){
            if(vis[x] == 2 ){
                return true;
            }else if(check(graph, x, vis)){
                return true;
            }
        }
        vis[sv] = 1;
        return false;
    }
    bool canFinish(int n, vector<vector<int>>& pre) {
        vector<int> vis(n,0);
        vector<vector<int>>graph(n);
        
        for(int i = 0; i< pre.size(); i++){
            graph[pre[i][0]].push_back(pre[i][1]);
        }
        for(int i = 0 ; i<n; i++){
            if(!vis[i] && check(graph, i, vis)){
                return false;
            }
        }
        return true;
    }
};