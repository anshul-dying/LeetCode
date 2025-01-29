class Solution {
public:
    bool isPalindrome(int x) 
    {
        if(x < 0)
            return false;
        int temp = x;
        long long int xr = 0;
        while(x!=0)
        {
            int r = x%10;
            x /= 10;
            xr = xr*10 + r;
        }    

        if(xr == temp)
            return true;
        
        return false;
    }
};