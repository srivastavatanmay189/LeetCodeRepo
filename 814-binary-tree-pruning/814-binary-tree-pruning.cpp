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
//     pair<TreeNode*, bool> find(TreeNode* root){
//         if(!root)return {NULL,false};
        
//         pair<TreeNode*, bool> l1 = find(root->left);
//         pair<TreeNode*, bool> r1 = find(root->right);
        
//         root->left = l1.first;
//         root->right = r1.first;
        
//         if(!l1.second && !r1.second && root->val != 1){
//             return {NULL, true};
//         }else{
//             return {root, true};
//         }
//     }
    TreeNode* find(TreeNode* root){
        if(!root)return root;
        
       TreeNode* l1 = find(root->left);
       TreeNode* r1 = find(root->right);
       
       root->left = l1;
       root->right = r1;
        
       if(!l1 && !r1) return root->val == 1 ? root : NULL;
       return root;
    }
    TreeNode* pruneTree(TreeNode* root) {
        return find(root);
    }
};