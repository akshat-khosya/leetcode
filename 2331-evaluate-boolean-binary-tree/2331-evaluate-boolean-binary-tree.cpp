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
    bool evaluateTree(TreeNode* root) {
        if(!root->left && !root->right)
            return root->val;
        int leftVal = evaluateTree(root->left);
        int rightVal = evaluateTree(root->right);
        if(root->val == 2) {
            root->val = leftVal or rightVal;
        }
        else {
            root->val = leftVal and rightVal;
        }
        return root->val;
    }
};