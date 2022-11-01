class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        if(numRows==1){
            return {{1}};
        }
        if(numRows==2){
            return {{1},{1,1}};
        }
        vector<vector<int>> v;
        v.push_back({1});
        v.push_back({1,1});
        for(int i=2;i<numRows;i++){
            vector<int> temp;
            for(int j=0;j<i+1;j++){
                if(j==0 || j==i){
                     temp.push_back(1);
                }else{
                     temp.push_back(v[i-1][j-1]+v[i-1][j]);
                }
               
            }
            v.push_back(temp);
        }
        return v;
    }
};