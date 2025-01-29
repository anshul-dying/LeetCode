class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) 
    {
        string common = strs[0];
        for(int i = 0; i < strs.size(); i++)
        {
            int j = 0;
            while(j < common.length() && j < strs[i].length() && strs[i][j] == common[j])
                j++;
            
            common = common.substr(0,j);
        }

        return common;
    }
};