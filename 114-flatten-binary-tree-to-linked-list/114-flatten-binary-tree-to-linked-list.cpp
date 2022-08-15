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
    // TreeNode* head=NULL;
    // void flat(TreeNode* root){
    //     if(!root){return;}
    //     if(!head){
    //         head = root;
    //     }else{
    //         head->right = root;
    //         head = head->right;
    //     }
    //     TreeNode* temp = root->right;
    //     flat(root->left);
    //     root->left = NULL;
    //     flat(temp);
    // }
    TreeNode* flat(TreeNode* root){
        if(!root || (!root->left && !root->right)){return root;}
        
        TreeNode* last1 = flat(root->left);
        TreeNode* last2 = flat(root->right);
        
        if(!last1){
            return last2;
        }else if(!last2){
            root->right = root->left;
            root->left = NULL;
            return last1;
        }else{
            last1 -> right = root->right;
            root->right = root->left;
            root->left = NULL;
            return last2;
        }
    }
    void flatten(TreeNode* root) {
        flat(root);
        return;
    }
};