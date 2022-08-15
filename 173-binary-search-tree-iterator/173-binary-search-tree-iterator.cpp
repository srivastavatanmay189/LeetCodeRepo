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
class BSTIterator {
public:
    
    stack<TreeNode*>it;
    BSTIterator(TreeNode* root) {
        while(root){
            it.push(root);
            root = root->left;
        }
    }
    
    int next() {
        TreeNode* temp = it.top();
        int ans = temp->val;
        it.pop();
        temp = temp->right;
        
        while(temp){
            it.push(temp);
            temp = temp->left; 
        }
        return ans;
    }
    
    bool hasNext() {
        return !it.empty();
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */