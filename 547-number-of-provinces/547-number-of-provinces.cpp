class Solution {
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n=isConnected.size();
        vector<int> visited(n,0);
        int count=0;
        for(int i=0;i<n;i++){
            if(visited[i]==0){
                count++;
                queue<int> q;
                q.push(i);
                while(!q.empty()){
                    int node=q.front();
                    q.pop();
                    visited[node]=1;
                    for(int j=0;j<n;j++){
                        if(isConnected[node][j]==1){
                            if(visited[j]==0){
                                q.push(j);
                            }
                        }
                    }
                }
            }
        }
        return count;
    }
};