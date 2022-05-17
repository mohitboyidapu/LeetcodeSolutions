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
public:
    TreeNode* getTargetCopy(TreeNode* original, TreeNode* cloned, TreeNode* target) {
        
        stack<TreeNode*> s;
        stack<TreeNode*> sdup;

        TreeNode* curr = original;
        TreeNode* dup = cloned;


        while(true){
            if(curr != NULL){
                s.push(curr);
                sdup.push(dup);

                curr = curr->left;
                dup = dup->left;
            }
            else{
                if(s.empty()) break;
                
                curr = s.top();
                dup = sdup.top();
                s.pop();
                sdup.pop();

                if(curr == target) return dup;

                curr = curr->right;
                dup = dup->right;

            }
        }
        return NULL;
    }
};