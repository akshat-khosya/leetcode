class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int y = matrix.size();
        int x = matrix[0].size();
        vector<bool> h(x,false);
        vector<bool> v(y,false);
        vector<vector<int>> m = matrix;
        for(int i=0;i<y;i++){
            for(int j=0;j<x;j++){
                if(matrix[i][j]==0){
                    if(v[i]!=true){
                        v[i]=true;
                        makeZero(m,y,x,i,j,true);
                    }
                    if(h[j]!=true){
                        h[j]=true;
                        makeZero(m,y,x,i,j,false);
                    }
                }
            }
        }
        matrix=m;
        
    }
    void makeZero(vector<vector<int>>& matrix,int y,int x,int i,int j,bool c){
        if(c){
            for(int a=0;a<x;a++){
                matrix[i][a]=0;
            }
            return ;
        }else{
            for(int a=0;a<y;a++){
                matrix[a][j]=0;
            }
            return ;
        }
    }
};