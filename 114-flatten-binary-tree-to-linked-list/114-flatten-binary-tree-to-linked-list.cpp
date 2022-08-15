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
    TreeNode* flat(TreeNode* root){
//         if(!root->left && !root->right)return root;
        
        
//         TreeNode* last1 = NULL;
//         TreeNode* last2 = NULL;
        
//         if(root->left)last1 = flat(root->left);
//         if(root->right)last2 = flat(root->right);
        
//         if(last1){
//             last1 ->right  = root->right;
//             root->right = root->left;
//         }else{
//             return last2;
//         }
//         root->left = NULL;
        
//         return !last2?last1:last2;
        
        if(!root)return root;
        
        TreeNode* last1 = flat(root->left);
        TreeNode* last2 = flat(root->right);
        
        if(!last1 && !last2){
            return root;
        }else if(last2 && last1){
            
           last1 ->right  = root->right;
           root->right = root->left;
           root->left = NULL;
           return last2;
            
        }else if(!last1){
            return last2;
        }else{
            root->right = root->left;
            root->left = NULL;
            return last1;
        }
    }
    void flatten(TreeNode* root) {
        flat(root);
    }
};