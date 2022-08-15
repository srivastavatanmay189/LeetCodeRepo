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
    long prev = LONG_MIN;
    
    bool check(TreeNode* root){
        if(!root)return true;
        
        bool ans = check(root->left);
        if(!ans || root->val <= prev)return false;
        prev = root->val;
        return check(root->right);

    }
    bool isValidBST(TreeNode* root) {
        return check(root);
    }
};