class Solution {
public:
    
    vector<int>dp;
    bool check(string s, vector<string>& wd, int id){
        if(id == s.size())return true;
        if(dp[id] != -1)return dp[id];
        
        for(int i= 0; i<wd.size(); i++){
            if(id+wd[i].size() <= s.size() && s.substr(id,wd[i].size()) == wd[i]){
                if(check(s, wd, id+wd[i].size()))return dp[id] =  true;
            }
        }
        return dp[id] = false;
    }
    
    bool wordBreak(string s, vector<string>& wordDict) {
        dp = vector<int>(s.size(), -1);
        return check(s, wordDict,0);
    }
};