class Solution {
public:
    int myAtoi(string s) 
    {
        int n = s.length();
        long long res = 0;
        int sign = 1;
        int i = 0;
        while(s[i] == ' ' && i < n)
        {
            i++;
        }    

        if(i < n && (s[i] == '+' || s[i] == '-'))
        {
            sign = s[i] == '+' ? 1 : -1;
            i++;
        }

        while(i < n && isdigit(s[i]))
        {
            res = res*10 + (s[i]-'0');
            i++;
            if(res > INT_MAX)
            {
                return sign == 1 ? INT_MAX : INT_MIN;
            }
        }

        return res*sign;
    }
};