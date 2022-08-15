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
    unordered_map<int,int>um;
    TreeNode* find(vector<int>& pre, vector<int>& in, int sp, int ep, int si, int ei){
        
        if(sp>ep)return NULL;
        
        int ri = um[pre[sp]];
        
        TreeNode* root = new TreeNode(pre[sp]);
        root->left = find(pre, in, sp+1, sp+ri-si, si, ri-1);
        root->right = find(pre, in, sp+ri-si+1, ep, ri+1, ei);
        
        return root;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int n = preorder.size();
        
        for(int i = 0; i<inorder.size(); i++)
            um[inorder[i]] = i;
        return find(preorder, inorder, 0, n-1, 0, n-1);
    }
};