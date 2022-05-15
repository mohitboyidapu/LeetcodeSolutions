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
    int deepestLeavesSum(TreeNode* root) {

        int deep = 0;
        
        if(root == NULL) return deep;
        
        queue<TreeNode*> q;
        q.push(root);
        deep = root->val;
        
        while(!q.empty()){
            int level = 0;
            int size = q.size();  //for number of elements in same level
            
            for(int i=0; i<size; i++){ //iterating through elemets of smae level
                TreeNode* node = q.front();
                q.pop();
                level += node->val;
                if(node->left != NULL) q.push(node->left);
                if(node->right != NULL) q.push(node->right);
            }
            deep = level;
        }
        return deep;
    }
};