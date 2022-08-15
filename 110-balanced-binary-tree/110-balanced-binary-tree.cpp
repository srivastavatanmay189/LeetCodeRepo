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
    pair<bool,int> find(TreeNode* root){
        if(!root)return {true,0};
        
        pair<bool,int> lh = find(root->left);
        pair<bool,int> rh = find(root->right);
        
        return {lh.first&&rh.first&&abs(lh.second-rh.second)<=1, 1+ max(lh.second,rh.second)};
    }
    bool isBalanced(TreeNode* root) {
        return find(root).first;
    }
};