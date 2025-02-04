class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) 
    {
        vector<int> ans(2,-1);
        int s = 0;
        int e = nums.size()-1;
        int mid = s+(e-s)/2;

        while(s <= e)//first occurance
        {
            if(nums[mid] == target)
            {
                ans[0] = mid;
                e = mid-1;
            }
            else if(target > nums[mid])
            {
                s = mid+1;
            }
            else
            {
                e = mid-1;
            }
            
            mid = s+(e-s)/2;
        } 

        s = 0, e = nums.size()-1;
        mid = s+(e-s)/2;
        while(s<=e)//second occurance
        {
            if(nums[mid] == target)
            {
                ans[1] = mid;
                s = mid+1;
            }
            else if(target > nums[mid])
            {
                s = mid+1;
            }
            else
            {
                e = mid-1;
            }
            
            mid = s+(e-s)/2;
        }

        return ans;
    }
};