class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        
        int n = grid.size();
        int m = grid[0].size();
        int** visited=new int*[n];
        for(int i=0;i<n;i++){
            int* arr=new int[m];
            for(int j=0;j<m;j++){
                arr[j]=0;
            }
            visited[i]=arr;
        }
        int count=0;
       
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]=='1' && visited[i][j]==0){
                    count++;
                     dfs(i,j,grid,visited,n,m);
                }
                    cout<<visited[i][j]<<" ";
                
            }
            cout<<endl;
        }
        return count;
    }
    void dfs(int i,int j,vector<vector<char>>& grid,int **visited,int n,int m){
        
            visited[i][j]=1;
            
            // 1 -right
            if(j<m-1 && visited[i][j+1]==0 && grid[i][j+1]=='1'){
                dfs(i,j+1,grid,visited,n,m);
            }
        
            // 2 -left
            if( j>0 && visited[i][j-1]==0 && grid[i][j-1]=='1'){
                dfs(i,j-1,grid,visited,n,m);
            }
        
            // 3 -up
            if(  i>0 && visited[i-1][j]==0 && grid[i-1][j]=='1'){
                dfs(i-1,j,grid,visited,n,m);
            }
            // 4 -down
            if(i<n-1 && visited[i+1][j]==0 && grid[i+1][j]=='1'){
                dfs(i+1,j,grid,visited,n,m);
            }
        /*
            // 5 up right
            if(i>0 &&  j<m-1 && visited[i-1][j+1]==0  && grid[i-1][j+1]=='1'){
                dfs(i-1,j+1,grid,visited,n,m);
            }
            // 6 up left
            if(i>0  && j>0 && visited[i-1][j-1]==0 && grid[i-1][j-1]=='1'){
                dfs(i-1,j-1,grid,visited,n,m);
            }
            // 7 down right
            if(i<n-1 && j<m-1 && visited[i+1][j+1]==0 && grid[i+1][j+1]=='1'){
                dfs(i+1,j+1,grid,visited,n,m);
            }
            // 8 down left
            if(i<n-1 && j>0 && visited[i+1][j-1]==0 && grid[i+1][j-1]=='1'){
                dfs(i+1,j-1,grid,visited,n,m);
            }
        */
            
         
    }
    
};