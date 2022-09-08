class Solution {
public:
    int ans = 0;     
    int find(int n, int ct, vector<int>& vis){
        if(ct == n)return 1;
        
        int ans = 0;
        for(int i = 1; i<=n; i++){
            if(!vis[i]){
                vis[i] = 1;
                if( i % (ct+1) == 0 || (ct+1)%i == 0)
                  ans += find(n, ct+1, vis);
                vis[i] = 0;
            }
        }
        return ans;
    }
    
    int countArrangement(int n) {
        vector<int>vis(n+1,0);
        return find(n, 0, vis);
    }
};