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
    int ans=-1;
    void check(TreeNode* root, int& k){
        if(!root){return ;}
        check(root->left,k);
        if(k==1){
            ans = root->val;
        }
        k--;
        check(root->right,k);
    }
    int kthSmallest(TreeNode* root, int k) {
        check(root,k);
        return ans;
    }
};