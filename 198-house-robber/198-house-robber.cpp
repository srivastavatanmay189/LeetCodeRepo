class Solution {
public:
    int rob(vector<int>& nums) {
        for(int i = 1; i< nums.size(); i++){
            nums[ i ] = max(nums[i-1],nums[i]+ (i>1?nums[i-2]:0) );
        }
        return nums[nums.size()-1];
    }
};