class Solution {
public:
    bool isPowerOfFour(int n) {
        if (n <= 0) return false;
        
       int x= log10(n)/log10(4);
     if(n == pow(4,x))
       {
           return 1;
         }
    
        return 0;
    }
        
    
};