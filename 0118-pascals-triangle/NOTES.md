1. if num==1 return {1}
2. if num==2 return {{1},{1,1}}
3. Traverse the nested loop with the nums  and j=0 to nums
4. Push the edge element 1 and rest v[i-1][j-1]+v[i-1][j]
5. return vector
​