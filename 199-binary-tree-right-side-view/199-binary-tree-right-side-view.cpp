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
//     void helper(TreeNode* root,vector<int>&ans,int &level){
//         if(root==NULL) return ;
        
//         helper(root->right,ans,level+1);
//         helper(root->left,ans,level+1);
        
        
        
        
        
        
    
    vector<int> rightSideView(TreeNode* root) {
        if(!root){
            return {};
        }
        vector<int> ans;
        queue<TreeNode*> q;
        q.push(root);
        // bool flag =true;
        while(!q.empty()){
            vector<int> level;
            int s=q.size();
            ans.push_back(q.front()->val);
            while(s--){
                TreeNode* m= q.front();
                q.pop();
                if(m->right)q.push(m->right);
                if(m->left) q.push(m->left);
                level.push_back(m->val);
            }
            // if(flag) ans.push_back(level);
            // if(!flag) {
            //     reverse(level.begin(),level.end());
            //     ans.push_back(level);
            // }
            // flag =1-flag;
            
        }
        return ans;
        
        
    }
};