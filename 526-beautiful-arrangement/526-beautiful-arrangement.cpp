class Solution {
public:
    int ans = 0;      
    void find(int n, int ct, vector<int>& vis){
        if(ct == n){
            ans++;
            return;
        }
        
        for(int i = 1; i<=n; i++){
            if(!vis[i]){
                vis[i] = 1;
                if( i % (ct+1) == 0 || (ct+1)%i == 0)
                  find(n, ct+1, vis);
                vis[i] = 0;
            }
        }
    }
    
    int countArrangement(int n) {
        vector<int>vis(n+1,0);
        
        find(n, 0, vis);
        return ans;
    }
};