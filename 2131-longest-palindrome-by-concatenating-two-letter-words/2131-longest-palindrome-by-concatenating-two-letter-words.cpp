class Solution {
public:
    int longestPalindrome(vector<string>& words) {
        int n = words.size();
        vector<vector<int>> counter(26,vector<int>(26,0));
        int ans=0;
        for(string s:words){
            int a = s[0]-'a'; 
            int b = s[1]-'a'; 
           
            if(counter[b][a]) {
                ans+=4;
                counter[b][a]--; 
            }
            else counter[a][b]++; 
        }
       
        for(int i=0;i<26;i++){
            if(counter[i][i]){ 
                ans+=2;
                break;
            }
        }
        return ans;
    }
};