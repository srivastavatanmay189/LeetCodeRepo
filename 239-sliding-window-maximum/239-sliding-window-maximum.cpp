class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<pair<int,int>>dq;
        int n = nums.size();
        
        for(int i = 0; i<k-1; i++){
            while(!dq.empty() && dq.back().first<= nums[i]){
                dq.pop_back();
            }
            dq.push_back({nums[i],i});
        }
        
        vector<int>res;
        for(int i = k-1; i<n; i++){
            while(!dq.empty() && dq.back().first<= nums[i]){
                dq.pop_back();
            }
            dq.push_back({nums[i],i});
            while(!dq.empty() && i- dq.front().second+1 > k){
                dq.pop_front();
            }
            res.push_back(dq.front().first);
        }
        return res;
    }
};