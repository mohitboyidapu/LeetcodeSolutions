/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
private:
    
    void inorder(TreeNode* root, TreeNode* cloned, TreeNode* target, TreeNode* &ans){
        if(root == NULL ){
            return;
        }
        
        if(root->val == target->val) {
            ans = cloned;
            
            return;
        }
        inorder(root->left, cloned->left, target, ans);
        inorder(root->right, cloned->right, target, ans);

    }
public:
    TreeNode* getTargetCopy(TreeNode* original, TreeNode* cloned, TreeNode* target) {
        TreeNode* ans = NULL;
        inorder(original, cloned, target, ans);
        return ans;
    }
};