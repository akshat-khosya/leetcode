class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        unordered_map<char,int> m;
        for(int i=0;i<ransomNote.length();i++){
            m[ransomNote[i]]++;
        }
        for(int i=0;i<magazine.length();i++){
            if(m[magazine[i]]>0){
                 m[magazine[i]]--;
            }
        }
        for(auto a:m){
            if(a.second!=0){
                cout<<a.second<<endl;
                return false;
            }
        }
        return true;
    }
};