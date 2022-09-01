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
    int count=0;
    int goodNodes(TreeNode* root) {
        if(root==NULL){
            return count;
        }
        count++;
        int maxl=root->val;
        int maxr=root->val;
        dfs(root->left,maxl);
        dfs(root->right,maxr);
        return count;
    }
    void dfs(TreeNode* root,int max ){
        if(root==NULL){
            return ;
        }
        if(root->val>=max){
            count++;
            max=root->val;
        }
        dfs(root->left,max);
        dfs(root->right,max);
    }
    
};