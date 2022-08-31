class Solution {
public:
    
    int orangesRotting(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        queue<pair<int,int>> q;
        int time=0;
        int** visited = new int*[n];
        for(int i=0;i<n;i++){
            int*arr=new int[m];
            for(int j=0;j<m;j++){
                arr[j]=0;
            }
            visited[i]=arr;
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==2){
                    q.push({i,j});
                    visited[i][j]=1;
                }
            }
        }
        while(!q.empty()){
            int s=q.size();
            time++;
            for(int i=0;i<s;i++){
                pair<int,int> p=q.front();
                visited[p.first][p.second]=1;
                q.pop();
                // left
                if(p.second>0 && grid[p.first][p.second-1]==1 && visited[p.first][p.second-1]==0){
                    visited[p.first][p.second-1]=1;
                    grid[p.first][p.second-1]=2;
                    q.push({p.first,p.second-1});
                    
                }
                // right
                if(p.second<m-1 && grid[p.first][p.second+1]==1 && visited[p.first][p.second+1]==0){
                    visited[p.first][p.second+1]=1;
                    grid[p.first][p.second+1]=2;
                    q.push({p.first,p.second+1});
                }
                // up
                if(p.first>0 && grid[p.first-1][p.second]==1 && visited[p.first-1][p.second]==0){
                    visited[p.first-1][p.second]=1;
                    grid[p.first-1][p.second]=2;
                    q.push({p.first-1,p.second});
                }
                // down
                if(p.first<n-1 && grid[p.first+1][p.second]==1 && visited[p.first+1][p.second]==0){
                    visited[p.first+1][p.second]=1;
                    grid[p.first+1][p.second]=2;
                    q.push({p.first+1,p.second});
                }
            }
        }
        //bfs(n,m,grid,visited);
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1){
                    return -1;
                }
            }
        }
        return time==0?0:time-1;
        
        
    }
    /*
    void bfs(int n,int m,vector<vector<int>>& grid,int** visited){
        int s=q.size();
        
    }
    */
};