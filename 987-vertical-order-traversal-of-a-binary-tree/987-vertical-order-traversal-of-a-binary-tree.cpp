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
    unordered_map<int,vector<pair<int,int>>> m;
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        if(root==NULL){
            return {};
        }
        vector<vector<int>> v(m.size());
        vector<pair<int,vector<pair<int,int>>>> st;
        dfs(0,0,root);
        for(auto i: m){
            
            st.push_back({i.first,i.second});
        }
        sort(st.begin(),st.end());
        for(auto a:st){
            sort(a.second.begin(),a.second.end());
            vector<int> temp;
            for(auto b:a.second){
                temp.push_back(b.second);
            }
            v.push_back(temp);
        }
        return v;
    }
    void dfs(int x,int y,TreeNode* node){
        
        m[y].push_back({x,node->val});
        if(node->left!=NULL){
            dfs(x+1,y-1,node->left);
        }
       
        if(node->right!=NULL){
            dfs(x+1,y+1,node->right);
        }
    }
};