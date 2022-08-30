class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int n=image.size();
        int m=image[0].size();
        int **visited=new int*[n];
        for(int i=0;i<n;i++){
            int* arr=new int[m];
            for(int j=0;j<m;j++){
                arr[j]=0;
            }
            visited[i]=arr;
        }
        dfs(sr,sc,n,m,image,visited,color);
        return image;
    }
    void dfs(int i,int j,int n,int m,vector<vector<int>>& image,int**visited,int color){
        int currentColor=image[i][j];
        image[i][j]=color;
        visited[i][j]=1;
        // right
        if(j<m-1 && image[i][j+1]==currentColor && visited[i][j+1]==0){
            dfs(i,j+1,n,m,image,visited,color);
        }
        // left
        if(j>0 && image[i][j-1]==currentColor && visited[i][j-1]==0){
            dfs(i,j-1,n,m,image,visited,color);
        }
        // up
        if(i>0 && image[i-1][j]==currentColor && visited[i-1][j]==0){
            dfs(i-1,j,n,m,image,visited,color);
        }
        // down
        if(i<n-1 && image[i+1][j]==currentColor && visited[i+1][j]==0){
            dfs(i+1,j,n,m,image,visited,color);
        }
    }
};