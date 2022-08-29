/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    Node* cloneGraph(Node* node) {
        if(node==NULL) return NULL;
        int arr[101]={0};
        unordered_map<int,Node*> m;
        vector<int> adj[101];
        queue<Node*> q;
        q.push(node);
        
        
        while(!q.empty()){
            Node* temp=q.front();
            q.pop();
            arr[temp->val]=1;
           
            Node* clone=new Node(temp->val);
            m[temp->val]=clone;
            
            for(auto it:temp->neighbors){
                adj[temp->val].push_back(it->val);
                if(arr[it->val]==0){
                    arr[it->val]=1;
                    q.push(it);
                }
                
            }
            
        }
        for(int i=0;i<5;i++){
            for(int j=0;j<adj[i].size();j++){
                cout<<i<<" "<<adj[i][j]<<endl;
            }
        }
        for(auto it:m){
            for(int j=0;j<adj[it.first].size();j++){
                it.second->neighbors.push_back(m[adj[it.first][j]]);
            }
            // cout<<it.first<<" "<<it.second->val<<endl;
        }
        
        
        return m[node->val];
    }
};