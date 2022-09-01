class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        
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
                if(grid[i][j]==1 && visited[i][j]==0){
                    
                     int val=dfs(i,j,grid,visited,n,m);
                    count=max(count,val);
                }
                    
                
            }
            
        }
        return count;
    }
     int dfs(int i,int j,vector<vector<int>>& grid,int **visited,int n,int m){
        
            visited[i][j]=1;
            int a=0,b=0,c=0,d=0;
            // 1 -right
            if(j<m-1 && visited[i][j+1]==0 && grid[i][j+1]==1){
                a=dfs(i,j+1,grid,visited,n,m);
            }
        
            // 2 -left
            if( j>0 && visited[i][j-1]==0 && grid[i][j-1]==1){
                b=dfs(i,j-1,grid,visited,n,m);
            }
        
            // 3 -up
            if(  i>0 && visited[i-1][j]==0 && grid[i-1][j]==1){
                c=dfs(i-1,j,grid,visited,n,m);
            }
            // 4 -down
            if(i<n-1 && visited[i+1][j]==0 && grid[i+1][j]==1){
               d= dfs(i+1,j,grid,visited,n,m);
            }
       
            
         return 1 + a + b +c +d;
    }
};