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
    
    int ht(TreeNode* root){
        if(!root)return 0;
        return 1+max(ht(root->left),ht(root->right));
    }
    int dia(TreeNode* root){
        if(!root)return 0;
        
        int lh = ht(root->left);
        int rh = ht(root->right);
        
        return max(lh+rh+1,max(dia(root->left),dia(root->right)));
    }
    int diameterOfBinaryTree(TreeNode* root) {
        return dia(root)-1;
    }
};