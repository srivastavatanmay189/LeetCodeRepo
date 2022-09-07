class Solution {
public:
    bool dfs(vector<vector<int>>& graph, int st, vector<int>& col, int cl){
        if(col[st] == -1)col[st] = cl;
        else return col[st]==cl;
        
        for(auto x : graph[st]){
            if(!dfs(graph,x,col,1-cl))return false;
        }
        return true;
    }
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int>col(n,-1);
        
        for(int i = 0; i<n; i++){
            if(col[i]==-1){
                if(!dfs(graph,i,col,0))return false;
            }
        }
        return true;
    }
};