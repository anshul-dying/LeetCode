class Solution 
{
public:
    int maxArea(vector<int>& height) 
    {
        // vector<int> ans;
        // int n = height.size();
        // for(int i = 0; i < n; i++)
        // {
        //     for(int j = i; j < n; j++)
        //     {
        //         int area = min(height[i], height[j]) * (j-i);
        //         ans.push_back(area);
        //     }
        // }

        // int res = *max_element(ans.begin(), ans.end());

        // return res;

        // int left = 0; int right = height.size()-1;
        // int maxArea = 0;

        // while(left < right)
        // {
        //     int area = min(height[left], height[right]) * (right-left);
        //     maxArea = max(maxArea, area);

        //     if(height[left] > height[right])
        //         right--;
        //     else
        //         left++;
        // }

        // return maxArea;
        int left = 0; int right = height.size()-1;
        int maxArea = INT_MIN;
        while(left < right)
        {
            int area = min(height[right], height[left]) * (right-left);

            maxArea = max(area, maxArea);
            if(height[left] > height[right])
                right--;
            else
                left++;
        }

        return maxArea;
    }
};