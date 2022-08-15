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
    pair<int,int> dia(TreeNode* root){
        if(!root)return {0,0};
        
        pair<int,int> lh = dia(root->left);
        pair<int,int> rh = dia(root->right);
        
        return {max(lh.second+rh.second+1,max(lh.first,rh.first)), 1+max(lh.second,rh.second)};
    }
    int diameterOfBinaryTree(TreeNode* root) {
        return dia(root).first-1;
    }
};