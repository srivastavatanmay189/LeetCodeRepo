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
    int ans=0;
    void count(TreeNode* root,int prev){
        if(root==NULL) return;
        if(root->val>=prev){
            ans++;
            prev=root->val;
        }
        count(root->left,prev);
        count(root->right,prev);
    }
    int goodNodes(TreeNode* root) {
        count(root,root->val);
        return ans;
    }
};