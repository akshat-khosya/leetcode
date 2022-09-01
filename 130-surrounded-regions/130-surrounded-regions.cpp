class Solution {
public:
    void solve(vector<vector<char>>& board) {
        int n=board.size();
        int m=board[0].size();
        
        queue<pair<int,int>> q;
        int** visited=new int*[n];
        for(int i=0;i<n;i++){
            int* arr=new int[m];
            for(int j=0;j<m;j++){
                arr[j]=0;
            }
            visited[i]=arr;
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if((i==0 ||j==0 || i==n-1 || j==m-1) && board[i][j]=='O'){
                    q.push({i,j});
                    visited[i][j]=1;
                }
            }
        }
        while(!q.empty()){
            pair<int,int> p=q.front();
            q.pop();
            cout<<p.first<<" "<<p.second<<endl;
            dfs(p.first,p.second,n,m,visited,board);
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(board[i][j]=='O' && visited[i][j]==0){
                    board[i][j]='X';
                }
            }
        }
        
    }
    void dfs(int i,int j,int n,int m,int** visited,vector<vector<char>>& board){
       visited[i][j]=1;
        // left
        if(j>0 && board[i][j-1]=='O' && visited[i][j-1]==0 ){
            dfs(i,j-1,n,m,visited,board);
        }
        // right
        if(j<m-1 && board[i][j+1]=='O' && visited[i][j+1]==0 ){
            dfs(i,j+1,n,m,visited,board);
        }
        // up
        if(i>0 && board[i-1][j]=='O' && visited[i-1][j]==0 ){
            dfs(i-1,j,n,m,visited,board);
        }
        // down
        if(i<n-1 && board[i+1][j]=='O' && visited[i+1][j]==0 ){
            
            dfs(i+1,j,n,m,visited,board);
        }
        
    }
};