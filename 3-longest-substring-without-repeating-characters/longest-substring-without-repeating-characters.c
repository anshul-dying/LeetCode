int lengthOfLongestSubstring(char* s) 
{
    int n = strlen(s);
    int max_len = 0;
    int cnt[256] = {0};
    for(int i = 0; i < n; i++)
    {
        int len = 0;
        memset(cnt, 0, sizeof(cnt));
        for(int j = i; j < n; j++)
        {
            if(cnt[s[j]] == 0)
            {
                cnt[s[j]]++;
                len++;
            }
            else break;
        }
        if(len > max_len) max_len = len;
    }
    return max_len;
}