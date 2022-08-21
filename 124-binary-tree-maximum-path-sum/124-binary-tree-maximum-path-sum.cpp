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
    
    int find(TreeNode* root, int& ans){
        if(!root)return 0;
        int lsum = find(root->left,ans);
        int rsum = find(root->right,ans);

        int dia = lsum+rsum+root->val;
        int lt = lsum+root->val;
        int rt = rsum+root->val;
        
        ans = max(ans, max(max(root->val,dia), max(lt,rt)));
        return max(root->val, root->val + max(lsum ,rsum));
    }
    
    int maxPathSum(TreeNode* root) {
        int ans = INT_MIN;
        return max(ans,find(root,ans));
    }
};