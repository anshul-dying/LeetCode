class Solution {
private: 
    int searchPivot(vector<int> nums)
    {
        int s = 0;
        int e = nums.size()-1;
        int mid = s + (e-s)/2;
        while(s<e)
        {
            if(nums[mid] > nums[e])
                s=mid+1;
            else
                e = mid;

            mid = s + (e-s)/2;
        }

        return s;
    }
public:
    int search(vector<int>& nums, int target) 
    {
        int pivot = searchPivot(nums);
        int s = 0;
        int e = nums.size()-1;
        int mid = s + (e-s)/2;

        while(s<=e)
        {
            if(nums[mid] == target) return mid;
            
            if(nums[s] <= nums[mid])
            {//left part
                if(nums[s] <= target && nums[mid] > target)
                    e = mid-1;
                else
                    s = mid+1;
            }
            else
            {//right part
                if(nums[mid] < target && nums[e] >= target)
                    s = mid+1;
                else
                    e = mid-1;
            }

            mid = s + (e-s)/2;
        }
        
        return -1;
    }
};