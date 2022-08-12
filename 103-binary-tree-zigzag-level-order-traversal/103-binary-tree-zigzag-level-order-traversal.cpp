/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        if(!root){
            return {};
        }
        vector<vector<int>> ans;
        queue<TreeNode*> q;
        q.push(root);
        bool flag =true;
        while(!q.empty()){
            vector<int> level;
            int s=q.size();
            while(s--){
                TreeNode* m= q.front();
                q.pop();
                if(m->left) q.push(m->left);
                if(m->right)q.push(m->right);
                level.push_back(m->val);
            }
            if(flag) ans.push_back(level);
            if(!flag) {
                reverse(level.begin(),level.end());
                ans.push_back(level);
            }
            flag =1-flag;
            
        }
        return ans;
      
    }
};